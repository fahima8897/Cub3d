/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:40:37 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/29 10:20:30 by user42           ###   ########.fr       */
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
	if (create_textures_wall(data) == FAILURE)
		return (free_win_and_data(data));
	loop(data);
	return (SUCCESS);
}
