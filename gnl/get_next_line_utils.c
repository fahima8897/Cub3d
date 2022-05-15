/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:25:45 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/15 07:59:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*int	ft_strlen_2( char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		len;

	len = ft_strlen_2(s);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	len = 0;
	while (s[len])
	{
		cpy[len] = s[len];
		len++;
	}
	cpy[len] = '\0';
	return (cpy);
}

void	*ft_memmove_2(char *save, char *buf, int n)
{
	char	tmp;
	int		i;

	i = 0;
	if (!save && !buf)
		return (NULL);
	if (save > buf)
	{
		while (n > 0)
		{
			tmp = buf[n - 1];
			save[n - 1] = tmp;
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			save[i] = buf[i];
			i++;
		}
	}
	return (save);
}

char	*ft_strjoin(char *save, char *buf)
{
	char	*cpy;
	int		len;

	if (!save && !buf)
		return (NULL);
	len = ft_strlen_2(save) + ft_strlen_2(buf);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	ft_memmove_2(cpy, save, ft_strlen_2(save));
	ft_memmove_2(cpy + ft_strlen_2(save), buf, ft_strlen_2(buf));
	cpy[len] = '\0';
	free(save);
	return (cpy);
}

char	*ft_strchr(char *save, int c)
{
	while (*save != '\0' && *save != (char)c)
		save++;
	if (*save == (char)c && *save != '\0')
		return (save + 1);
	else if (*save == '\0')
		return (save);
	return (NULL);
}*/

/*		mon get next line utils */

char	*ft_strjoin_2( char *s1,  char *s2)
{
	char	*str;
	int	len_s1;
	int	len_s2;
	int	join;

	len_s2 = ft_strlen_2(s2);
	len_s1 = ft_strlen_2(s1);
	join = len_s1 + len_s2 + 1;
	if (!s1 && !s2)
		return (0);
	str = (char *)malloc(sizeof(char *) * (join));
	if (str == NULL)
		return (0);
	ft_memmove_2(str, s1, len_s1);
	ft_memmove_2(str + len_s1, s2, len_s2);
	str[join - 1] = '\0';
	free((char *)s1);
	return (str);
}

void	*ft_memmove_2(void *dst,  void *src, int len)
{
	 char	*s2;
	char		*s1;
	 char	*s;
	char		*d;

	s = src;
	d = dst;
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		s1 = d + (len - 1);
		s2 = s + (len - 1);
		while (len--)
			*s1-- = *s2--;
	}
	return (dst);
}

int	ft_strlen_2(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr_2(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}
