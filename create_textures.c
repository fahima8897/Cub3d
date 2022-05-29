#include "cub3d.h"

t_img get_xpm_to_img(t_data *data, char *texture, t_img txt)
{
    txt.img = mlx_xpm_file_to_image(data->mlx, texture, &txt.width, &txt.height);
//	if (!txt.img)
//		return (return_failure("Error\nmlx_xpm_to_image failed."));
    txt.addr = mlx_get_data_addr(txt.img, &txt.bpp, &txt.line, &txt.endian);
    
	/* GERER LES ERREURS DANS LE CAS OU !TXT.IMG ou !TXT_ADDR*/
//	if (!txt.addr)
//		return (return_failure("Error\nmlx_get_data_addr failed."));
    txt.status = 1;
	return (txt);
}

int create_textures_wall(t_data *data)
{
	int i;
	char **s_byspace;

	i = -1;
	while (data->map->map[++i])
	{
		s_byspace = ft_split(data->map->map[i], ' ');
		if (ft_strncmp(s_byspace[0], "EA", 3) == 0)
			data->east = get_xpm_to_img(data, data->map_info->ea_texture, data->east);
		if (ft_strncmp(s_byspace[0], "WE", 3) == 0)
			data->west = get_xpm_to_img(data, data->map_info->we_texture, data->west);
		if (ft_strncmp(s_byspace[0], "NO", 3) == 0)
			data->north = get_xpm_to_img(data, data->map_info->no_texture, data->north);
		if (ft_strncmp(s_byspace[0], "SO", 3) == 0)
			data->south = get_xpm_to_img(data, data->map_info->so_texture, data->south);
		free_tab(s_byspace);
	}
	return (SUCCESS);
}