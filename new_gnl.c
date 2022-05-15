/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 07:48:10 by user42            #+#    #+#             */
/*   Updated: 2022/05/15 15:46:03 by user42           ###   ########.fr       */
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
		j = read(fd, buffer, 1);
		if (buffer[0] == '\n')
			i++;
		if (j == -1)
		{
			free(buffer);
			return (i);
		}
	}
	i++;
	free(buffer);
	close(fd);
	return (i);
}

char *ft_buffer_init(char *buffer)
{
	buffer =  (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (buffer == NULL)
		return (NULL);
	return (buffer);
}

char **ft_ret_init(char **ret, int i)
{
	ret = ft_calloc(sizeof(char *), i + 1);
	if (ret == NULL)
		return (NULL);
	return (ret);
}

char **ft_fill_tab(char **tab, int fd, char *buffer)
{
	int j;
	int i;

	j = 1;
	i = 0;	
	while (j != 0)
	{
		j = read(fd, buffer, 34);
		if (j == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[j] = '\0';
		tab[i] = ft_strdup(buffer);
		i++;
	}
	free(buffer);
	printf("i == %d\n", i );
	return (tab);
}

char **new_gnl(int fd, char *argv)
{
    char *buffer;
	char **ret;
	int i;
	int j;

	j = 1;
	buffer = NULL;
	ret = NULL;
    buffer = ft_buffer_init(buffer);
	i = ft_return_size_of_file(argv);
	ret = ft_ret_init(ret, i);
	ret = ft_fill_tab(ret, fd, buffer);
	return (ret);
}