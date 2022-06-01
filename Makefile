# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 16:11:35 by fboumell          #+#    #+#              #
#    Updated: 2022/06/01 21:23:07 by adaloui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAME_BONUS = cub3D_bonus
BONUS_DIR = bonus/
SRCS_BONUS = bonus/main_bonus.c \
		bonus/utils_bonus.c \
		bonus/window_bonus.c \
		bonus/errors_bonus.c \
		bonus/get_map_content_bonus.c \
		libft/ft_atoi.c \
		libft/ft_bzero.c \
		libft/ft_calloc.c \
		libft/ft_isalnum.c \
		libft/ft_isalpha.c \
		libft/ft_isascii.c \
		libft/ft_isdigit.c \
		libft/ft_isprint.c \
		libft/ft_itoa.c \
		libft/ft_lstadd_back.c \
		libft/ft_lstadd_front.c \
		libft/ft_lstclear.c \
		libft/ft_lstdelone.c \
		libft/ft_lstiter.c \
		libft/ft_lstlast.c \
		libft/ft_lstnew.c \
		libft/ft_lstsize.c \
		libft/ft_memccpy.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_memcpy.c \
		libft/ft_memmove.c \
		libft/ft_memset.c \
		libft/ft_putchar_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_split.c \
		libft/ft_strchr.c \
		libft/ft_strcmp.c \
		libft/ft_strcpy.c \
		libft/ft_strdup.c \
		libft/ft_strjoin.c \
		libft/ft_strlcat.c \
		libft/ft_strlcpy.c \
		libft/ft_strlen.c \
		libft/ft_strlen_tab.c \
		libft/ft_strmapi.c \
		libft/ft_strncmp.c \
		libft/ft_strnstr.c \
		libft/ft_strrchr.c \
		libft/ft_strtrim.c \
		libft/ft_substr.c \
		libft/ft_tolower.c \
		gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		bonus/init_bonus.c \
		bonus/free_bonus.c \
		bonus/check_line_content_bonus.c \
		bonus/utils_check_line_content_bonus.c \
		bonus/utils_check_line_content2_bonus.c \
		bonus/utils_check_map_content_bonus.c \
		bonus/utils_get_all_map_info_bonus.c \
		bonus/check_map_content_bonus.c \
		bonus/get_rest_of_map_bonus.c \
		bonus/t_verif_bonus.c \
		bonus/get_all_map_info_bonus.c \
		bonus/init_player_bonus.c \
		bonus/raycast_bonus.c \
		bonus/draw_bonus.c \
		bonus/create_textures_bonus.c \
		bonus/gameplay_bonus.c \
		bonus/gameplay_camera_bonus.c \
		bonus/gameplay_utils_bonus.c \
		bonus/first_step_parse_bonus.c \
		bonus/second_step_parse_bonus.c \
		bonus/draw_utils_bonus.c \
		bonus/gameplay_camera_mouse_bonus.c \
		bonus/add_sound_bonus.c \

SRCS	= mandatory/main.c \
		mandatory/utils.c \
		mandatory/window.c \
		mandatory/errors.c \
		mandatory/get_map_content.c \
		libft/ft_atoi.c \
		libft/ft_bzero.c \
		libft/ft_calloc.c \
		libft/ft_isalnum.c \
		libft/ft_isalpha.c \
		libft/ft_isascii.c \
		libft/ft_isdigit.c \
		libft/ft_isprint.c \
		libft/ft_itoa.c \
		libft/ft_lstadd_back.c \
		libft/ft_lstadd_front.c \
		libft/ft_lstclear.c \
		libft/ft_lstdelone.c \
		libft/ft_lstiter.c \
		libft/ft_lstlast.c \
		libft/ft_lstnew.c \
		libft/ft_lstsize.c \
		libft/ft_memccpy.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_memcpy.c \
		libft/ft_memmove.c \
		libft/ft_memset.c \
		libft/ft_putchar_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_split.c \
		libft/ft_strchr.c \
		libft/ft_strcmp.c \
		libft/ft_strcpy.c \
		libft/ft_strdup.c \
		libft/ft_strjoin.c \
		libft/ft_strlcat.c \
		libft/ft_strlcpy.c \
		libft/ft_strlen.c \
		libft/ft_strlen_tab.c \
		libft/ft_strmapi.c \
		libft/ft_strncmp.c \
		libft/ft_strnstr.c \
		libft/ft_strrchr.c \
		libft/ft_strtrim.c \
		libft/ft_substr.c \
		libft/ft_tolower.c \
		gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		mandatory/init.c \
		mandatory/free.c \
		mandatory/check_line_content.c \
		mandatory/utils_check_line_content.c \
		mandatory/utils_check_line_content2.c \
		mandatory/utils_check_map_content.c \
		mandatory/utils_get_all_map_info.c \
		mandatory/check_map_content.c \
		mandatory/get_rest_of_map.c \
		mandatory/t_verif.c \
		mandatory/get_all_map_info.c \
		mandatory/init_player.c \
		mandatory/raycast.c \
		mandatory/draw.c \
		mandatory/create_textures.c \
		mandatory/gameplay.c \
		mandatory/gameplay_camera.c \
		mandatory/gameplay_utils.c \
		mandatory/first_step_parse.c \
		mandatory/second_step_parse.c \
		mandatory/draw_utils.c \

OBJS = ${SRCS:.c=.o}
BONUS_OBJ = ${SRCS_BONUS:.c=.o}

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

bonus: ${NAME_BONUS}

$(NAME_BONUS) : $(BONUS_OBJ)
	@make --no-print-directory -s -C ./mlx
	@make --no-print-directory -C $(LIBFT_DOSSIER)
	${CC} ${CFLAGS} $(LIBFT) -I mlx/libmlx_Linux.a ${SRCS_BONUS} -o ${NAME_BONUS} $(FL_MLX)

clean_bonus :
	${RM} ${BONUS_OBJ}
	@make --no-print-directory -C $(LIBFT_DOSSIER) clean

fclean_bonus : clean_bonus
	${RM} ${NAME_BONUS}
	@make --no-print-directory -C $(LIBFT_DOSSIER) fclean

re_bonus : fclean_bonus bonus

.PHONY : all clean fclean re bonus clean_bonus fclean_bonus