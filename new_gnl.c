/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 07:48:10 by user42            #+#    #+#             */
/*   Updated: 2022/05/16 15:49:40 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_return_size_of_file(char *argv)
{
	int		j;
	int		i;
	int		fd;
	char	*buffer;

	j = 1;
	i = 0;
	fd = open(argv, O_RDONLY);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (buffer == NULL)
		return (i);
	while (j != 0)
	{
		j = read(fd, buffer, 1);
		if (buffer[0] == '\n')
			i++;
		if (j == FAILURE)
		{
			free(buffer);
			return (i);
		}
	}
	// i++;
	free(buffer);
	close(fd);
	return (i);
}

char	**ft_ret_init(char **ret, int i)
{
	ret = ft_calloc(sizeof(char *), i + 1);
	if (ret == NULL)
		return (NULL);
	return (ret);
}
