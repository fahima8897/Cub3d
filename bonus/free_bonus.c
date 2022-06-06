/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:39:58 by fboumell          #+#    #+#             */
/*   Updated: 2022/06/06 17:05:55 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	free_struct(t_map *map)
{
	if (map->map)
		free_tab(map->map);
	if (map->map_2)
		free_tab(map->map_2);
	free(map);
}

void	free_map_info(t_map_info *map_info, t_data *data)
{
	(void)data;
	if (map_info->no_texture)
		free(map_info->no_texture);
	if (map_info->so_texture)
		free(map_info->so_texture);
	if (map_info->ea_texture)
		free(map_info->ea_texture);
	if (map_info->we_texture)
		free(map_info->we_texture);
	free(map_info);
}

void	free_loading_txt_failed(t_data *data)
{
	if (data->map)
		free_struct(data->map);
	if (data->east.status == 1)
		mlx_destroy_image(data->mlx, data->east.img);
	if (data->west.status == 1)
		mlx_destroy_image(data->mlx, data->west.img);
	if (data->north.status == 1)
		mlx_destroy_image(data->mlx, data->north.img);
	if (data->south.status == 1)
		mlx_destroy_image(data->mlx, data->south.img);
	if (data->mlx_win)
	{
		free_map_info(data->map_info, data);
		if (data->screen.img != NULL)
			mlx_destroy_image(data->mlx, data->screen.img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		data->mlx_win = NULL;
	}
	free(data->mlx);
	if (data)
		free(data);
	exit (0);
}

void	free_data(t_data *data)
{
	if (data->east.status == 1)
		mlx_destroy_image(data->mlx, data->east.img);
	if (data->west.status == 1)
		mlx_destroy_image(data->mlx, data->west.img);
	if (data->north.status == 1)
		mlx_destroy_image(data->mlx, data->north.img);
	if (data->south.status == 1)
		mlx_destroy_image(data->mlx, data->south.img);
	if (data->screen.status == 1)
		mlx_destroy_image(data->mlx, data->screen.img);
	if (data->map)
		free_struct(data->map);
}
