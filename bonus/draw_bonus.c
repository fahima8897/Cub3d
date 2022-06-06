/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:24:25 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/06 21:18:27 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	find_limit(t_data *data, int *limit, int *begin)
{
	if (data->ray.wall_start < 0)
		*begin = 0;
	else
		*begin = data->ray.wall_start;
	if (data->ray.wall_end >= data->win_height)
		*limit = data->win_height - 1;
	else
		*limit = data->ray.wall_end;
	return (SUCCESS);
}

int	draw_every_walls(t_data *data, t_img *img, int height, int width)
{
	data->screen.addr[(width * data->screen.bpp >> 3)
		+ height * data->screen.line]
		= img->addr[(int)(data->ray.wall_x * img->width) * (img->bpp >> 3)
		+ (int)((height - data->ray.wall_start * 1.0) / data->ray.line_height
			* img->height) *img->line];
	data->screen.addr[(width * data->screen.bpp >> 3)
		+ 1 + height * data->screen.line]
		= img->addr[(int)(data->ray.wall_x * img->width) * (img->bpp >> 3)
		+ 1 + (int)((height - data->ray.wall_start * 1.0)
			/ data->ray.line_height * img->height) *img->line];
	data->screen.addr[(width * data->screen.bpp >> 3)
		+ 2 + height * data->screen.line]
		= img->addr[(int)(data->ray.wall_x * img->width) * (img->bpp >> 3)
		+ 2 + (int)((height - data->ray.wall_start * 1.0)
			/ data->ray.line_height * img->height) *img->line];
	return (SUCCESS);
}

int	draw_walls_types(t_data *data, int height, int width)
{
	if (data->ray.side == NO)
		draw_every_walls(data, &data->west, height, width);
	if (data->ray.side == SO)
		draw_every_walls(data, &data->east, height, width);
	if (data->ray.side == WE)
		draw_every_walls(data, &data->north, height, width);
	if (data->ray.side == EA)
		draw_every_walls(data, &data->south, height, width);
	return (SUCCESS);
}

int	draw_colors_on_screen(t_data *data, int *tab, int width, int height)
{
	if (data->screen.endian == 1)
	{
		data->screen.addr[(width * data->screen.bpp >> 3)
			+ height * data->screen.line] = tab[0];
		data->screen.addr[(width * data->screen.bpp >> 3)
			+ 1 + height * data->screen.line] = tab[1];
		data->screen.addr[(width * data->screen.bpp >> 3)
			+ 2 + height * data->screen.line] = tab[2];
	}
	else
	{
		data->screen.addr[(width * data->screen.bpp >> 3)
			+ height * data->screen.line] = tab[2];
		data->screen.addr[(width * data->screen.bpp >> 3)
			+ 1 + height * data->screen.line] = tab[1];
		data->screen.addr[(width * data->screen.bpp >> 3)
			+ 2 + height * data->screen.line] = tab[0];
	}
	return (SUCCESS);
}

int	draw_on_screen(t_data *data, int width)
{
	int	limit;
	int	begin;
	int	height;
	int	tab_floor[3];
	int	tab_ceiling[3];

	find_limit(data, &limit, &begin);
	tab_init(data, tab_floor, tab_ceiling);
	height = 0;
	while (height < begin)
	{
		draw_colors_on_screen(data, tab_ceiling, width, height);
		height++;
	}
	while (height < limit)
	{
		draw_walls_types(data, height, width);
		height++;
	}
	while (height < data->win_height - 1)
	{
		draw_colors_on_screen(data, tab_floor, width, height);
		height++;
	}
	return (SUCCESS);
}
