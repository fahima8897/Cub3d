/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:46:41 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/06 23:04:52 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_rays_distance(t_data *data)
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
		data->ray.side_dist.x = (data->ray.mapx + 1.0
				- data->map->player.p_pos.x) * data->ray.delta_dist.x;
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

void	get_walls_dist(t_data *data)
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
	if (data->ray.side == WE || data->ray.side == EA)
		data->ray.wall_x = data->map->player.p_pos.y + data->ray.wall_dist
			* data->ray.dir.y;
	else if (data->ray.side == NO || data->ray.side == SO)
		data->ray.wall_x = data->map->player.p_pos.x + data->ray.wall_dist
			* data->ray.dir.x;
	data->ray.wall_x -= floor(data->ray.wall_x);
}

void	ray_touch_walls(t_data *data)
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
		}
		if (data->map->map_2[data->ray.mapx][data->ray.mapy] == '1')
			data->ray.hit = 1;
	}
}
