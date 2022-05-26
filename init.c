/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:38:08 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/26 16:22:16 by adaloui          ###   ########.fr       */
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
	data->tx = malloc(sizeof(t_img));
	if (!data->tx)
		return ;
	data->ray = malloc(sizeof(t_ray));
	if (!data->ray)
		return ;
	data->map->map = NULL;
	data->map->map_2 = NULL;
	data->map->fd = 0;
	data->map->count_line = 0;
	data->map->space_in_map_2 = 0;
	data->map_info->no_texture = NULL;
	data->map_info->so_texture = NULL;
	data->map_info->we_texture = NULL;
	data->map_info->ea_texture = NULL;
	data->map_info->mlx_no = NULL;
	data->map_info->mlx_so = NULL;
	data->map_info->mlx_we = NULL;
	data->map_info->mlx_ea = NULL;
	data->map->player.p_pos.x = 0;
	data->map->player.p_pos.y = 0;

	data->ray->dir.x = 1;
	data->ray->dir.y = 1;
	data->ray->side = 0;
	data->ray->stepx = 0;
	data->ray->stepy = 0;
	data->ray->mapx = 1;
	data->ray->mapy = 1;
	data->ray->line_height = 0;

	data->tx->bpp = 0;
	data->tx->height = 0;
	data->tx->width = 0;
	data->tx->endian = 0;
	data->tx->line = 0;
	data->tx->status = 0;
	data->tx->img = NULL;
	data->tx->addr = NULL;
}
