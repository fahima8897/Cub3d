/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:40:37 by fboumell          #+#    #+#             */
/*   Updated: 2022/06/01 00:22:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (FAILURE);
	if (check_arguments(ac, av[1]) == FAILURE)
	{
		free(data);
		return (FAILURE);
	}
	init_data(data);
	if (check_opt_argv_map(av[1], data) == FAILURE)
	{
		free_map_info(data->map_info, data);
		free_data(data);
		return (FAILURE);
	}
	printf("floor %d,%d,%d\n", data->map_info->f_red, data->map_info->f_green, data->map_info->f_blue);
	printf("floor %d,%d,%d\n", data->map_info->c_red, data->map_info->c_green, data->map_info->c_blue);
	init_window(data);
	if (create_textures_wall(data) == FAILURE)
		return (FAILURE);
	loop(data);
	return (SUCCESS);
}
