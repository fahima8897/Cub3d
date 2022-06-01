/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sound_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:50:50 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/01 16:35:03 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	play_sound_bonus(char *path, int volume) // bonus,mais fonction pas bonne
{
	char	command[500];
	char	*tmp;
	double	calcul;

	calcul = (double)volume / 100 * 65536;
	ft_bzero(command, 500);
	ft_strlcat(command, "(" "paplay" " --volume ", 500);
	tmp = ft_itoa((int)calcul);
	ft_strlcat(command, tmp, 500);
	free(tmp);
	ft_strlcat(command, " ", 500);
	ft_strlcat(command, path, 500);
	ft_strlcat(command, " &" ") " " > /dev/null 2>&1", 500);
	return (system(command));
}

void	menu_and_music_bonus(t_data *data)
{
	t_img menu;

	menu.img = mlx_xpm_file_to_image(data->mlx, "./ressources/re4menu.xpm",
			&menu.width, &menu.height);
	if (!menu.img)
	{
		printf("\033[1;31mError\nLoading menu image failed.\n\033[0m");
		free_loading_txt_failed(data);
	}
	menu.addr = mlx_get_data_addr(menu.img, &menu.bpp,
			&menu.line, &menu.endian);
	if (!menu.addr)
	{
		printf("\033[1;31mError\nLoading menu image failed.\n\033[0m");
		free_loading_txt_failed(data);
	}
	menu.status = 1;
	mlx_put_image_to_window(data->mlx, data->mlx_win, menu.img, -150, 0);
	play_sound_bonus("./ressources/resident_evil_4.wav", 100); // bonus
	sleep(5);
	if (menu.status == 1)
		mlx_destroy_image(data->mlx, menu.img);
	play_sound_bonus("./ressources/RE4_Save_Theme.wav", 30); // bonus
}
