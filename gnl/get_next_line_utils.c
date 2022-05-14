/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:25:45 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/14 18:43:46 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*int	ft_strlen(const char *s)
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

	len = ft_strlen(s);
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

void	*ft_memmove(char *save, char *buf, int n)
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
	len = ft_strlen(save) + ft_strlen(buf);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	ft_memmove(cpy, save, ft_strlen(save));
	ft_memmove(cpy + ft_strlen(save), buf, ft_strlen(buf));
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	join;

	len_s2 = ft_strlen(s2);
	len_s1 = ft_strlen(s1);
	join = len_s1 + len_s2 + 1;
	if (!s1 && !s2)
		return (0);
	str = (char *)malloc(sizeof(char *) * (join));
	if (str == NULL)
		return (0);
	ft_memmove(str, s1, len_s1);
	ft_memmove(str + len_s1, s2, len_s2);
	str[join - 1] = '\0';
	free((char *)s1);
	return (str);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s2;
	char		*s1;
	const char	*s;
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*src2;

	i = 0;
	dest = dst;
	src2 = src;
	if (dest == NULL && src2 == NULL)
		return (NULL);
	while (i < n)
	{
		dest[i] = src2[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *s)
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

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (src[len])
		len++;
	str = (char*)malloc(sizeof(*str) * (len + 1));
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}
