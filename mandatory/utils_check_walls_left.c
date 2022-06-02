/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_walls_left.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:38:10 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/02 22:01:19 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_max_len(char **map)
{
	int	i;
	int	j;
	int	max;

	max = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (max < j)
			max = j;
		i++;
	}
	return (max);
}

char	*fill_with_x(char *s, int max_len)
{
	int		i;
	char	*s2;

	s2 = malloc(sizeof(char) * (max_len + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i <= max_len - 1)
	{
		s2[i] = 'X';
		i++;
	}
	s2[i] = '\0';
	i = 0;
	while (i <= max_len - 1)
	{
		if (s[i] && s[i] != ' ')
			s2[i] = s[i];
		else if (s[i] == ' ')
			s2[i] = 'X';
		else
			return (s2);
		i++;
	}
	return (s2);
}

char	**change_space_to_3(t_data *data)
{
	int		i;
	int		size_of_map;
	int		max_j;
	char	**mapx;

	i = -1;
	max_j = get_max_len(data->map->map_2);
	size_of_map = ft_strlen_tab(data->map->map_2);
	mapx = ft_calloc(size_of_map + 1, sizeof(char *));
	if (!mapx)
		return (NULL);
	while (++i < size_of_map)
		mapx[i] = fill_with_x(data->map->map_2[i], max_j);
	return (mapx);
}
