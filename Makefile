# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 16:11:35 by fboumell          #+#    #+#              #
#    Updated: 2022/05/29 18:10:41 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS	= main.c \
		utils.c \
		window.c \
		errors.c \
		check_opt_argv.c \
		get_map_content.c \
		libft/*.c \
		gnl/*.c \
		init.c \
		free.c \
		check_line_content.c \
		utils_check_line_content.c \
		utils_check_line_content2.c \
		check_map_content.c \
		get_rest_of_map.c \
		t_verif.c \
		get_all_map_info.c \
		init_player.c \
		raycast.c \
		draw.c \
		create_textures.c \
		gameplay.c \
		

OBJS = ${SRCS:.c=.o}

CC = clang

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

FL_MLX = -ldl -lmlx -Lmlx -lm -lXext -lX11

LIBFT_A = libft.a
LIBFT_DOSSIER = libft/
LIBFT  = $(addprefix $(LIBFT_DOSSIER), $(LIBFT_A))

all : ${NAME}

$(NAME) : $(OBJS)
	@make --no-print-directory -s -C ./mlx
	@make --no-print-directory -C $(LIBFT_DOSSIER)
	${CC} ${CFLAGS} $(LIBFT) -I mlx/libmlx_Linux.a ${SRCS} -o ${NAME} $(FL_MLX)
	
%.o:%.c
	${CC} ${FLAGS} -Imlx -Ibass -I mlx/libmlx_Linux.a -o $@ -c $<

clean :
	${RM} ${OBJS}
	@make --no-print-directory -C $(LIBFT_DOSSIER) clean

fclean : clean
	${RM} ${NAME}
	@make --no-print-directory -C $(LIBFT_DOSSIER) fclean

re : fclean all

.PHONY : clean fclean re