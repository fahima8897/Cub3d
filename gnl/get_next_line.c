/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:23:36 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/15 14:25:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#include "get_next_line.h"

static int	ft_search_n(char *save)
{
	int	i;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_get_line(char *save)
{
	int		i;
	int		len;
	char	*cpy;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	len = i + 1;
	cpy = malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && i < len)
	{
		cpy[i] = save[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static char	*ft_after_n(char *save)
{
	unsigned int	i;
	char			*cpy;
	char			*tmp;

	tmp = ft_strchr_2(save, '\n');
	i = ft_strlen_2(tmp);
	cpy = malloc(sizeof(char) * (i + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (tmp[i] != '\0')
	{
		cpy[i] = tmp[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static char	*ft_return(char **save, char **line, int ret)
{
	if (ret == 0 && **line == '\0')
	{	
		free(*line);
		free(*save);
		*save = NULL;
		return (NULL);
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	static char	*save;
	char		*line;
	char		*tmp;

	ret = 1;
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, buf, 0) == -1)
		return (NULL);
	if (save == 0)
		save = ft_strdup_2("\0");
	while (ft_search_n(save) == 0 && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		save = ft_strjoin_2(save, buf);
	}
	line = ft_get_line(save);
	tmp = ft_after_n(save);
	free(save);
	save = ft_strdup_2(tmp);
	free(tmp);
	return (ft_return(&save, &line, ret));
}

/*		MON GET NEXT LINE */	

/*#include "get_next_line.h"

char	*ft_get_char(char *s)
{
	char	*ret;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[len] != '\0' && s[len] != '\n')
		len++;
	if (!s[len])
	{
		free(s);
		return (0);
	}
	ret = (char *)malloc(sizeof(char) * ((ft_strlen(s) - len)) + 1);
	if (ret == 0)
		return (0);
	len++;
	while (s[len] != '\0')
		ret[i++] = s[len++];
	ret[i] = '\0';
	free(s);
	return (ret);
}

char	*ft_get_line(char *s)
{
	char	*ret;
	char	*tmp;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0' && s[len] != '\n')
		len++;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	ret = tmp;
	return (ret);
}

int	ft_read(int fd, char **line)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	return (1);
}

char	*ft_malloc(char *buf)
{
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (buf == NULL)
		return (NULL);
	return (buf);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*str;
	int			i;

	i = 1;
	buf = NULL;
	ft_read(fd, line);
	buf = ft_malloc(buf);
	while (!ft_strchr_2(str) && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (-1);
		}
		buf[i] = '\0';
		str = ft_strjoin_2(str, buf);
	}
	free(buf);
	*line = ft_get_line(str);
//	str = ft_get_char(str);
	if (i == 0)
	{
		free(*line);
		return (0);
	}
	return (1);
}*/