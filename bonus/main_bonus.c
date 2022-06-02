/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:40:37 by fboumell          #+#    #+#             */
/*   Updated: 2022/06/02 22:36:18 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	data = NULL;
	if (!(*env))
		return (return_failure("Error\nNo environment."));
	if (check_arguments(ac, av[1]) == FAILURE)
		return (FAILURE);
	data = malloc(sizeof(t_data));
	if (!data)
		return (FAILURE);
	init_data(data);
	if (check_file_content(av[1], data) == FAILURE)
	{
		free_map_info(data->map_info, data);
		free_data(data);
		free(data);
		return (FAILURE);
	}
	init_window(data);
	if (create_textures_wall(data) == FAILURE)
		return (FAILURE);
	loop(data);
	return (SUCCESS);
}
