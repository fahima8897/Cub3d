/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:38:43 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/18 16:36:20 by fboumell         ###   ########.fr       */
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

typedef struct s_map
{
	char	**map;
	int		fd;
	int		count_line;
	int		is_map;
	int		map_begin_line;
	int		map_end_line;
	int		x;
	int		y;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	int		win_height;
	int		win_width;
	t_map	*map;
}	t_data;

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
char	*strdup_no_n(const char *s1);
int		check_digit(char *str);
int		check_digit_size(int nb);
int		strlen_tab(char **str);

	/* free.c */
void	free_tab(char **str);
void	free_struct(t_map *map);
void	free_data(t_data *data);

	/* window.c */
void	loop(t_data *data);
int		close_escape(int keycode, t_data *data);
int		close_redx(t_data *data);
int		init_window(t_data *data);

	/* error.c */
void	write_errors(char *error_str);
int		return_failure(char *error_str);
int		ret_free(char *error_str, char **tab);
int		ret_free2(char *error_str, char **tab, char*tmp);

	/* check_opt_argv.c */
t_verif	verif_init(void);
int		check_map_content(t_map *map);
int		check_compo_map(char **map);
int		check_opt_argv_map(char *argv, t_data *data);
t_verif	verif_init(void);
int		check_line_content(t_map *map);

	/* main.c */
int		check_extension(char *av);
int		check_directory(char *av);
int		check_file_existence(char *av);
void	check_arguments(int ac, char *av);
int		main(int ac, char **av);

// 	/*new_gnl.c*/
// // char	**new_gnl(int fd, char *argv);
// char	**ft_fill_tab(char **tab, int fd, char *buffer);
// char	**ft_ret_init(char **ret, int i);
// int		ft_return_size_of_file(char *argv);
// char	*ft_buffer_init(char *buffer);
// char	**ft_ret_init(char **ret, int i);

	/* get_map_content.c */
t_map	*count_line(char *s, t_data *data);
void	fill_map(int row, int column, int i, t_map *map);
t_map	*create_map(char *av, t_data *data);

	/* init.c */
void	init_data(t_data *data);

	/* check_line_content.c */
int		check_verif_content(char *str, t_verif *check);
int		compare_and_open_line(char **split_byspace, t_verif *check, char *tmp);
int		compare_and_check_number_line(char **split_byspace, t_verif *check);
int		check_filled_lines(char **map, t_verif *check);
int		check_line_content(t_map *map);

	/* utils_check_line_content.c */
int		reduce_check_filled_lines(char **split_byspace, char *tmp);
int		reduce_compare_and_check_line_f(char *split_byspace);
int		reduce_compare_and_check_line_c(char *split_byspace);

	/* t_verif.c */
t_verif	verif_init(void);
int		check_verif(t_verif tab);
int		check_verif_2(t_verif tab);

#endif
