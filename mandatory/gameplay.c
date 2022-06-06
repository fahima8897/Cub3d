/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:30:43 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/06 18:55:20 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	forward(t_data *data)
{
	if (data->map->map_2[(int)(data->map->player.p_pos.x
			+ data->map->player.dir_pos.x * SPEED)]
		[(int)(data->map->player.p_pos.y)] == '0'
		|| data->map->map_2[(int)(data->map->player.p_pos.x +
	data->map->player.dir_pos.x * SPEED)][(int)(data->map->player.p_pos.y)]
	== data->map->player.p_dir)
		data->map->player.p_pos.x += data->map->player.dir_pos.x * SPEED;
	if (data->map->map_2[(int)(data->map->player.p_pos.x)]
	[(int)(data->map->player.p_pos.y + data->map->player.dir_pos.y * SPEED)]
	== '0' || data->map->map_2[(int)(data->map->player.p_pos.x)]
	[(int)(data->map->player.p_pos.y + data->map->player.dir_pos.y * SPEED)]
	== data->map->player.p_dir)
		data->map->player.p_pos.y += data->map->player.dir_pos.y * SPEED;
}

void	back(t_data *data)
{
	if (data->map->map_2[(int)(data->map->player.p_pos.x
			- data->map->player.dir_pos.x * SPEED)]
	[(int)(data->map->player.p_pos.y)]
	== '0' || data->map->map_2[(int)(data->map->player.p_pos.x
	- data->map->player.dir_pos.x * SPEED)][(int)(data->map->player.p_pos.y)]
	== data->map->player.p_dir)
		data->map->player.p_pos.x -= data->map->player.dir_pos.x * SPEED;
	if (data->map->map_2[(int)(data->map->player.p_pos.x)]
	[(int)(data->map->player.p_pos.y - data->map->player.dir_pos.y * SPEED)]
	== '0' || data->map->map_2[(int)(data->map->player.p_pos.x)]
	[(int)(data->map->player.p_pos.y - data->map->player.dir_pos.y * SPEED)]
	== data->map->player.p_dir)
		data->map->player.p_pos.y -= data->map->player.dir_pos.y * SPEED;
}

void	left(t_data *data)
{
	if (data->map->map_2[(int)(data->map->player.p_pos.x
			- data->map->player.plane_pos.x * SPEED)]
	[(int)(data->map->player.p_pos.y)] == '0'
	|| data->map->map_2[(int)(data->map->player.p_pos.x
	- data->map->player.plane_pos.x * SPEED)]
	[(int)(data->map->player.p_pos.y)] == data->map->player.p_dir)
		data->map->player.p_pos.x += -(data->map->player.plane_pos.x * SPEED);
	if (data->map->map_2[(int)(data->map->player.p_pos.x)]
	[(int)(data->map->player.p_pos.y - data->map->player.plane_pos.y * SPEED)]
	== '0' || data->map->map_2[(int)(data->map->player.p_pos.x)]
	[(int)(data->map->player.p_pos.y - data->map->player.plane_pos.y * SPEED)]
	== data->map->player.p_dir)
		data->map->player.p_pos.y += -(data->map->player.plane_pos.y * SPEED);
}

void	right(t_data *data)
{
	if (data->map->map_2[(int)(data->map->player.p_pos.x
			+ data->map->player.plane_pos.x * SPEED)]
	[(int)(data->map->player.p_pos.y)] == '0'
	|| data->map->map_2[(int)(data->map->player.p_pos.x
	+ data->map->player.plane_pos.x * SPEED)][(int)(data->map->player.p_pos.y)]
	== data->map->player.p_dir)
		data->map->player.p_pos.x += data->map->player.plane_pos.x * SPEED;
	if (data->map->map_2[(int)(data->map->player.p_pos.x)]
	[(int)(data->map->player.p_pos.y + data->map->player.plane_pos.y
	* SPEED)] == '0' || data->map->map_2[(int)(data->map->player.p_pos.x)]
	[(int)(data->map->player.p_pos.y + data->map->player.plane_pos.y * SPEED)]
	== data->map->player.p_dir)
		data->map->player.p_pos.y += data->map->player.plane_pos.y * SPEED;
}

void	keyboard_gameplay(t_data *data)
{	
	if (data->map->player.gamplay.forward == 1)
		forward(data);
	if (data->map->player.gamplay.backward == 1)
		back(data);
	if (data->map->player.gamplay.left == 1)
		left(data);
	if (data->map->player.gamplay.right == 1)
		right(data);
	if (data->map->player.gamplay.look_left == 1)
		look_left(data);
	if (data->map->player.gamplay.look_right == 1)
		look_right(data);
	if (data->map->player.gamplay.escape == 1)
		close_escape(XK_Escape, data);
}
