/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 07:48:10 by user42            #+#    #+#             */
/*   Updated: 2022/05/15 10:01:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_return_size_of_file(char *argv)
{
	int j;
	int i;
	int fd;
	char *buffer;

	j = 1;
	i = 0;
	fd = open(argv, O_RDONLY);
	buffer =  (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (buffer == NULL)
		return (i);
	while (j != 0)
	{
		j = read(fd, buffer, BUFFER_SIZE);
		if (j == -1)
		{
			free(buffer);
			return (i);
		}
		i++;
	}
	free(buffer);
	return (i);
}

char *ft_buffer_init(char *buffer)
{
	buffer =  (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (buffer == NULL)
		return (NULL);
	return (buffer);
}

char **new_gnl(int fd, char *argv)
{
    char *buffer;
	char **ret;
	int i;
	int j;

	j = 1;
	buffer = NULL;
    buffer = ft_buffer_init(buffer);
	i = ft_return_size_of_file(argv);
	ret = ft_calloc(sizeof(char *), i + 8);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (j != 0)
	{
		j = read(fd, buffer, BUFFER_SIZE);
		if (j == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[j] = '\0';
		ret[i] = ft_strdup(buffer);
		i++;
	}
	free(buffer);
	return (ret);
}