# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 05:51:01 by lvincent          #+#    #+#              #
#    Updated: 2024/02/24 17:05:56 by lvincent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[1;32m

RED = \033[1;31m

RESET = \033[0m

CC 		=	clang

FLAGS 	=	-Werror -Wall -Wextra
NAME 	=	cub3D

LIBFT = libft/libft.a

MLX = MacroLibX/libmlx.so

SRC_DIR = src

OBJ_DIR = obj

SRC 	=	src/main.c \
			src/parser/parser_interior.c src/parser/parser_index_color.c src/parser/parser_main.c\
			src/parser/parser_exterior.c src/parser/parser_index_textures.c src/parser/parser_map.c\
			src/parser/parser_check_textures.c src/utils/utils_parser.c\
			src/utils/utils_misc.c src/utils/utils_error.c src/utils/utils_graphics.c\
			src/utils/parser_to_render.c src/utils/parser_to_render_img.c src/utils/utils_color.c\
			src/render/mlx_core.c src/render/mlx_fonction.c src/render/mlx_hook.c\
		   	src/render/raycaster.c src/render/ray_line.c src/render/mlx_hook2.c\

OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@printf "$(GREEN)CUB3D [Compiling ...]$(RESET) $<\n"
	@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(MLX) -lSDL2 -lm -o $(NAME)
	@printf "$(GREEN)[Executable created]\n"

$(LIBFT):
	@make -s --no-print-directory -C libft -j

$(MLX):
	@make -s --no-print-directory -C MacroLibX -j

clean:
	@make fclean --no-print-directory -C libft
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@printf "$(RED)[Executable deleted]$(RESET)\n"

clean_mlx:
	@make fclean --no-print-directory -C libft
	@make fclean --no-print-directory -C MacroLibX
	@rm -rf $(OBJ)

fclean_mlx: clean_mlx
	@rm -rf $(NAME)
	@printf "$(RED)[Program deleted]$(RESET)\n"

re_mlx: fclean_mlx all

re: fclean all

debug: FLAGS += -g
debug: $(MLX) $(OBJ)
	@make debug --no-print-directory -C libft -j
	@$(CC) $(FLAGS) $(OBJ) -L./libft -lft ./MacroLibX/libmlx.so -lSDL2 -lm -o $(NAME)
	@printf "$(GREEN)[DEBUG Executable created]$(RESET)\n"

.PHONY: all clean fclean re debug
