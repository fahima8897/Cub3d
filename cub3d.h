/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:38:43 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/21 09:46:16 by user42           ###   ########.fr       */
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

typedef struct s_map_info
{
	int		f_red;
	int		f_green;
	int		f_blue;
	int		c_red;
	int		c_green;
	int		c_blue;
	char	*no_texture;
	char	*so_texture;
	char	*ea_texture;
	char	*we_texture;
	void	*mlx_no;
	void	*mlx_so;
	void	*mlx_ea;
	void	*mlx_we;
}	t_map_info;

typedef struct s_map
{
	char	**map;
	char	**map_2;
	int		fd;
	int		count_line;
	int		player;
	int		space_in_map_2;
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	int			win_height;
	int			win_width;
	t_map		*map;
	t_map_info	*map_info;
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
void	free_map_info(t_map_info *map_info, t_data *data);

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
int		check_opt_argv_map(char *argv, t_data *data);
int		check_line_content(t_map *map);

	/* main.c */
int		check_extension(char *av);
int		check_directory(char *av);
int		check_file_existence(char *av);
void	check_arguments(int ac, char *av);
int		main(int ac, char **av);

	/* get_map_content.c */
int		check_get_next_line(char *line);	
t_map	*reduce_count_line(t_data *data, int fd);
t_map	*count_line(char *s, t_data *data);

	/* init.c */
void	init_data(t_data *data);

	/* check_line_content.c */
int		check_verif_content(char *str, t_verif *check);
int		compare_and_open_line(char **split_byspace, t_verif *check, char *tmp);
int		compare_and_check_number_line(char **split_byspace, t_verif *check);
int		check_filled_lines(char **map, t_verif *check);
int		check_line_content(t_map *map);

	/* utils_check_line_content.c */
int		reduce_check_filled_lines(char **split_byspace);
int		reduce_compare_and_check_line_f(char *split_byspace);
int		reduce_compare_and_check_line_c(char *split_byspace);

	/* utils_check_line_content2.c */
int		check_no(t_verif *check, char *tmp);
int		check_so(t_verif *check, char *tmp);
int		check_we(t_verif *check, char *tmp);
int		check_ea(t_verif *check, char *tmp);

	/* check_map_content.c	*/
int		check_map_content_characters(t_data *data);
int		check_forbidden_character(char **map);

	/*get_rest_of_the_map.c	*/
int		check_get_next_line2(char *line);
int		reduce_return_size_of_map(int fd);
int		return_size_of_file(char *s);
t_map	*count_line_for_map(char *s, t_data *data);

	/* t_verif.c */
t_verif	verif_init(void);
int		check_verif(t_verif tab);
int		check_verif_2(t_verif tab);

/*		get_all_map_info.c		*/
t_map_info	*get_all_map_info(t_data *data);

#endif
