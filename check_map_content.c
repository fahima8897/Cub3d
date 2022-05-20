/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:08:18 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/20 16:29:56 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
				return (return_failure("Error\nWrong character."));
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_player_nb(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_2[i])
	{
		j = 0;
		while (map->map_2[i][j])
		{
			if (map->map_2[i][j] == 'N' || map->map_2[i][j] == 'E'
				|| map->map_2[i][j] == 'S' || map->map_2[i][j] == 'W')
				map->player++;
			j++;
		}
		i++;
	}
	if (map->player != 1)
		return (return_failure("Error\nWrong number of player."));
	return (SUCCESS);
}

int	ft_strlen_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	check_walls_top_bottom(char **map)
{
	int	j;
	int	size;

	size = ft_strlen_tab(map) - 1;
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1' && map[0][j] != '\n' && map[0][j] != ' ')
			return (return_failure("Error\nThere's hole on the top."));
		j++;
	}
	j = 0;
	while (map[size][j])
	{
		if (map[size][j] != '1' && map[size][j] != '\n' && map[size][j] != ' ')
			return (return_failure("Error\nThere's hole ont the bottom."));
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
				if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
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
		// printf("i : %d\n", i);
		size = ft_strlen(map[i]);
		if (map[i][size - 1] == '0')
			return (return_failure("Error\nThere is a hole on the right"));
		if (ft_strlen(map[i]) < ft_strlen(map[i + 1]))
			if (check_right_hole(map[i + 1], ft_strlen(map[i]) - 1) == FAILURE)
				return (return_failure("Error\nThere is a hole on the right"));
		if (ft_strlen(map[i]) > ft_strlen(map[i + 1]))
			if (check_right_hole(map[i], ft_strlen(map[i + 1]) - 1) == FAILURE)
				return (return_failure("Error\nThere is a hole on the right"));
		i++;
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

int	check_map_content_characters(t_data *data)
{
	/*Rajouter la conditions pour E W S N lorsqu'ils ont des espaces autour */
	/* Considerer les espaces entourant la map comme mauvais quand il y'a un joueur*/
	/* cas de figure [][][][][]1\0 lorsqu'il est avant la ligne d'au dessus*/
	/* cas de figure ou E est en dehors de la map ex : 1010000000000001     E*/
	if (check_walls_top_bottom(data->map->map_2) == FAILURE)
		return (FAILURE);
	if (check_walls_left(data->map->map_2) == FAILURE)
		return (return_failure("Error\nThere is a hole on the left"));
	if (check_walls_right(data->map->map_2) == FAILURE)
		return (FAILURE);
	if (check_hole_inside_map(data->map->map_2) == FAILURE)
		return (return_failure("Error\nThere's a hole inside the map."));
	if (check_player_nb(data->map) == FAILURE)
		return (FAILURE);
	if (check_forbidden_character(data->map->map_2) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
