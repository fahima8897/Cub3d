/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:53:47 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/21 11:40:41 by user42           ###   ########.fr       */
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
			mlx_destroy_window(data->mlx, data->mlx_win);
			mlx_destroy_display(data->mlx);
			data->mlx_win = NULL;
		}
		free(data->mlx);
		free_data(data);
		exit(0);
	}
	if (keycode == 100 || keycode == 97 || keycode == 115 || keycode == 119)
		printf("coucou\n");
	return (SUCCESS);
}

// penser a destroy image ou texture et a free le double tableau de la map
int	close_redx(t_data *data)
{
	if (data->mlx_win)
	{
		free_map_info(data->map_info, data);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		data->mlx_win = NULL;
	}
	free(data->mlx);
	free_data(data);
	exit(0);
}

/*initialisation de width et height juste pour tester
A initialiser comme il faut quand dans une fonction 
	et quand on aura la taille de la map*/
int	init_window(t_data *data)
{
	data->win_width = 24 * 48;
	data->win_height = 10 * 48;
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
	return (SUCCESS);
}

void	loop(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 1L << 0, &close_escape, data);
	mlx_hook(data->mlx_win, 17, 0L, &close_redx, data);
	mlx_loop(data->mlx);
}
