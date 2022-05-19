/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:39:37 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/19 15:39:52 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_get_next_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] > 32)
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}

t_map	*reduce_count_line(t_data *data, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while ((line = get_next_line(fd)))
	{
		if (check_get_next_line(line) == SUCCESS)
		{
			if (i <= 5)
			{
				data->map->map[i] = strdup_no_n(line);
				i++;
			}
		}
		free(line);
	}
	free(line);
	close(fd);
	return (data->map);
}

t_map	*count_line(char *s, t_data *data)
{
	int		fd;

	data->map->map = ft_calloc(6 + 1, sizeof(char *));
	if (!(data->map->map))
		return (NULL);
	fd = open(s, O_RDONLY);
	if (fd < 0)
		printf("Error\nOpen map.cub failed\n");
	else
		data->map = reduce_count_line(data, fd);
	return (data->map);
}
