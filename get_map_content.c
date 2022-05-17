/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:39:37 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/17 12:05:29 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_line(char *s)
{
	int		fd;
	int		count_line;
	char	*line;

	count_line = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
		printf("Error\nOpen map.cub failed\n");
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			count_line++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (count_line);
}

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

t_data	*create_map(char *av, t_data *data)
{
	int		row;
	int		i;
	int		column;

	row = 0;
	i = 0;
	column = 0;
	// map = malloc(sizeof(t_map) * 1);
//    if (map == NULL)
  //      return (NULL);
	data->map->count_line = count_line(av);
	data->->data-> = ft_calloc(map->count_line + 1, sizeof(char *));
	if (!(map->map))
		return (NULL);
	map->fd = open(av, O_RDONLY);
	if (map->fd < 0)
    {
		printf("Error\nOpen failed\n");
        return (NULL);
    }
	else
	{
		fill_map(row, column, i, map);
		close(map->fd);
	}
    return (map);
}
