/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_step_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:07:41 by fboumell          #+#    #+#             */
/*   Updated: 2022/06/03 15:28:03 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file_content(char *argv, t_data *data)
{
	data->map = count_line(argv, data);
	if (check_line_content(data->map, data) == FAILURE)
		return (FAILURE);
	data->map = count_line_for_map(argv, data);
	if (data->map->space_in_map_2 == 1)
		return (return_failure("Error\nError Parsing."));
	if (check_map_content_characters(data) == FAILURE)
		return (FAILURE);
	data->map_info = get_all_map_info(data);
	return (SUCCESS);
}
