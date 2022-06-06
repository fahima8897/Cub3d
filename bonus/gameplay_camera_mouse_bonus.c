/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_camera_mouse_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:54:26 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/06 18:53:22 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	look_left_camera(t_data *data)
{
	double		previous_cam_x;
	double		previous_dir_x;

	previous_cam_x = data->map->player.plane_pos.x;
	previous_dir_x = data->map->player.dir_pos.x;
	data->map->player.dir_pos.x = data->map->player.dir_pos.x * cos(CAM_SPEED)
		- data->map->player.dir_pos.y * sin(CAM_SPEED);
	data->map->player.dir_pos.y = previous_dir_x * sin(CAM_SPEED)
		+ data->map->player.dir_pos.y * cos(CAM_SPEED);
	data->map->player.plane_pos.x = data->map->player.plane_pos.x
		* cos(CAM_SPEED)
		- data->map->player.plane_pos.y * sin(CAM_SPEED);
	data->map->player.plane_pos.y = previous_cam_x * sin(CAM_SPEED)
		+ data->map->player.plane_pos.y * cos(CAM_SPEED);
}

void	look_right_camera(t_data *data)
{
	double		previous_cam_x;
	double		previous_dir_x;

	previous_cam_x = data->map->player.plane_pos.x;
	previous_dir_x = data->map->player.dir_pos.x;
	data->map->player.dir_pos.x = data->map->player.dir_pos.x * cos(-CAM_SPEED)
		- data->map->player.dir_pos.y * sin(-CAM_SPEED);
	data->map->player.dir_pos.y = previous_dir_x * sin(-CAM_SPEED)
		+ data->map->player.dir_pos.y * cos(-CAM_SPEED);
	data->map->player.plane_pos.x = data->map->player.plane_pos.x
		* cos(CAM_SPEED)
		- data->map->player.plane_pos.y * sin(-CAM_SPEED);
	data->map->player.plane_pos.y = previous_cam_x * sin(-CAM_SPEED)
		+ data->map->player.plane_pos.y * cos(-CAM_SPEED);
}

int	mouse_handler(int x, int y, t_data *data)
{
	if (x >= 0 && x < data->win_width && y >= 0 && y < data->win_height)
	{
		if (x > data->win_width / 2)
		{
			look_right_camera(data);
			mlx_mouse_move(data->mlx, data->mlx_win,
				data->win_width / 2, data->win_height / 2);
		}
		else if (x < data->win_width / 2)
		{
			look_left_camera(data);
			mlx_mouse_move(data->mlx, data->mlx_win,
				data->win_width / 2, data->win_height / 2);
		}
		else
			mlx_mouse_move(data->mlx, data->mlx_win,
				x, data->win_height / 2);
	}
	return (SUCCESS);
}
