/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:09:26 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/06 18:36:43 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	put_image_on_screen(t_data *data)
{
	int	width;

	width = 0;
	while (width < data->win_width)
	{
		data->ray.hit = 0;
		data->ray.cam.x = 2 * width / (double)data->win_width - 1;
		data->ray.dir.x = data->map->player.dir_pos.x
			+ data->map->player.plane_pos.x * data->ray.cam.x;
		data->ray.dir.y = data->map->player.dir_pos.y
			+ data->map->player.plane_pos.y * data->ray.cam.x;
		data->ray.hit = 0;
		data->ray.mapx = (int)data->map->player.p_pos.x;
		data->ray.mapy = (int)data->map->player.p_pos.y;
		data->ray.delta_dist.x = fabs(1 / data->ray.dir.x);
		data->ray.delta_dist.y = fabs(1 / data->ray.dir.y);
		get_rays_distance(data);
		player_touch_walls(data);
		get_walls_dist(data);
		draw_on_screen(data, width);
		width++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->screen.img, 0, 0);
	return (1);
}
