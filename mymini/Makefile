# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 23:09:28 by afalconi          #+#    #+#              #
#    Updated: 2023/07/17 01:33:00 by afalconi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell
LIBFT = ./include/libft
LIB_L = $(LIBFT)/bin/libft.a
LIBS = $(LIB_L)
SRCS = minishell.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

all: $(NAME)

$(NAME): $(OBJS)
	@make -s -C $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) -lncurses -lreadline
	mv ./*.o ./obj

clean:
	@make clean -s -C $(LIBFT)
	@rm -rf obj

fclean: clean
	@make fclean -s -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all
	@make re -s -C $(LIBFT)

.PHONY: all clean fclean re
