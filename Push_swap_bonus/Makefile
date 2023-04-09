# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 15:20:41 by lde-mich          #+#    #+#              #
#    Updated: 2023/04/03 11:57:47 by adi-stef         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	= $(wildcard src/*.c)

OBJS	= $(SRCS:%.c=%.o)

CC		= clang
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

%.o:%.c
	@$(CC) $(FLAG) -c $< -o $@
	@printf "\033[1;33mCompiling... %-33.33s\r\033[0m" $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -O2 $(OBJS) push_swap.c -o $(NAME)
	@echo "\033[1;32m$(NAME) created successfully\033[0m"

all: $(NAME)

bonus: $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) checker.c -o checker
	@echo "\033[1;32mchecker created successfully\033[0m"

clean:
	@echo "\033[1;31mRemoving object files...\033[0m"
	@$(RM) $(OBJS)

fclean: clean
	@echo "\033[1;31mRemoving program executable...\033[0m"
	@$(RM) $(NAME)
	@$(RM) checker

re: fclean $(NAME) bonus

.PHONY: all clean fclean re bonus

