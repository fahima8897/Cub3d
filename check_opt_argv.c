/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:14:49 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/14 18:50:31 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*join(char *s1, char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	join;
	char	*tmp;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len_s2 = ft_strlen(s2);
	len_s1 = ft_strlen(s1);
	join = len_s1 + len_s2;
	tmp = (char *)malloc(sizeof(char *) * (join + 2));
	if (tmp == NULL)
		return (0);
	ft_memmove(tmp, s1, len_s1);
	ft_memmove(tmp + len_s1, s2, len_s2);
	tmp[join] = '\n';
	tmp[join + 1] = '\0';
	str = tmp;
	free(tmp);
	return (str);
}

char **get_map(char *argv)
{
    char *buffer;
	char **full_map = NULL;
	char *map;
	char *tmp;
	int fd;

	tmp = NULL;
	buffer = NULL;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &buffer) > 0)
	{
		printf("buffer = %s\n", buffer);
		map = join(tmp, buffer);
		free(buffer);
	}
//	full_map = ft_split(map, '\n');
//	int i = 0;
//	while (full_map[i])
//	{
//		printf("full map = %s\n", full_map[i]);
//		i++;
//	}
	free(tmp);
	return (full_map);
}

void check_opt_argv_map(char *argv)
{
	char **map;
	
    map = get_map(argv);
//	ft_free_tab(map);
}