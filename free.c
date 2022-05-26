/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:39:58 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/26 14:56:10 by adaloui          ###   ########.fr       */
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
	if (map_info->no_texture)
		free(map_info->no_texture);
	if (map_info->so_texture)
		free(map_info->so_texture);
	if (map_info->ea_texture)
		free(map_info->ea_texture);
	if (map_info->we_texture)
		free(map_info->we_texture);
	if (map_info->mlx_ea)
		mlx_destroy_image(data->mlx, map_info->mlx_ea);
	if (map_info->mlx_no)
		mlx_destroy_image(data->mlx, map_info->mlx_no);
	if (map_info->mlx_so)
		mlx_destroy_image(data->mlx, map_info->mlx_so);
	if (map_info->mlx_we)
		mlx_destroy_image(data->mlx, map_info->mlx_we);
	free(map_info);
}

void	free_tx(t_data *data)
{
	printf("COUCOU\n");
	printf("img = %p\n", data->tx->img);
	if (data->tx->img)
	{
		printf("FREE IMG\n");
		free(data->tx->img);
	}
	printf("img = %p\n", data->tx->img);
//	if (data->tx->addr)
//		free(data->tx->addr);
/*	if (data->tx->img != NULL)
	{
		mlx_destroy_image(data->mlx, data->tx->img);
		data->tx->img = NULL;
	}*/
	if (data->tx)
		free(data->tx);
}

void	free_data(t_data *data)
{
	if (data->map)
		free_struct(data->map);
	if (data->ray)
		free(data->ray);
	if (data->tx)
		free_tx(data);
	if (data != NULL)
		free(data);
}
