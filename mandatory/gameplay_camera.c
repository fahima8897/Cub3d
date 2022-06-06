/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:19:21 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/06 18:55:44 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	look_right(t_data *data)
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
	return (SUCCESS);
}

int	look_left(t_data *data)
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
	return (SUCCESS);
}
