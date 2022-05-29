/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:53:47 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/29 23:44:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// penser a destroy image ou texture et a free le double tableau de la map
int	close_escape(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		if (data->mlx_win)
		{
			free_map_info(data->map_info, data);
			free_data(data);
			mlx_destroy_window(data->mlx, data->mlx_win);
			mlx_destroy_display(data->mlx);
			data->mlx_win = NULL;
		}
		free(data->mlx);
	if (data != NULL)
		free(data);
		exit(0);
	}
/*	if (keycode == 100 || keycode == 97 || keycode == 115 || keycode == 119)
		printf("coucou\n");*/
	return (SUCCESS);
}

// penser a destroy image ou texture et a free le double tableau de la map
int	close_redx(t_data *data)
{
	if (data->mlx_win)
	{
		free_map_info(data->map_info, data);
		free_data(data);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		data->mlx_win = NULL;
	}
	free(data->mlx);
	if (data != NULL)
		free(data);
	exit(0);
}

int	init_display(t_data *data)
{
	data->tx.img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	if (!data->tx.img)
		return (return_failure("Error\nInit display\n"));
	data->tx.addr = mlx_get_data_addr(data->tx.img, &data->tx.bpp,
			&data->tx.line, &data->tx.endian);
	if (!data->tx.addr)
		return (return_failure("Error\nInit display\n"));
	return (SUCCESS);
}

/*initialisation de width et height juste pour tester
A initialiser comme il faut quand dans une fonction 
	et quand on aura la taille de la map*/
int	init_window(t_data *data)
{
	data->win_width = 800;
	data->win_height = 600;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (FAILURE);
	data->mlx_win = mlx_new_window(data->mlx, data->win_width,
			data->win_height, "cub3D");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_win);
		free(data);
		return (FAILURE);
	}
	if (init_display(data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int press_keyboard(int key, t_data *data)
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
	else
		printf("No action is on this key\n");
	return (SUCCESS);
}

int release_keyboard(int key, t_data *data)
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

int	loop_raycast(t_data *data)
{
	keyboard_gameplay(data);
	draw(data);
	return (0);
}

void	loop(t_data *data)
{
	mlx_loop_hook(data->mlx, loop_raycast, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, &press_keyboard, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, &release_keyboard, data);
	//mlx_hook(data->mlx_win, 2, 1L << 0, &close_escape, data);
	mlx_hook(data->mlx_win, 17, 0L, &close_redx, data);
//	mlx_do_sync(data->mlx);
	mlx_loop(data->mlx);
}
