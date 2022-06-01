#include "cub3d.h"

int	check_file_content(char *argv, t_data *data)
{
	data->map = count_line(argv, data);
	if (check_line_content(data->map, data) == FAILURE)
		return (FAILURE);
	data->map = count_line_for_map(argv, data);
	if (data->map->space_in_map_2 == 1)
		return (return_failure("Error\nNo empty line allowed for map."));
	if (check_map_content_characters(data) == FAILURE)
		return (FAILURE);
	data->map_info = get_all_map_info(data);
	return (SUCCESS);
}