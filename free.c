/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:39:58 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/17 18:02:41 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	free_struct(t_map *map)
{
	free_tab(map->map);
	free(map);
}

void	free_data(t_data *data)
{
	if (data->map)
		free_struct(data->map);
	if (data != NULL)
		free(data);
}
