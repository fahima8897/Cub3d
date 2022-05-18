/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:14:49 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/18 23:31:02 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_opt_argv_map(char *argv, t_data *data)
{
	data->map = count_line(argv, data);
	if (check_line_content(data->map) == FAILURE)
		return (FAILURE);
	data->map = count_line_for_map(argv, data);
	if (data->map->space_in_map == 1)
		return (return_failure("Error\nNo empty line allowed for map."));
//	int i = 0;
//	while(data->map->map[i])
//	{
//		printf("map == %s", data->map->map[i]);
//		i++;
//	}
	if (check_map_content_characters(data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
