/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:53:47 by fboumell          #+#    #+#             */
/*   Updated: 2022/06/06 21:31:47 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
		free(data);
		system("killall paplay");
		exit(0);
	}
	return (SUCCESS);
}

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
	system("killall paplay");
	if (data != NULL)
		free(data);
	exit(0);
}

int	put_new_image_on_screen(t_data *data)
{
	data->screen.img = mlx_new_image(data->mlx, data->win_width,
			data->win_height);
	if (!data->screen.img)
		return (return_failure("Error\nInit display\n"));
	data->screen.addr = mlx_get_data_addr(data->screen.img, &data->screen.bpp,
			&data->screen.line, &data->screen.endian);
	if (!data->screen.addr)
		return (return_failure("Error\nInit display\n"));
	data->screen.status = 1;
	return (SUCCESS);
}

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
	if (put_new_image_on_screen(data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

void	loop(t_data *data)
{
	mlx_loop_hook(data->mlx, create_rays, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, &press_keyboard, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, &release_keyboard, data);
	mlx_hook(data->mlx_win, MotionNotify, PointerMotionMask,
		&mouse_handler, data);
	mlx_hook(data->mlx_win, 17, 0L, &close_redx, data);
	menu_and_music_bonus(data);
	mlx_loop(data->mlx);
}
