# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 16:11:35 by fboumell          #+#    #+#              #
#    Updated: 2022/05/13 15:23:44 by fboumell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS	= main.c \
		utils.c \
		window.c \

OBJS = ${SRCS:.c=.o}

CC = clang

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

FL_MLX = -ldl -lmlx -Lmlx -lm -lXext -lX11

all : ${NAME}

$(NAME) : $(OBJS)
	make -s -C ./mlx
	${CC} ${CFLAGS} -I mlx/libmlx_Linux.a ${SRCS} -o ${NAME} $(FL_MLX)
	
%.o:%.c
	${CC} ${FLAGS} -Imlx -Ibass -I mlx/libmlx_Linux.a -o $@ -c $<

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : clean fclean re