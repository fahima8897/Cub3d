/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:39:58 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/29 10:47:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	free_data(t_data *data)
{
	if (data->east.img != NULL)
		mlx_destroy_image(data->mlx, data->east.img);
	if (data->west.img != NULL)
		mlx_destroy_image(data->mlx, data->west.img);
	if (data->south.img != NULL)
		mlx_destroy_image(data->mlx, data->south.img);
	if (data->north.img != NULL)
		mlx_destroy_image(data->mlx, data->north.img);
	if (data->tx.img != NULL)
		mlx_destroy_image(data->mlx, data->tx.img);
	if (data->map)
		free_struct(data->map);
}
