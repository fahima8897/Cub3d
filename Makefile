# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 16:11:35 by fboumell          #+#    #+#              #
#    Updated: 2022/05/13 11:08:03 by fboumell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS	= main.c \
		utils.c \

OBJS = ${SRCS:.c=.o}

CC = clang

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

$(NAME) : $(OBJS)
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}
	
%.o:%.c
	${CC} ${FLAGS} -o $@ -c $<

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : clean fclean re