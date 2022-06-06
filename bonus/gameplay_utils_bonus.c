/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:59:29 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/06 21:31:47 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	press_keyboard(int key, t_data *data)
{
	if (key == XK_w)
		data->map->player.gamplay.forward = 1;
	else if (key == XK_s)
		data->map->player.gamplay.backward = 1;
	else if (key == XK_a)
		data->map->player.gamplay.left = 1;
	else if (key == XK_d)
		data->map->player.gamplay.right = 1;
	else if (key == XK_Left)
		data->map->player.gamplay.look_left = 1;
	else if (key == XK_Right)
		data->map->player.gamplay.look_right = 1;
	else if (key == XK_Escape)
		data->map->player.gamplay.escape = 1;
	return (SUCCESS);
}

int	release_keyboard(int key, t_data *data)
{
	if (key == XK_w)
		data->map->player.gamplay.forward = 0;
	else if (key == XK_s)
		data->map->player.gamplay.backward = 0;
	else if (key == XK_a)
		data->map->player.gamplay.left = 0;
	else if (key == XK_d)
		data->map->player.gamplay.right = 0;
	else if (key == XK_Left)
		data->map->player.gamplay.look_left = 0;
	else if (key == XK_Right)
		data->map->player.gamplay.look_right = 0;
	else if (key == XK_Escape)
		data->map->player.gamplay.escape = 0;
	return (SUCCESS);
}

int	create_rays(t_data *data)
{
	keyboard_gameplay(data);
	put_image_on_screen(data);
	return (0);
}
