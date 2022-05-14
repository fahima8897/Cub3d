/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:38:43 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/14 17:03:29 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	int		win_height;
	int		win_width;
}	t_data;

	/* returns */
# define SUCCESS 0
# define FAILURE -1

	/* utils.c */
int		ft_strcmp(char *s1, char *s2);
int		parse(char *av);
void	ft_free_tab(char **str);


	/* window.c */
void	loop(t_data data);
int		close_escape(int keycode, t_data *data);
int		close_redx(t_data *data);
int		init_window(t_data *data);

	/*write_error.c */
void	write_errors(char *error_str);

	/*check_opt_argv.c*/
void	check_opt_argv_map(char *argv);
char	**ft_split(char *str, char c);

	/* main.c */
int		check_extension(char *av);
void	check_arguments(int ac, char *av);
int		main(int ac, char **av);

#endif
