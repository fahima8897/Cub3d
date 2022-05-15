/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:26:46 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/15 08:00:16 by user42           ###   ########.fr       */
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
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
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
void	*ft_memmove_2(void *dst, void *src, int len);
int     ft_strlen_2(char *s);
char	*ft_strjoin_2(char *s1, char *s2);
int		ft_strchr_2(char *s);
char	*ft_get_line(char *str);
char	*ft_get_char(char *str);

#endif