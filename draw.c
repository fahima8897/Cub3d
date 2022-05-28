/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:24:25 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/28 17:29:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rgb(t_data *data, int y, int x)
{
	if (data->tx.endian == 1)
	{
		data->tx.addr[(x * data->tx.bpp >> 3)
			+ y * data->tx.line] = data->map_info->f_red;
		data->tx.addr[(x * data->tx.bpp >> 3)
			+ 1 + y * data->tx.line] = data->map_info->f_green;
		data->tx.addr[(x * data->tx.bpp >> 3)
			+ 2 + y * data->tx.line] = data->map_info->f_blue;
	}
	else
	{
		data->tx.addr[(x * data->tx.bpp >> 3)
			+ y * data->tx.line] = data->map_info->c_blue;
		data->tx.addr[(x * data->tx.bpp >> 3)
			+ 1 + y * data->tx.line] = data->map_info->c_green;
		data->tx.addr[(x * data->tx.bpp >> 3)
			+ 2 + y * data->tx.line] = data->map_info->c_red;
	}
}

void	draw_wall(t_data *data, t_img *tex, int y, int x)
{
	data->tx.addr[(x * data->tx.bpp >> 3)
		+ y * data->tx.line]
		= tex->addr[(int)(data->ray.wall_x * tex->width) * (tex->bpp >> 3)
		+ (int)((y - data->ray.wall_start * 1.0) / data->ray.line_height
			* tex->height) *tex->line];
	data->tx.addr[(x * data->tx.bpp >> 3)
		+ 1 + y * data->tx.line]
		= tex->addr[(int)(data->ray.wall_x * tex->width) * (tex->bpp >> 3)
		+ 1 + (int)((y - data->ray.wall_start * 1.0)
			/ data->ray.line_height * tex->height) *tex->line];
	data->tx.addr[(x * data->tx.bpp >> 3)
		+ 2 + y * data->tx.line]
		= tex->addr[(int)(data->ray.wall_x * tex->width) * (tex->bpp >> 3)
		+ 2 + (int)((y - data->ray.wall_start * 1.0)
			/ data->ray.line_height * tex->height) *tex->line];
}

void	draw_tmp(t_data *data, int y, int x)
{
/*	if (data->ray.side == NO)
		draw_wall(data, &data->map_info->north, y, x);
	else if (data->ray.side == SO)
		draw_wall(data, &data->map_info->south, y, x);
	else if (data->ray.side == WE)
		draw_wall(data, &data->map_info->west, y, x);
	else if (data->ray.side == EA)
		draw_wall(data, &data->map_info->east, y, x);*/
	if (data->ray.side == NO)
		draw_wall(data, &data->north, y, x);
	else if (data->ray.side == SO)
		draw_wall(data, &data->south, y, x);
	else if (data->ray.side == WE)
		draw_wall(data, &data->west, y, x);
	else if (data->ray.side == EA)
		draw_wall(data, &data->east, y, x);
}

void	set_stop(t_data *data, int *start, int *end)
{
	if (data->ray.wall_start < 0)
		*start = 0;
	else
		*start = data->ray.wall_start;
	if (data->ray.wall_end >= data->win_height)
		*end = data->win_height - 1;
	else
		*end = data->ray.wall_end;
}

void	put_in_display(t_data *data, int x)
{
	int	y;
	int	start;
	int	end;

	y = 0;
	set_stop(data, &start, &end);
	while (y < start)
	{
		draw_rgb(data, y, x);
		y++;
	}
	while (y < end)
	{
		draw_tmp(data, y, x);
		y++;
	}
	while (y < data->win_height - 1)
	{
		draw_rgb(data, y, x);
		y++;
	}
}
