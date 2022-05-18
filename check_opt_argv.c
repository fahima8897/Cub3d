/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:14:49 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/18 20:37:23 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_opt_argv_map(char *argv, t_data *data)
{
//	data->map = create_map(argv, data);
	int i;

	i = 0;
	data->map = count_line(argv, data);
	if (check_line_content(data->map) == FAILURE)
		return (FAILURE);
	while (data->map->map[i])
	{
		printf("%s", data->map->map[i]);
		i++;
	}
	return (SUCCESS);
}
