# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 23:09:28 by afalconi          #+#    #+#              #
#    Updated: 2023/08/17 16:55:27 by afalconi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell
LIBFT = ./include/libft
LIB_L = $(LIBFT)/bin/libft.a
LIBS = $(LIB_L)
SRCS =	minishell.c src/check_errors.c src/setup.c src/lx_init.c \
		src/lx_token_ls.c src/lx_create_insert_list.c src/destroy_ls.c\
		src/lx_list_CMD_ARG.c src/builtins.c src/lx_ck_list_token.c \
		src/ps_init.c src/ps_create_insert_list.c src/ex_init.c src/ex_cmd.c \
		src/ex_cl_s.c src/ex_ck_cmd.c src/ex_out.c src/ex_real_cmd.c src/ping.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

all: $(NAME)

$(NAME): $(OBJS)
	@mkdir -p obj
	@mkdir -p bin
	@make -s -C $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) -lncurses -lreadline
	@mv $(OBJS) ./obj
	@mv $(NAME) ./bin

clean:
	@make clean -s -C $(LIBFT)
	@rm -rf obj

fclean: clean
	@make fclean -s -C $(LIBFT)
	@rm -rf bin

re: fclean all
	@make re -s -C $(LIBFT)

.PHONY: all clean fclean re
