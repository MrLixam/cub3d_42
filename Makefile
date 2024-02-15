# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 05:51:01 by lvincent          #+#    #+#              #
#    Updated: 2024/02/15 21:12:23 by lvincent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		=	clang

FLAGS 	=	-Wall -Wextra -Werror
NAME 	=	cub3d

SRC_DIR = src

OBJ_DIR = obj

SRC 	=	src/main.c \
			src/parser/parser_interior.c src/parser/parser_exterior.c src/parser/parser_color.c src/parser/parser_image.c src/parser/parser_map.c\
			src/utils/utils_misc.c src/utils/utils_error.c

OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -o $@ -c $<
	@echo -en "\\r\033[2K"
	@echo -en "\\r\033[1;33m[compiling...]"$<

all: $(NAME)


$(NAME): $(OBJ)
	@make -s --no-print-directory -C libft
	#@make -s --no-print-directory -C MacroLibX
	@$(CC) $(FLAGS) $(OBJ) -L./libft -lft -o $(NAME)
	@echo -en "\\r\033[2K"
	@echo -e "\033[1;32m[executable created]"


clean:
	@make fclean --no-print-directory -C libft
	@make fclean --no-print-directory -C MacroLibX
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@echo -e "\033[1;32m[Programe deleted]"

re: fclean all

debug: FLAGS += -g
debug: $(OBJ)
	@make debug -s --no-print-directory -C libft
	#@make -s --no-print-directory -C MacroLibX
	@$(CC) $(FLAGS) $(OBJ) -L./libft -lft -o $(NAME)
	@echo -en "\\r\033[2K"
	@echo -e "\033[1;32m[executable created]"

.PHONY: all clean fclean re