/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:38:08 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/28 16:14:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_img(t_img *image)
{
	image->bpp = 0;
	image->height = 0;
	image->width = 0;
	image->endian = 0;
	image->line = 0;
	image->status = 0;
	image->img = NULL;
	image->addr = NULL;
}

void	init_ray(t_ray *ray)
{
	ray->dir.x = 1;
	ray->dir.y = 1;
	ray->side = 0;
	ray->stepx = 0;
	ray->stepy = 0;
	ray->mapx = 1;
	ray->mapy = 1;
	ray->line_height = 0;
}

void	init_data(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return ;
	data->map_info = malloc(sizeof(t_map_info));
	if (!data->map_info)
		return ;
/*	data->tx = malloc(sizeof(t_img));
	if (!data->tx)
		return ;*/
/*	data->ray = malloc(sizeof(t_ray));
	if (!data->ray)
		return ;*/
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

	data->ray.dir.x = 1;
	data->ray.dir.y = 1;
	data->ray.side = 0;
	data->ray.stepx = 0;
	data->ray.stepy = 0;
	data->ray.mapx = 1;
	data->ray.mapy = 1;
	data->ray.line_height = 0;

	data->tx.bpp = 0;
	data->tx.height = 0;
	data->tx.width = 0;
	data->tx.endian = 0;
	data->tx.line = 0;
	data->tx.status = 0;
	data->tx.img = NULL;
	data->tx.addr = NULL;

	data->map_info->east.bpp = 0;
	data->map_info->east.height = 0;
	data->map_info->east.width = 0;
	data->map_info->east.endian = 0;
	data->map_info->east.line = 0;
	data->map_info->east.status = 0;
	data->map_info->east.img = NULL;
	data->map_info->east.addr = NULL;

	data->map_info->west.bpp = 0;
	data->map_info->west.height = 0;
	data->map_info->west.width = 0;
	data->map_info->west.endian = 0;
	data->map_info->west.line = 0;
	data->map_info->west.status = 0;
	data->map_info->west.img = NULL;
	data->map_info->west.addr = NULL;

	data->map_info->north.bpp = 0;
	data->map_info->north.height = 0;
	data->map_info->north.width = 0;
	data->map_info->north.endian = 0;
	data->map_info->north.line = 0;
	data->map_info->north.status = 0;
	data->map_info->north.img = NULL;
	data->map_info->north.addr = NULL;

	data->map_info->south.bpp = 0;
	data->map_info->south.height = 0;
	data->map_info->south.width = 0;
	data->map_info->south.endian = 0;
	data->map_info->south.line = 0;
	data->map_info->south.status = 0;
	data->map_info->south.img = NULL;
	data->map_info->south.addr = NULL;
}
