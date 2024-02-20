# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 05:51:01 by lvincent          #+#    #+#              #
#    Updated: 2024/02/20 06:35:26 by lvincent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[1;32m

RED = \033[1;31m

RESET = \033[0m

CC 		=	clang

FLAGS 	=	-Wall -Wextra -Werror
NAME 	=	cub3d

SRC_DIR = src

OBJ_DIR = obj

SRC 	=	src/main.c \
			src/parser/parser_interior.c src/parser/parser_index_color.c src/parser/parser_main.c\
			src/parser/parser_exterior.c src/parser/parser_index_textures.c src/parser/parser_map.c\
			src/parser/parser_check_textures.c\
			src/utils/utils_misc.c src/utils/utils_error.c

OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo -e "$(GREEN)CUB3D [Compiling ...]$(RESET) $<"
	@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): dependencies $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -L./libft -lft ./MacroLibX/libmlx.so -lSDL2 -o $(NAME)
	@echo -e "$(GREEN)[Executable created]"

dependencies:
	@make -s --no-print-directory -C libft
	@make -s --no-print-directory -C MacroLibX

clean:
	@make fclean --no-print-directory -C libft
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@echo -e "$(RED)[Executable deleted]$(RESET)"

clean_mlx:
	@make fclean --no-print-directory -C libft
	@make fclean --no-print-directory -C MacroLibX
	@rm -rf $(OBJ)

fclean_mlx:
	@rm -rf $(NAME)
	@echo -e "$(RED)[Programe deleted]$(RESET)"

re_mlx: fclean_mlx all

re: fclean all

debug: FLAGS += -g
debug: $(OBJ)
	@make debug -s --no-print-directory -C libft
	#@make -s --no-print-directory -C MacroLibX
	@$(CC) $(FLAGS) $(OBJ) -L./libft -lft -o $(NAME)
	@echo -e "\n$(GREEN)[executable created]$(RESET)"

.PHONY: all clean fclean re