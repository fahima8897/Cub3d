/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_map_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:33:44 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/20 20:12:48 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map_info	*get_textures(char **map, t_map_info *map_info)
{
	int		i;
	char	**s_byspace;

	i = -1;
	while (map[++i] && i < 6)
	{
		s_byspace = ft_split(map[i], ' ');
		if (ft_strncmp(s_byspace[0], "NO", 3) == 0)
			map_info->no_texture = ft_strdup(s_byspace[1]);
		if (ft_strncmp(s_byspace[0], "SO", 3) == 0)
			map_info->so_texture = ft_strdup(s_byspace[1]);
		if (ft_strncmp(s_byspace[0], "EA", 3) == 0)
			map_info->ea_texture = ft_strdup(s_byspace[1]);
		if (ft_strncmp(s_byspace[0], "WE", 3) == 0)
			map_info->we_texture = ft_strdup(s_byspace[1]);
		free_tab(s_byspace);
	}
	return (map_info);
}

void	get_color_cd_reduce(char **s_byspace, t_map_info *map_info)
{
	char	**s_bycomma;

	if (ft_strncmp(s_byspace[0], "F", 2) == 0)
	{
		s_bycomma = ft_split(s_byspace[1], ',');
		map_info->f_red = ft_atoi(s_bycomma[0]);
		map_info->f_green = ft_atoi(s_bycomma[1]);
		map_info->f_blue = ft_atoi(s_bycomma[2]);
		free_tab(s_bycomma);
	}
	if (ft_strncmp(s_byspace[0], "C", 2) == 0)
	{
		s_bycomma = ft_split(s_byspace[1], ',');
		map_info->c_red = ft_atoi(s_bycomma[0]);
		map_info->c_green = ft_atoi(s_bycomma[1]);
		map_info->c_blue = ft_atoi(s_bycomma[2]);
		free_tab(s_bycomma);
	}
}

t_map_info	*get_colors_cf(char **map, t_map_info *map_info)
{
	int		i;
	char	**s_byspace;

	i = -1;
	while (map[++i] && i < 6)
	{
		s_byspace = ft_split(map[i], ' ');
		get_color_cd_reduce(s_byspace, map_info);
		free_tab(s_byspace);
	}
	return (map_info);
}

t_map_info	*get_all_map_info(t_data *data)
{
	t_map_info	*map_info;

	map_info = malloc(sizeof(t_map_info) * 1);
	if (map_info == NULL)
		return (NULL);
	map_info = get_textures(data->map->map, map_info);
	map_info = get_colors_cf(data->map->map, map_info);
	return (map_info);
}
