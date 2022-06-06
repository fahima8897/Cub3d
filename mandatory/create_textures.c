/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:18:00 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/06 21:16:35 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_xpm_to_img(t_data *data, char **s, char *texture, t_img *txt)
{
	txt->img = mlx_xpm_file_to_image(data->mlx, texture,
			&txt->width, &txt->height);
	if (!txt->img)
		return (ret_free_txt("Error\nmlx_xpm_to_image failed.", s, data));
	txt->addr = mlx_get_data_addr(txt->img, &txt->bpp,
			&txt->line, &txt->endian);
	if (!txt->addr)
		return (ret_free_txt("Error\nmlx_get_data_addr failed.", s, data));
	txt->status = 1;
	return (SUCCESS);
}

int	reduce_create_textures_wall(t_data *data, char **s)
{
	if (ft_strncmp(s[0], "EA", 3) == 0)
	{
		if (get_xpm_to_img(data, s, data->map_info->ea_texture,
				&data->east) == FAILURE)
			return (FAILURE);
	}
	if (ft_strncmp(s[0], "WE", 3) == 0)
	{
		if (get_xpm_to_img(data, s, data->map_info->we_texture,
				&data->west) == FAILURE)
			return (FAILURE);
	}
	if (ft_strncmp(s[0], "NO", 3) == 0)
	{
		if (get_xpm_to_img(data, s, data->map_info->no_texture,
				&data->north) == FAILURE)
			return (FAILURE);
	}
	if (ft_strncmp(s[0], "SO", 3) == 0)
	{
		if (get_xpm_to_img(data, s, data->map_info->so_texture,
				&data->south) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	create_textures_wall(t_data *data)
{
	int		i;
	char	**s_byspace;

	i = -1;
	while (data->map->map[++i])
	{
		s_byspace = ft_split(data->map->map[i], ' ');
		if (ft_strncmp(s_byspace[0], "EA", 3) == 0)
			reduce_create_textures_wall(data, s_byspace);
		if (ft_strncmp(s_byspace[0], "WE", 3) == 0)
			reduce_create_textures_wall(data, s_byspace);
		if (ft_strncmp(s_byspace[0], "NO", 3) == 0)
			reduce_create_textures_wall(data, s_byspace);
		if (ft_strncmp(s_byspace[0], "SO", 3) == 0)
			reduce_create_textures_wall(data, s_byspace);
		free_tab(s_byspace);
	}
	return (SUCCESS);
}
