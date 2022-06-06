/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_line_content2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:54:13 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/06 19:47:12 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_no(t_verif *check, char *tmp, t_data *data)
{
	check->no++;
	if (check_verif(*check) == FAILURE)
		return (FAILURE);
	data->map->fd = open(tmp, O_RDONLY);
	if (data->map->fd < 0)
		return (FAILURE);
	close(data->map->fd);
	return (SUCCESS);
}

int	check_so(t_verif *check, char *tmp, t_data *data)
{
	check->so++;
	if (check_verif(*check) == FAILURE)
		return (FAILURE);
	data->map->fd = open(tmp, O_RDONLY);
	if (data->map->fd < 0)
		return (FAILURE);
	close(data->map->fd);
	return (SUCCESS);
}

int	check_we(t_verif *check, char *tmp, t_data *data)
{
	check->we++;
	if (check_verif(*check) == FAILURE)
		return (FAILURE);
	data->map->fd = open(tmp, O_RDONLY);
	if (data->map->fd < 0)
		return (FAILURE);
	close(data->map->fd);
	return (SUCCESS);
}

int	check_ea(t_verif *check, char *tmp, t_data *data)
{
	check->ea++;
	if (check_verif(*check) == FAILURE)
		return (FAILURE);
	data->map->fd = open(tmp, O_RDONLY);
	if (data->map->fd < 0)
		return (FAILURE);
	close(data->map->fd);
	return (SUCCESS);
}
