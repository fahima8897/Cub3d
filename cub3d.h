/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:38:43 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/16 16:15:29 by fboumell         ###   ########.fr       */
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
# include "libft/libft.h"

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

typedef struct s_map
{
	char	**map;
	int		fd;
	int		count_line;
}	t_map;

typedef struct s_verif
{
	long long	no;
	long long	so;
	long long	we;
	long long	ea;
	long long	f;
	long long	c;
}	t_verif;

	/* returns */
# define SUCCESS 0
# define FAILURE -1

	/* utils.c */
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
t_verif	ft_verif_init(void);
int		ft_check_map_content(char **map);
int		check_compo_map(char **map);
int		check_opt_argv_map(char *argv);
void	ft_create_map(char *av);

	/* main.c */
int		check_extension(char *av);
int		check_directory(char *av);
int		check_file_existence(char *av);
void	check_arguments(int ac, char *av);
int		main(int ac, char **av);

	/*new_gnl.c*/
// char	**new_gnl(int fd, char *argv);
char	**ft_fill_tab(char **tab, int fd, char *buffer);
char	**ft_ret_init(char **ret, int i);
int		ft_return_size_of_file(char *argv);
char	*ft_buffer_init(char *buffer);
char	**ft_ret_init(char **ret, int i);

#endif
