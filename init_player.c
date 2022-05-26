/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:06:10 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/26 14:21:34 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_plane(t_data *data, double dx, double dy)
{
	data->map->player.plane_pos.x = dx;
	data->map->player.plane_pos.y = dy;
}

void	set_dir(t_data *data, double x, double y)
{
	data->map->player.dir_pos.x = x;
	data->map->player.dir_pos.y = y;
}

void	west_east(t_data *data, char dir)
{
	if (dir == 'E')
	{
		set_dir(data, 0, 1);
		set_plane(data, 0.66, 0);
	}
	else if (dir == 'W')
	{	
		set_dir(data, 0, -1);
		set_plane(data, -0.66, 0);
	}
}

void	init_player(t_data *data, int h, int w, char dir)
{
	(void)h;
	(void) w;
	if (dir == 'N')
	{
		set_dir(data, -1, 0);
		set_plane(data, 0, 0.66);
	}
	else if (dir == 'S')
	{
		set_dir(data, 1, 0);
		set_plane(data, 0, -0.66);
	}
	else if (dir == 'E' || dir == 'W')
		west_east(data, dir);
	data->map->player.p_pos.x = h + 0.5;
	data->map->player.p_pos.y = w + 0.5;
}
