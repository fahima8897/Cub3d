/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:38:08 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/18 23:03:08 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return ;
	data->map->map = NULL;
	data->map->fd = 0;
	data->map->count_line = 0;
	data->map->player = 0;
	data->map->space_in_map = 0;
}
