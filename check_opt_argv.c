/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:14:49 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/15 09:51:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void check_opt_argv_map(char *argv)
{
	char **map = NULL;
	int fd;
	
	fd = open(argv, O_RDONLY);
    map = new_gnl(fd, argv);
	int i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	ft_free_tab(map);
}