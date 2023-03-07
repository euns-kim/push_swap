# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 14:17:41 by eunskim           #+#    #+#              #
#    Updated: 2023/03/07 22:18:47 by eunskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

#//= Mandatory part =//#
NAME 				:= push_swap
CFLAGS 				:= -fsanitize=address -g3 -Wextra -Wall -Werror

LIBFT				:= lib/libft
LIBGNL				:= lib/get_next_line
LIBC				:= $(LIBFT)/libft.a
GNL					:= $(LIBGNL)/get_next_line.a

INC_DIR				:= inc
HEADERS				:= -I $(LIBFT) -I $(LIBGNL) -I $(INC_DIR)

SRC_DIR_ESSENTIAL	:= src_essential
SRCS_ESSENTIAL		:= $(addprefix $(SRC_DIR_ESSENTIAL)/, \
						parse_and_error_check.c \
						input_parsing_utils.c \
						push_swap_utils.c \
						test_printing.c \
						operations.c \
						double_operations.c \
						queue.c \
						command.c)
OBJS_ESSENTIAL 		:= $(SRCS_ESSENTIAL:.c=.o)						

SRC_DIR_MANDATORY 	:= src_mandatory
SRCS_MANDATORY 		:= $(addprefix $(SRC_DIR_MANDATORY)/, \
						push_swap.c)
OBJS_MANDATORY 		:= $(SRCS_MANDATORY:.c=.o)

#//= Bonus part =//#
NAME_BONUS 			:= checker

SRC_DIR_BONUS 		:= src_bonus
SRCS_BONUS 			:= $(addprefix $(SRC_DIR_BONUS)/, \
						checker.c \
						read_command.c \
						is_sorted.c)
OBJS_BONUS 			:= $(SRCS_BONUS:.c=.o)

#//= Make Rules =//#
all: libft $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

libgnl:
	@$(MAKE) -C $(LIBGNL)

$(NAME): $(OBJS_ESSENTIAL) $(OBJS_MANDATORY)
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS_ESSENTIAL) $(OBJS_MANDATORY) $(LIBC) -o $(NAME) && \
	echo "$(MAGENTA)$(BOLD)>> Mandatory part - push_swap$(RESET)" && \
	echo "$(BLUE)$(BOLD)Compilation successful!$(RESET)"

bonus: libft libgnl $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_ESSENTIAL) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS_ESSENTIAL) $(OBJS_BONUS) $(LIBC) $(GNL) -o $(NAME_BONUS) && \
	echo "$(GREEN)$(BOLD)>> Bonus part - checker$(RESET)" && \
	echo "$(BLUE)$(BOLD)Compilation successful!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ 

clean:
	@rm -f $(OBJS_ESSENTIAL)
	@rm -f $(OBJS_MANDATORY)
	@rm -f $(OBJS_BONUS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBGNL) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@rm -f $(LIBC)
	@rm -f $(GNL)

re: fclean all

.PHONY: all, bonus, clean, fclean, re, libft, libgnl
