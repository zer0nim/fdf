# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emarin <emarin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/25 11:19:29 by emarin            #+#    #+#              #
#    Updated: 2017/12/16 13:41:31 by emarin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_NAME = fdf.c \
			ft_lstpushback.c \
			ft_printmap.c \
			ft_getcoord.c \
			ft_draw_line.c \
			ft_matrix.c \
			ft_camera.c \
			ft_abs.c \
			ft_invertmatrix.c \
			ft_atoi_base.c \
			ft_lookat.c \
			ft_projec.c \
			ft_utils_map.c \
			ft_vector.c \
			ft_free_param.c \
			ft_fly.c \
			ft_commonmatrix.c \
			ft_key_mode.c \
			get_next_line.c

SRC_PATH = src

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

FLAGS = -Wall -Wextra -Werror

LIBFT = -L./libft -lft

MLX = -lmlx -framework OpenGL -framework AppKit

HEADERS = -I ./

all: compile

compile:
	@$(MAKE) -C libft
	@$(MAKE) $(NAME)

$(NAME): $(OBJ) libft/libft.a
	gcc -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c fdf.h
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc -c $(FLAGS) -o $@ -c $<

clean:
	make -C libft/ clean
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
