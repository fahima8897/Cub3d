/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:09:26 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/28 16:16:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_dist(t_data *data)
{
	if (data->ray.side == WE || data->ray.side == EA)
		data->ray.wall_dist = (data->ray.mapx - data->map->player.p_pos.x
				+ (1 - data->ray.stepx) / 2) / data->ray.dir.x;
	else if (data->ray.side == NO || data->ray.side == SO)
		data->ray.wall_dist = (data->ray.mapy - data->map->player.p_pos.y
				+ (1 - data->ray.stepy) / 2) / data->ray.dir.y;
	data->ray.line_height = (int)(data->win_height / data->ray.wall_dist);
	data->ray.wall_start = -data->ray.line_height / 2 + data->win_height / 2;
	data->ray.wall_end = data->ray.line_height / 2 + data->win_height / 2;
	if (data->ray.side == 2 || data->ray.side == 3)
		data->ray.wall_x = data->map->player.p_pos.y + data->ray.wall_dist
			* data->ray.dir.y;
	else
		data->ray.wall_x = data->map->player.p_pos.x + data->ray.wall_dist
			* data->ray.dir.x;
	data->ray.wall_x -= floor(data->ray.wall_x);
}

void	loop_hit(t_data *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.side_dist.x < data->ray.side_dist.y)
		{
			data->ray.side_dist.x += data->ray.delta_dist.x;
			data->ray.mapx += data->ray.stepx;
			if (data->ray.dir.x > 0)
				data->ray.side = EA;
			else
				data->ray.side = WE;
		}
		else
		{
			data->ray.side_dist.y += data->ray.delta_dist.y;
			data->ray.mapy += data->ray.stepy;
			if (data->ray.dir.y > 0)
				data->ray.side = SO;
			else
				data->ray.side = NO;
			data->ray.side = 1;
		}
		if (data->map->map_2[data->ray.mapx][data->ray.mapy] == '1')
			data->ray.hit = 1;
	}
}

void	calcul_raydis(t_data *data)
{
	if (data->ray.dir.x < 0)
	{
		data->ray.stepx = -1;
		data->ray.side_dist.x = (data->map->player.p_pos.x - data->ray.mapx)
			* data->ray.delta_dist.x;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.side_dist.x
			= (data->ray.mapx + 1.0 - data->map->player.p_pos.x)
			* data->ray.delta_dist.x;
	}
	if (data->ray.dir.y < 0)
	{
		data->ray.stepy = -1;
		data->ray.side_dist.y = (data->map->player.p_pos.y - data->ray.mapy)
			* data->ray.delta_dist.y;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.side_dist.y
			= (data->ray.mapy + 1.0 - data->map->player.p_pos.y)
			* data->ray.delta_dist.y;
	}
}

int	draw(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->win_width)
	{
		data->ray.hit = 0;
		data->ray.cam.x = 2 * x / (double)data->win_width - 1;
		data->ray.dir.x = data->map->player.dir_pos.x
			+ data->map->player.plane_pos.x * data->ray.cam.x;
		data->ray.dir.y = data->map->player.dir_pos.y
			+ data->map->player.plane_pos.y * data->ray.cam.x;
		data->ray.hit = 0;
		data->ray.mapx = (int)data->map->player.p_pos.x;
		data->ray.mapy = (int)data->map->player.p_pos.y;
		data->ray.delta_dist.x = fabs(1 / data->ray.dir.x);
		data->ray.delta_dist.y = fabs(1 / data->ray.dir.y);
		calcul_raydis(data);
		loop_hit(data);
		wall_dist(data);
		put_in_display(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->tx.img, 0, 0);
	return (1);
}
