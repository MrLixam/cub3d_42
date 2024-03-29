# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 15:46:24 by lvincent          #+#    #+#              #
#    Updated: 2024/02/24 17:06:18 by lvincent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors !

GREEN = \033[1;32m

RED = \033[1;31m

YELLOW = \033[1;33m

BLUE = \033[1;34m

RESET = \033[0m

#Sources relative to get_next_line
SRC +=	get_next_line/get_next_line.c get_next_line/get_next_line_init.c \
		get_next_line/get_next_line_mem.c get_next_line/get_next_line_misc.c\
		get_next_line/gnl_full_file.c

#Sources relative to ft_printf
SRC	+=	ft_printf/ft_printf.c ft_printf/ft_printf_utils1.c

#Sources relative file descriptor writing
SRC +=	libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_putchar_fd.c

#Miscellaneous utilities
SRC +=	libft/ft_itoa.c libft/ft_atoi.c libft/ft_split.c libft/ft_calloc.c\
		libft/ft_memcmp.c libft/ft_len_arr.c libft/ft_free_arr.c
		
#Sources relative to single char operations
SRC +=	libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
		libft/ft_isdigit.c libft/ft_isprint.c libft/ft_isspace.c \
		libft/ft_tolower.c libft/ft_toupper.c

#Sources relative to memory manipulation	
SRC	+=	libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_memchr.c

#Sources relative to string manipulation
SRC +=	libft/ft_strchr.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strdup.c libft/ft_strnstr.c \
		libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strrchr.c libft/ft_substr.c libft/ft_strtrim.c \
		libft/ft_strjoin.c libft/ft_strmapi.c libft/ft_striteri.c

#Sources relative to chained lists
SRC +=	libft/ft_lstadd_front.c libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_lstlast.c \
		libft/ft_lstadd_back.c libft/ft_lstclear.c libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstmap.c

OBJ = ${SRC:.c=.o}

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

CC = clang

AR = ar

AR_FLAGS = rc

all : $(NAME)

.c.o:

	@printf "$(GREEN)LIBFT [Compiling ...]$(RESET) $<\n"
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ)
	@printf "\n$(BLUE)[Compiled object files for libft]$(RESET)\n"
	@$(AR) $(AR_FLAGS) $(NAME) $(OBJ)
	@printf "$(YELLOW)[Compiled libft]$(RESET)\n"
	
clean:
	@$(RM) $(OBJ)
	@printf "$(RED)[Removed object files from libft]$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED)[Removed $(NAME)] $(RESET)\n"

re: clean all

debug: CFLAGS += -g
debug: $(NAME)

.PHONY: all clean fclean re debug
