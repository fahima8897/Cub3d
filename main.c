/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:40:37 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/28 15:55:51 by user42           ###   ########.fr       */
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
	data->map_info->east.img = mlx_xpm_file_to_image(data->mlx, /*ICI*/
			data->map_info->we_texture, &data->map_info->east.width, &data->map_info->east.height);
	if (!data->map_info->east.img)
		return (return_failure("Error\nxpm to image failed for EA."));
	data->map_info->west.img = mlx_xpm_file_to_image(data->mlx,
			data->map_info->we_texture, &data->map_info->west.width, &data->map_info->west.height);
	if (!data->map_info->west.img)
		return (return_failure("Error\nxpm to image failed for WE."));
	data->map_info->north.img = mlx_xpm_file_to_image(data->mlx,
			data->map_info->we_texture, &data->map_info->north.width, &data->map_info->north.height);
	if (!data->map_info->north.img)
		return (return_failure("Error\nxpm to image failed for NO."));
	data->map_info->south.img = mlx_xpm_file_to_image(data->mlx,
			data->map_info->we_texture, &data->map_info->south.width, &data->map_info->south.height);
	if (!data->map_info->south.img)
		return (return_failure("Error\nxpm to image failed for SO."));
	
	
	
	data->map_info->east.addr = mlx_get_data_addr(data->map_info->east.img,
			&data->map_info->east.bpp, &data->map_info->east.line,
			&data->map_info->east.endian);
	if (!data->map_info->east.addr)
		return (return_failure("Error\nxpm to image failed for EA."));
	data->map_info->west.addr = mlx_get_data_addr(data->map_info->west.img,
			&data->map_info->west.bpp, &data->map_info->west.line,
			&data->map_info->west.endian);
	if (!data->map_info->west.addr)
		return (return_failure("Error\nxpm to image failed for WE."));
	data->map_info->north.addr = mlx_get_data_addr(data->map_info->north.img,
			&data->map_info->north.bpp, &data->map_info->north.line,
			&data->map_info->north.endian);
	if (!data->map_info->north.addr)
		return (return_failure("Error\nxpm to image failed for EA."));
	data->map_info->south.addr = mlx_get_data_addr(data->map_info->south.img,
			&data->map_info->south.bpp, &data->map_info->south.line,
			&data->map_info->south.endian);
	if (!data->map_info->south.addr)
		return (return_failure("Error\nxpm to image failed for EA."));
	data->map_info->east.status = 1;
	data->map_info->west.status = 1;
	data->map_info->north.status = 1;
	data->map_info->south.status = 1;
	return (SUCCESS);
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
	init_window(data);
	if (ft_create_textures(data) == FAILURE)
		return (free_win_and_data(data));
	loop(data);
	return (SUCCESS);
}
