/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:40:37 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/21 14:56:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extension(char *av)
{
	int		i;
	char	*format;

	i = 0;
	format = "cub";
	if (av[5] == '.' || av[0] == '.')
		return (FAILURE);
	if (parse(av) == FAILURE)
		return (1);
	while (av[i])
	{
		if (av[i] == '.')
		{
			i++;
			if (ft_strcmp((av + i), format) != 0)
				return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

int	check_directory(char *av)
{
	int	fd;

	fd = open(av, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	check_file_existence(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (FAILURE);
	}
	close(fd);
	return (SUCCESS);
}

void	check_arguments(int ac, char *av)
{
	int	ret;

	ret = 0;
	if (ac != 2)
		write_errors("Error.\nWrong number of arguments.");
	ret = check_directory(av);
	if (ret == FAILURE)
		write_errors("Error.\nYou are trying to open a directory.");
	ret = check_file_existence(av);
	if (ret == FAILURE)
		write_errors("Error.\nThe file you are trying to open does not exist.");
	ret = check_extension(av);
	if (ret == FAILURE)
		write_errors("Error.\nExtension map invalid.");
	if (ret == 1)
		write_errors("Error.\nExtension file missing.");
}

int	ft_create_textures(t_data *data)
{
	int	a;
	int	b;

	a = 48 * 24;
	b = 48 * 10;
	data->map_info->mlx_we = mlx_xpm_file_to_image(data->mlx,
			data->map_info->we_texture, &a, &b);
	if (!data->map_info->mlx_we)
		return (return_failure("Error\nxpm to image failed for WE."));
	data->map_info->mlx_ea = mlx_xpm_file_to_image(data->mlx,
			data->map_info->ea_texture, &a, &b);
	if (!data->map_info->mlx_ea)
		return (return_failure("Error\nxpm to image failed for EA."));
	data->map_info->mlx_no = mlx_xpm_file_to_image(data->mlx,
			data->map_info->no_texture, &a, &b);
	if (!data->map_info->mlx_no)
		return (return_failure("Error\nxpm to image failed for NO."));
	data->map_info->mlx_so = mlx_xpm_file_to_image(data->mlx,
			data->map_info->so_texture, &a, &b);
	if (!data->map_info->mlx_so)
		return (return_failure("Error\nxpm to image failed for SO."));
	return (SUCCESS);
}

void	ft_put_images(t_data *data, int width, int i, int j)
{
	if (data->map->map_2[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->map_info->mlx_ea,
			width, i * 48);
	else if (data->map->map_2[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->map_info->mlx_so,
			width, i * 48);
/*	else if (data->map.map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->map_info->,
			width, i * 48);*/
/*	else if (data->map.map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->image.exit,
			width, i * 48);
	else if (data->map.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->image.mouse,
			width, i * 48);*/
}

int	ft_image(t_data *data)
{
	int		i;
	size_t	j;
	int		width;

	if (data->mlx_win == NULL)
		return (0);
	i = 0;
	j = 0;
	width = 0;
	while (data->map->map_2[i])
	{
		while (data->map->map_2[i][j] && data->map->map_2[i][j] != '\n')
		{
			ft_put_images(data, width, i, j);
			width += 48;
			j++;
		}
		j = 0;
		width = 0;
		i++;
	}
	return (1);
}

int	free_win_and_data(t_data *data)
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
	return (FAILURE);
}

void	init_ray(t_data *data)
{
	data->ray->posx = (double)data->map->p_pos_x + 0.5;
	data->ray->posy = (double)data->map->p_pos_y + 0.5;
	data->ray->dirx = 0;
	data->ray->diry = 0;
	data->ray->planx = 0;
	data->ray->plany = 0;
	data->ray->hit = 0;
	data->ray->perpwalldist = 0;
	data->ray->camerax = 2 * data->ray->x / (double)10 - 1;
	data->ray->raydirx = data->ray->dirx + data->ray->planx * \
						data->ray->camerax;
	data->ray->raydiry = data->ray->diry + data->ray->plany * \
						data->ray->camerax;
	data->ray->mapx = (int)data->ray->posx;
	data->ray->mapy = (int)data->ray->posy;
	data->ray->movespeed = 0.1;
	data->ray->rotspeed = 0.033 * 1.8;
	if (data->map->player == 'N')
		data->ray->dirx = -1;
	if (data->map->player == 'S')
		data->ray->dirx = 1;
	if (data->map->player == 'E')
		data->ray->diry = 1;
	if (data->map->player == 'W')
		data->ray->diry = -1;
	if (data->map->player == 'N')
		data->ray->plany = 0.66;
	if (data->map->player == 'S')
		data->ray->plany = -0.66;
	if (data->map->player == 'E')
		data->ray->planx = 0.66;
	if (data->map->player == 'W')
		data->ray->planx = -0.66;
	printf("ray == %f\n", data->ray->plany);
	printf("ray == %f\n", data->ray->planx);
	printf("ray == %f\n", data->ray->diry);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (FAILURE);
	check_arguments(ac, av[1]);
	init_data(data);
	if (check_opt_argv_map(av[1], data) == FAILURE)
	{
		free_map_info(data->map_info, data);
		free_data(data);
		return (FAILURE);
	}
	init_ray(data);
	init_window(data);
	if (ft_create_textures(data) == FAILURE)
		return (free_win_and_data(data));
	ft_image(data);
	loop(data);
	return (SUCCESS);
}
