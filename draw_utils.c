#include "cub3d.h"

void	tab_init(t_data *data, int *tab_floor, int *tab_ceiling)
{
	tab_floor[0] = data->map_info->f_red;
	tab_floor[1] = data->map_info->f_green;
	tab_floor[2] = data->map_info->f_blue;
	tab_ceiling[0] = data->map_info->c_red;
	tab_ceiling[1] = data->map_info->c_green;
	tab_ceiling[2] = data->map_info->c_blue;
}