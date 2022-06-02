/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:05:15 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/02 22:29:06 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_one(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
		return (SUCCESS);
	while (str[i])
	{
		if ((str[i] > 32 && str[i] < 49) || (str[i] > 49 && str[i] < 127))
		{
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

void	reduce_reduce_cl_for_map(t_data *data, int i, char *line)
{
	data->map->is_map = 1;
	data->map->map_2[i] = strdup_no_n(line);
}

void	reduce_reduce_cl_for_map_2(t_data *data, int i, char *line)
{
	data->map->is_map = 1;
	data->map->gap = 0;
	if (ft_one(line) == -1 || ft_one(data->map->map_2[i - 2]) == -1)
		data->map->space_in_map_2 = 1;
}
