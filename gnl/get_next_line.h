/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:26:46 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/14 18:43:54 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s);
void	*ft_memmove(char *save, char *buf, int n);
char	*ft_strjoin(char *save, char *buf);
char	*ft_strchr(char *save, int c);

#endif
*/

/* mon .h*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../cub3d.h"

# define BUFFER_SIZE 1

int		get_next_line(int fd, char **line);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strchr(char *s);
char	*ft_get_line(char *str);
char	*ft_get_char(char *str);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *src);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);

#endif