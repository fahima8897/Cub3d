/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:38:43 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/13 13:26:19 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

	/* returns */
# define SUCCESS 0
# define FAILURE -1

	/* utils.c */
int		ft_strcmp(char *s1, char *s2);
int		parse(char *av);

	/* main.c */
int		check_extension(char *av);
void	check_file(char *av);
void	check_arguments(int ac, char *av);
int		main(int ac, char **av);

#endif
