/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_map_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:33:44 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/01 20:01:47 by adaloui          ###   ########.fr       */
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

t_map_info	*get_all_map_info(t_data *data)
{
	data->map_info = get_textures(data->map->map, data->map_info);
	data->map_info = get_colors_cf(data->map->map, data->map_info);
	data->map->player.p_dir = get_player_dir(data);
	data->map->player.p_pos = get_player_pos(data);
	init_player(data, data->map->player.p_pos.x, data->map->player.p_pos.y,
		data->map->player.p_dir);
	return (data->map_info);
}
