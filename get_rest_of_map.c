/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rest_of_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:46:20 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/18 23:03:43 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_get_next_line2(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] > 32)
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}

int	return_size_of_map(char *s)
{
	int		count_line;
	int		i;
	int		fd;
	char	*line;

	i = 0;
	count_line = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
		printf("Error\nOpen map.cub failed\n");
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			if (check_get_next_line2(line) == SUCCESS)
			{
				count_line++;
				if (count_line > 6)
					i++;
			}
			free(line);
			line = get_next_line(fd);
		}
		free(line);
		close(fd);
	}
	printf("number of line after ressources == %d\n", i);
	return (i);
}

t_map *count_line_for_map(char *s, t_data *data)
{
    int		fd;
	int		count_line;
	char	*line;
	int		i;
	int		map_size;

	count_line = 0;
	i = 0;
	map_size = return_size_of_map(s);
	printf("map size == %d\n", map_size);
	data->map->map = ft_calloc(map_size + 1, sizeof(char *));
	if (!(data->map->map))
		return (NULL);
	fd = open(s, O_RDONLY);
	if (fd < 0)
		printf("Error\nOpen map.cub failed\n");
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			if (check_get_next_line2(line) == SUCCESS)
			{
				count_line++;
				if (count_line > 6)
				{
					data->map->map[i] = ft_strdup(line);
					i++;
				}
			}
			else if (count_line > 6 && i > 0)
			{
				data->map->space_in_map = 1;
				break ;
			}
			free(line);
			line = get_next_line(fd);
		}
		free(line);
		close(fd);
	}
	return (data->map);
}

