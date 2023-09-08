# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 23:09:28 by afalconi          #+#    #+#              #
#    Updated: 2023/09/08 03:11:16 by afalconi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell
LIBFT = ./include/libft
LIB_L = $(LIBFT)/bin/libft.a
LIBS = $(LIB_L)
SRCS =	minishell.c src/check_errors.c src/setup.c src/lx_init.c \
		src/lx_token_ls.c src/lx_create_insert_list.c src/destroy_ls.c\
		src/lx_list_CMD_ARG.c src/builtins.c src/lx_ck_list_token.c \
		src/ps_init.c src/ex_init.c src/ex_cmd.c src/ex_cl_s.c \
		src/ex_ck_cmd.c src/ex_out_app.c src/ex_real_cmd.c src/ping.c\
		src/ps_redirection_setup.c src/ex_ck_redirection.c src/ex_inp_hdoc.c \
		src/lx_remove_usleschar.c src/lx_set_redirection.c src/ex_or.c
OBJS = $(SRCS:.c=.o)
CC = gcc -g
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
