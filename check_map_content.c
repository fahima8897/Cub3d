/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:08:18 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/19 15:53:23 by adaloui          ###   ########.fr       */
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

int	check_surrounded_by_walls_top_bottom(char **map)
{
	int	j;
	int	size;

	size = ft_strlen_tab(map) - 1;
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1' && map[0][j] != '\n' && map[0][j] != ' ')
			return (return_failure("Error\nWall error 1."));
		j++;
	}
	j = 0;
	while (map[size][j])
	{
		if (map[size][j] != '1' && map[size][j] != '\n' && map[size][j] != ' ')
			return (return_failure("Error\nWall error 1."));
		j++;
	}
	return (SUCCESS);
}

int	check_surrounded_by_walls_left_right(char **map)
{
	int	i;
	int	j;
	int	x_size;

	i = 1;
	while (map[i])
	{
		j = 0;
		x_size = ft_strlen(map[i]) - 1;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			j++;
		if (map[i][j] != '1')// rajouter map[i][j] != ' ' ? car espace == wall
			return (return_failure("Error\nWall error 2."));
		if (map[i][x_size] != '1') // meme chose
			return (return_failure("Error\nWall error 3."));
		i++;
	}
	return (SUCCESS);
}

int	check_map_content_characters(t_data *data)
{
	if (check_forbidden_character(data->map->map_2) == FAILURE)
		return (FAILURE);
	if (check_surrounded_by_walls_top_bottom(data->map->map_2) == FAILURE)
		return (FAILURE);
	if (check_surrounded_by_walls_left_right(data->map->map_2) == FAILURE)
		return (FAILURE);
	if (check_player_nb(data->map) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
