# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 16:11:35 by fboumell          #+#    #+#              #
#    Updated: 2022/05/16 16:45:14 by adaloui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS	= main.c \
		utils.c \
		window.c \
		write_error.c \
		check_opt_argv.c \
		ft_get_map_content.c \
		new_gnl.c \
		libft/*.c \
		gnl/*.c \

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