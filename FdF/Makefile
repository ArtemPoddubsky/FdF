# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lholdo <lholdo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 16:11:05 by lholdo            #+#    #+#              #
#    Updated: 2021/10/25 16:31:22 by lholdo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

FLAGS = -MMD -Wall -Werror -Wextra -g3

MINILIBX = ./minilibx_macos/

DIR_S = ./

DIR_O = ./obj

SOURCES = color.c controls.c copy.c fdf_utils.c fdf.c projection.c read_map.c utils.c mouse.c draw.c draw_utils.c iso_and_rotate.c reallocation.c read_map_utils.c free.c gnl/gnl.c gnl/gnl_util_1.c gnl/gnl_util_2.c gnl/gnl_1.c gnl/gnl_1_utils_1.c gnl/gnl_1_utils_2.c

OBJS = $(addprefix $(DIR_O)/,${SOURCES:.c=.o})

LIBFT = ./libft/

LIB = ./libft/libft.a

all: dir lib libmlx.a $(NAME)

dir:
	@echo "\033[92mCreating directory...\033[0m"
	@mkdir -p obj
	@mkdir -p obj/gnl

$(DIR_O)/%.o: $(DIR_S)/%.c
	$(CC) $(FLAGS) -c $< -o $@ -g

lib:
	@echo "\033[92mMaking libft...\033[0m"
	@make -C $(LIBFT)

libmlx.a:
	@echo "\033[92mMaking minilibx...\033[0m"
	@make -C $(MINILIBX)
	@cp $(MINILIBX)/libmlx.a .

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $(NAME) $(LIB) -L $(MINILIBX) libmlx.a -framework OpenGL -framework AppKit -g
	@echo "\033[92mReady.\033[0m"

clean:
	@echo "\033[0;35mУдаляю объектные файлы...\033[0;31m"
	@rm -rf $(DIR_O)
	@make clean -C $(MINILIBX)
	@make clean -C $(LIBFT)

fclean: clean
	@echo "\033[0;35mУдаляю исполняемый файл...\033[0;31m"
	@rm -f $(NAME)
	@rm -f libmlx.a
	@make clean -C $(MINILIBX)
	@make clean -C $(LIBFT)

re: fclean all

.PHONY: all lib libmlx.a clean fclean re

-include $(OBJS:.o=.d)