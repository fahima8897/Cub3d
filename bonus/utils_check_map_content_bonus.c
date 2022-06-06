/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_map_content_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:52:25 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/03 16:06:18 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check_forbidden_character(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'N' && map[i][j] != 'E'
				&& map[i][j] != 'S' && map[i][j] != 'W'
				&& map[i][j] != ' ' && map[i][j] != '\n')
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	reduce_check_player_inside_map(char **map, int i, int j)
{
	if (map[i][j - 1] == ' ' || map[i][j + 1] == ' '
		|| map[i - 1][j] == ' ' || map[i + 1][j] == ' '
		|| map[i - 1][j] == '\0' || map[i + 1][j] == '\0')
		return (FAILURE);
	else
		return (SUCCESS);
}

int	check_player_inside_map(char **map)
{
	int	i;
	int	j;
	int	size;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][++j])
		{
			size = ft_strlen(map[i]) - 1;
			if (map[i][0] == 'N' || map[i][0] == 'E' || map[i][0] == 'S'
				|| map[i][0] == 'W')
				return (FAILURE);
			if (map[i][size] == 'N' || map[i][size] == 'E'
				|| map[i][size] == 'S' || map[i][size] == 'W')
				return (FAILURE);
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S'
				|| map[i][j] == 'W')
				return (reduce_check_player_inside_map(map, i, j));
		}
	}
	return (SUCCESS);
}

int	check_player_nb(t_map *map)
{
	int	i;
	int	j;
	int	p_nb;

	i = -1;
	p_nb = 0;
	while (map->map_2[++i])
	{
		j = 0;
		while (map->map_2[i][j])
		{
			if (map->map_2[i][j] == 'N' || map->map_2[i][j] == 'E'
				|| map->map_2[i][j] == 'S' || map->map_2[i][j] == 'W')
				p_nb++;
			j++;
		}
	}
	if (p_nb != 1)
		return (FAILURE);
	if (p_nb == 1)
	{
		if (check_player_inside_map(map->map_2) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	check_hole_inside_map(char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				if (map[i][j + 1] == ' ')
					return (FAILURE);
			if (map[i][j] == ' ')
				if (map[i][j + 1] == '0')
					return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}