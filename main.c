/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:40:37 by fboumell          #+#    #+#             */
/*   Updated: 2022/06/01 00:57:14 by user42           ###   ########.fr       */
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
	if (check_file_content(av[1], data) == FAILURE)
	{
		free_map_info(data->map_info, data);
		free_data(data);
		return (FAILURE);
	}
	init_window(data);
	if (create_textures_wall(data) == FAILURE)
		return (FAILURE);
	loop(data);
	return (SUCCESS);
}
