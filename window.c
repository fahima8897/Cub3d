/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:53:47 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/13 15:34:46 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loop(t_data data)
{
	mlx_hook(data.mlx_win, 2, 1L << 0, &close_escape, &data);
	mlx_hook(data.mlx_win, 17, 0L, &close_redx, &data);
	mlx_loop(data.mlx);
}

// penser a destroy image ou texture et a free le double tableau de la map
int	close_escape(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		if (data->mlx_win)
		{
			mlx_destroy_window(data->mlx, data->mlx_win);
			mlx_destroy_display(data->mlx);
			data->mlx_win = NULL;
		}
		free(data->mlx);
		exit(0);
	}
	return (SUCCESS);
}

// penser a destroy image ou texture et a free le double tableau de la map
int	close_redx(t_data *data)
{
	if (data->mlx_win)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		data->mlx_win = NULL;
	}
	free(data->mlx);
	exit(0);
}

int	init_window(t_data *data)
{
	/*initialisation de width et height juste pour tester
	A initialiser comme il faut quand dans une fonction 
	 et quand on aura la taille de la map*/
	data->win_width = 640;
	data->win_height = 800;

	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (FAILURE);
	data->mlx_win = mlx_new_window(data->mlx, data->win_width,
			data->win_height, "cub3D");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_win);
		return (FAILURE);
	}
	return (SUCCESS);
}
