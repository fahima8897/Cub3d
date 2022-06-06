/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:38:08 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/06 17:05:55 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_img(t_data *data)
{
	data->screen.bpp = 0;
	data->screen.height = 0;
	data->screen.width = 0;
	data->screen.endian = 0;
	data->screen.line = 0;
	data->screen.status = 0;
	data->screen.img = NULL;
	data->screen.addr = NULL;
}

void	init_ray(t_data *data)
{
	data->ray.dir.x = 1;
	data->ray.dir.y = 1;
	data->ray.side = 0;
	data->ray.stepx = 0;
	data->ray.stepy = 0;
	data->ray.mapx = 1;
	data->ray.mapy = 1;
	data->ray.line_height = 0;
}

void	init_east_west(t_data *data)
{
	data->east.bpp = 0;
	data->east.height = 0;
	data->east.width = 0;
	data->east.endian = 0;
	data->east.line = 0;
	data->east.status = 0;
	data->east.img = NULL;
	data->east.addr = NULL;
	data->west.bpp = 0;
	data->west.height = 0;
	data->west.width = 0;
	data->west.endian = 0;
	data->west.line = 0;
	data->west.status = 0;
	data->west.img = NULL;
	data->west.addr = NULL;
}

void	init_south_north_and_player(t_data *data)
{
	data->north.bpp = 0;
	data->north.height = 0;
	data->north.width = 0;
	data->north.endian = 0;
	data->north.line = 0;
	data->north.status = 0;
	data->north.img = NULL;
	data->north.addr = NULL;
	data->south.bpp = 0;
	data->south.height = 0;
	data->south.width = 0;
	data->south.endian = 0;
	data->south.line = 0;
	data->south.status = 0;
	data->south.img = NULL;
	data->south.addr = NULL;
	data->map->player.gamplay.forward = 0;
	data->map->player.gamplay.backward = 0;
	data->map->player.gamplay.left = 0;
	data->map->player.gamplay.right = 0;
	data->map->player.gamplay.look_left = 0;
	data->map->player.gamplay.look_right = 0;
	data->map->player.gamplay.escape = 0;
}

void	init_data(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return ;
	data->map_info = malloc(sizeof(t_map_info));
	if (!data->map_info)
		return ;
	init_south_north_and_player(data);
	init_east_west(data);
	init_ray(data);
	init_img(data);
	data->map->map = NULL;
	data->map->map_2 = NULL;
	data->map->fd = 0;
	data->map->count_line = 0;
	data->map->space_in_map_2 = 0;
	data->map_info->no_texture = NULL;
	data->map_info->so_texture = NULL;
	data->map_info->we_texture = NULL;
	data->map_info->ea_texture = NULL;
	data->map->player.p_pos.x = 0;
	data->map->player.p_pos.y = 0;
	data->map->gap = 0;
	data->map->is_map = 0;
}
