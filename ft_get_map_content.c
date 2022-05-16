/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:39:37 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/16 16:50:23 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_count_line(char *s)
{
	int		fd;
	int		count_line;
	char	*line;

	count_line = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
		printf("Error\nOpen map.ber failed\n");
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

void	ft_fill_map(int row, int column, int i, t_map *map)
{
	char	*line;

	line = get_next_line(map->fd);
	while (line != NULL)
	{
		map->map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!(map->map[row]))
			return (ft_free_tab(map->map));
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

t_map	*ft_create_map(char *av)
{
	t_map	*map;
	int	row;
	int	i;
	int	column;

	row = 0;
	i = 0;
	column = 0;
	map = malloc(sizeof(t_map) * 1);
//    if (map == NULL)
  //      return (NULL);
	map->count_line = ft_count_line(av);
	map->map = ft_calloc(map->count_line+ 1, sizeof(char *));
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
		ft_fill_map(row, column, i, map);
		close(map->fd);
	}
    return (map);
}