/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_camera_mouse_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:54:26 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/01 11:54:42 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rot_left(t_data *data) //bonus
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
}

void	rot_right(t_data *data) //bonus
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
}

int	mouse_handler(int x, int y, t_data *data) //bonus
{
	if (x >= 0 && x < data->win_width && y >= 0 && y < data->win_height)
	{
		if (x > data->win_width / 2)
		{
			rot_right(data);
			mlx_mouse_move(data->mlx, data->mlx_win,
				data->win_width / 2, data->win_height / 2);
		}
		else if (x < data->win_width / 2)
		{
			rot_left(data);
			mlx_mouse_move(data->mlx, data->mlx_win,
				data->win_width / 2, data->win_height / 2);
		}
		else
			mlx_mouse_move(data->mlx, data->mlx_win,
				x, data->win_height / 2);
	}
	return (0);
}