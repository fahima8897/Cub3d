/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:39:58 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/28 16:46:10 by user42           ###   ########.fr       */
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
//	if (map_info->no_texture)
//		free(map_info->no_texture);
//	if (map_info->so_texture)
//		free(map_info->so_texture);
//	if (map_info->ea_texture)
//		free(map_info->ea_texture);
//	if (map_info->we_texture)
//		free(map_info->we_texture);
/*	free(data->map_info->east.img);
	free(data->map_info->west.img);
	free(data->map_info->north.img);
	free(data->map_info->south.img);
	free(data->map_info->east.addr);
	free(data->map_info->west.addr);
	free(data->map_info->north.addr);
	free(data->map_info->south.addr);*/
	free(map_info);
}

void	free_data(t_data *data)
{
	if (data->map)
		free_struct(data->map);
	//mlx_destroy_image(data->mlx, data->map_info->east.img);
//	mlx_destroy_image(data->mlx, data->tx.img);
	free_map_info(data->map_info, data);
	if (data != NULL)
		free(data);
}
