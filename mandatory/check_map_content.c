/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:08:18 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/02 22:44:09 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_walls_top_bottom(char **map)
{
	int	j;
	int	size;

	size = ft_strlen_tab(map) - 1;
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1' && map[0][j] != '\n' && map[0][j] != ' ')
			return (return_failure("Error\nError Parsing."));
		j++;
	}
	j = 0;
	while (map[size][j])
	{
		if (map[size][j] != '1' && map[size][j] != '\n' && map[size][j] != ' ')
			return (return_failure("Error\nError Parsing."));
		j++;
	}
	return (SUCCESS);
}

int	check_right_hole(char *s, int size)
{
	int	i;

	i = 0;
	if (!s)
		return (SUCCESS);
	while (i < size)
		i++;
	i++;
	while (s[i])
	{
		if (s[i] == '0')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_walls_left(char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i])
	{
		if (map[i][0] == '0')
			return (FAILURE);
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (map[i - 1][j] == 'X' || map[i + 1][j] == 'X')
					return (FAILURE);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_walls_right(char **map)
{
	int	i;
	int	size;

	i = 0;
	while (map[i])
	{
		size = ft_strlen(map[i]);
		if (map[i][size - 1] == '0')
			return (return_failure("Error\nError Parsing."));
		if (ft_strlen(map[i]) < ft_strlen(map[i + 1]))
			if (check_right_hole(map[i + 1], ft_strlen(map[i]) - 1) == FAILURE)
				return (return_failure("Error\nError Parsing."));
		if (ft_strlen(map[i]) > ft_strlen(map[i + 1]))
			if (check_right_hole(map[i], ft_strlen(map[i + 1]) - 1) == FAILURE)
				return (return_failure("Error\nError Parsing."));
		i++;
	}
	return (SUCCESS);
}

int	check_map_content_characters(t_data *data)
{
	char	**mapx;

	mapx = transform_sp_to_x(data);
	if (mapx == NULL)
		return (return_failure("Error\nmapx could not load."));
	if (check_walls_top_bottom(data->map->map_2) == FAILURE)
		return (ret_free("", mapx));
	if (check_walls_left(mapx) == FAILURE)
		return (ret_free("Error\nParsing popo", mapx));
	if (check_walls_right(data->map->map_2) == FAILURE)
		return (ret_free("", mapx));
	if (check_hole_inside_map(data->map->map_2) == FAILURE)
		return (ret_free("Error\nParsing lolo", mapx));
	if (check_player_nb(data->map) == FAILURE)
		return (ret_free("", mapx));
	if (check_forbidden_character(data->map->map_2) == FAILURE)
		return (ret_free("", mapx));
	free_tab(mapx);
	return (SUCCESS);
}
