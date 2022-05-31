/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:19:21 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/31 19:03:34 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	look_right(t_data *data)
{
	double		old_dirx;
	double		old_planex;

	old_dirx = data->map->player.dir_pos.x;
	old_planex = data->map->player.plane_pos.x;
	data->map->player.dir_pos.x = data->map->player.dir_pos.x * cos(-0.04)
		- data->map->player.dir_pos.y * sin(-0.04);
	data->map->player.dir_pos.y = old_dirx * sin(-0.04)
		+ data->map->player.dir_pos.y * cos(-0.04);
	data->map->player.plane_pos.x = data->map->player.plane_pos.x * cos(0.04)
		- data->map->player.plane_pos.y * sin(-0.04);
	data->map->player.plane_pos.y = old_planex * sin(-0.04)
		+ data->map->player.plane_pos.y * cos(-0.04);
	return (SUCCESS);
}

int	look_left(t_data *data)
{
	double		old_dirx;
	double		old_planex;

	old_dirx = data->map->player.dir_pos.x;
	old_planex = data->map->player.plane_pos.x;
	data->map->player.dir_pos.x = data->map->player.dir_pos.x * cos(0.04)
		- data->map->player.dir_pos.y * sin(0.04);
	data->map->player.dir_pos.y = old_dirx * sin(0.04)
		+ data->map->player.dir_pos.y * cos(0.04);
	data->map->player.plane_pos.x = data->map->player.plane_pos.x * cos(0.04)
		- data->map->player.plane_pos.y * sin(0.04);
	data->map->player.plane_pos.y = old_planex * sin(0.04)
		+ data->map->player.plane_pos.y * cos(0.04);
	return (SUCCESS);
}
