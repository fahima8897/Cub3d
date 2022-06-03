/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_line_content2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:54:13 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/03 14:49:44 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_fd(char *str, int fd)
{
	printf("\033[1;31m%s\n\033[0m", str);
	close(fd);
	return (FAILURE);
}

int	check_no(t_verif *check, char *tmp, t_data *data)
{
	check->no++;
	if (check_verif(*check) == FAILURE)
		return (return_failure("Error\nError Parsing."));
	data->map->fd = open(tmp, O_RDONLY);
	if (data->map->fd < 0)
		return (close_fd("Error\nCould not open file.", data->map->fd));
	close(data->map->fd);
	return (SUCCESS);
}

int	check_so(t_verif *check, char *tmp, t_data *data)
{
	check->so++;
	if (check_verif(*check) == FAILURE)
		return (return_failure("Error\nError Parsing."));
	data->map->fd = open(tmp, O_RDONLY);
	if (data->map->fd < 0)
		return (close_fd("Error\nCould not open file.", data->map->fd));
	close(data->map->fd);
	return (SUCCESS);
}

int	check_we(t_verif *check, char *tmp, t_data *data)
{
	check->we++;
	if (check_verif(*check) == FAILURE)
		return (return_failure("Error\nError Parsing."));
	data->map->fd = open(tmp, O_RDONLY);
	if (data->map->fd < 0)
		return (close_fd("Error\nCould not open file.", data->map->fd));
	close(data->map->fd);
	return (SUCCESS);
}

int	check_ea(t_verif *check, char *tmp, t_data *data)
{
	check->ea++;
	if (check_verif(*check) == FAILURE)
		return (return_failure("Error\nError Parsing."));
	data->map->fd = open(tmp, O_RDONLY);
	if (data->map->fd < 0)
		return (close_fd("Error\nCould not open file.", data->map->fd));
	close(data->map->fd);
	return (SUCCESS);
}
