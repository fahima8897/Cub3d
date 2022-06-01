/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rest_of_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:46:20 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/29 14:00:25 by user42           ###   ########.fr       */
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

int	reduce_return_size_of_map(int fd)
{
	int		count_line;
	char	*line;
	int		i;

	count_line = 0;
	i = 0;
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
	return (i);
}

int	return_size_of_map(char *s)
{
	int		i;
	int		fd;

	i = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
		printf("Error\nOpen map.cub failed\n");
	else
		i = reduce_return_size_of_map(fd);
	return (i);
}

t_map	*reduce_cl_for_map(t_data *data, int fd, int cl)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (check_get_next_line2(line) == SUCCESS)
		{
			cl++;
			if (cl > 6)
			{
				data->map->map_2[i] = strdup_no_n(line);
				i++;
			}
		}
		else if (cl > 6 && i > 0)
			data->map->space_in_map_2 = 1;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (data->map);
}

t_map	*count_line_for_map(char *s, t_data *data)
{
	int		fd;
	int		count_line;
	int		map_size;

	count_line = 0;
	map_size = return_size_of_map(s);
	data->map->map_2 = ft_calloc(map_size + 1, sizeof(char *));
	if (!(data->map->map_2))
		return (NULL);
	fd = open(s, O_RDONLY);
	if (fd < 0)
		printf("Error\nOpen map.cub failed\n");
	else
		data->map = reduce_cl_for_map(data, fd, count_line);
	return (data->map);
}
