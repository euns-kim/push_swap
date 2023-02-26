# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 14:17:41 by eunskim           #+#    #+#              #
#    Updated: 2023/02/26 18:06:19 by eunskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= push_swap
CFLAGS 		:= -fsanitize=address -g3 -Wextra -Wall -Werror
LIBFT		:= lib/libft
LIBGNL		:= lib/get_next_line
SRC_DIR 	:= src
HEADERS		:= -I $(LIBFT) -I $(LIBGNL) -I $(SRC_DIR)
LIBC		:= $(LIBFT)/libft.a
GNL			:= $(LIBGNL)/get_next_line.a
SRCS 		:= $(addprefix $(SRC_DIR)/, \
				push_swap.c \
				parse_and_error_check.c \
				input_parsing_utils.c \
				push_swap_utils.c \
				test_printing.c)
OBJS 		:= $(SRCS:.c=.o)

#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

#//= Make Rules =//#
all: libft libgnl $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

libgnl:
	@$(MAKE) -C $(LIBGNL)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(LIBC) $(GNL) -o $(NAME) && \
	echo "$(BLUE)$(BOLD)Compilation successful!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ 

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBGNL) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBGNL) fclean

re: fclean all

.PHONY: all, clean, fclean, re, libft, libgnl
