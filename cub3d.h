/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:38:43 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/29 21:39:29 by user42           ###   ########.fr       */
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
# include <math.h>

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

# define NO 0
# define SO 1
# define WE 2
# define EA 3

typedef struct s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		height;
	int		width;
	int		endian;
	int		line;
	int		status;
}				t_img;

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
}	t_map_info;

typedef struct s_gameplay
{
	int forward;
	int backward;
	int left;
	int right;
	int look_left;
	int look_right;
	int escape;
}		t_gameplay;

typedef struct s_player
{
	char	p_dir;
	t_coord	p_pos;
	t_coord	dir_pos;
	t_coord	plane_pos;
	t_gameplay gamplay;
}		t_player;

typedef struct s_map
{
	char		**map;
	char		**map_2;
	int			fd;
	int			count_line;
	t_player	player;
	int			space_in_map_2;
}	t_map;

typedef struct s_ray
{
	t_coord		dir;
	t_coord		map;
	int			mapx;
	int			mapy;
	t_coord		delta_dist;
	t_coord		side_dist;
	t_coord		cam;
	int			hit;
	int			stepx;
	int			stepy;
	int			side;
	double		wall_dist;
	int			line_height;
	int			wall_start;
	int			wall_end;
	double		wall_x;
}				t_ray;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	int			win_height;
	int			win_width;
	t_map		*map;
	t_map_info	*map_info;
	t_img		tx;
	t_ray		ray;
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
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

/*		init_player.c		*/
void	init_player(t_data *data, int x, int y, char dir);

/*		raycats.c		*/
int		draw(t_data *data);

/*		draw.c		*/
void	put_in_display(t_data *data, int x);

/*		create_texture.c		*/
int create_textures_wall(t_data *data);
/* GERER LES ERREURS DANS LE CAS OU !TXT.IMG ou !TXT_ADDR*/

/*		gameplay.c		*/
int	keyboard_gameplay(t_data *data);

#endif
