/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:14:49 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/16 11:38:58 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_verif	ft_verif_init(void)
{
	t_verif	check;

	check.c = 0;
	check.f = 0;
	check.ea = 0;
	check.no = 0;
	check.so = 0;
	check.we = 0;
	return (check);
}

int	ft_check_map_content(char **map)
{
	int		i;
	int		j;
	t_verif	check;

	i = 0;
	j = 0;
	check = ft_verif_init();
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			while (map[i][j] == ' ' || map[i][j] == '\t')
				j++;
			if (map[i][j] == 'C' && map[i][j + 1] == ' ')
				check.c = 1;
			if (map[i][j] == 'F' && map[i][j + 1] == ' ')
				check.f = 1;
			if (map[i][j] == 'N' && map[i][j + 1] == 'O'
				&& map[i][j + 2] == ' ')
				check.no = 1;
			if (map[i][j] == 'S' && map[i][j + 1] == 'O'
				&& map[i][j + 2] == ' ')
				check.so = 1;
			if (map[i][j] == 'E' && map[i][j + 1] == 'A'
				&& map[i][j + 2] == ' ')
				check.ea = 1;
			if (map[i][j] == 'W' && map[i][j + 1] == 'E'
				&& map[i][j + 2] == ' ')
				check.we = 1;
			j++;
		}
		i++;
	}
/*	char **split_space;
	int k;
	char *temp;
	k = 0;
	while (map[i])
	{
		split_space = ft_split(map[i], ' ');
		temp = split_space[0];
		k = 0;
		while (temp[k])
		{
			printf("%c", temp[k]);
			k++;
		}
		ft_free_tab(split_space);
		i++;
	}*/
/*	printf("J == %d\ni == %d\n", j, i);
	printf ("OUI check.c == %lld\n", check.c);
	printf ("OUI check.f == %lld\n", check.f);
	printf ("OUI check.ea == %lld\n", check.ea);
	printf ("OUI check.no == %lld\n", check.no);
	printf ("OUI check.so == %lld\n", check.so);
	printf ("OUI check.we == %lld\n", check.we);*/
	return (SUCCESS);
}

int	check_opt_argv_map(char *argv)
{
	char	**map;
	int		fd;
	int		i;
	int		j;

	map = NULL;
	fd = open (argv, O_RDONLY);
	i = ft_return_size_of_file(argv);
	j = 0;
	map = ft_ret_init(map, i);
	while (j <= i)
	{
		map[j] = get_next_line(fd);
		j++;
	}
	if (ft_check_map_content(map) == FAILURE)
	{
		ft_free_tab(map);
		return (FAILURE);
	}
	close(fd);
	ft_free_tab(map);
	return (SUCCESS);
}
