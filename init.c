/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:38:08 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/21 09:23:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return ;
	data->map_info = malloc(sizeof(t_map_info));
	if (!data->map_info)
		return ;
	data->map->map = NULL;
	data->map->map_2 = NULL;
	data->map->fd = 0;
	data->map->count_line = 0;
	data->map->player = 0;
	data->map->space_in_map_2 = 0;
	data->map_info->no_texture = NULL;
	data->map_info->so_texture = NULL;
	data->map_info->we_texture = NULL;
	data->map_info->ea_texture = NULL;
	data->map_info->mlx_no = NULL;
	data->map_info->mlx_so = NULL;
	data->map_info->mlx_we = NULL;
	data->map_info->mlx_ea = NULL;
	
}
