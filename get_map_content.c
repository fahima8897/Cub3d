/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:39:37 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/18 21:03:46 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_get_next_line(char *line)
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

t_map	*count_line(char *s, t_data *data)
{
	int		fd;
	int		count_line;
	char	*line;
	int		i;

	count_line = 0;
	i = 0;
	data->map->map = ft_calloc(6 + 1, sizeof(char *));
	if (!(data->map->map))
		return (NULL);
	fd = open(s, O_RDONLY);
	if (fd < 0)
		printf("Error\nOpen map.cub failed\n");
	else
	{
		line = get_next_line(fd);
		while (line != NULL && count_line < 6)
		{
			if (check_get_next_line(line) == SUCCESS)
			{
				count_line++;
				data->map->map[i] = ft_strdup(line);
				i++;
			}
			free(line);
			line = get_next_line(fd);
		}
		free(line);
		close(fd);
	}
	return (data->map);
}

/*
void	fill_map(int row, int column, int i, t_map *map)
{
	char	*line;

	line = get_next_line(map->fd);
	while (line != NULL)
	{
		map->map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!(map->map[row]))
			return (free_tab(map->map));
		while (line[i] != '\0')
		{
			map->map[row][column] = line[i];
			column++;
			i++;
		}
		map->map[row][column] = '\0';
		row++;
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(map->fd);
	}
	map->map[row] = NULL;
}

t_map	*create_map(char *av, t_data *data)
{
	int		row;
	int		i;
	int		column;

	row = 0;
	i = 0;
	column = 0;
	data->map->count_line = 0;
	data->map->count_line = count_line(av);
	data->map->map = ft_calloc(data->map->count_line + 1, sizeof(char *));
	if (!(data->map->map))
		return (NULL);
	data->map->fd = open(av, O_RDONLY);
	if (data->map->fd < 0)
	{
		printf("Error\nOpen failed\n");
		return (NULL);
	}
	else
	{
		fill_map(row, column, i, data->map);
		close(data->map->fd);
	}
	return (data->map);
}
*/