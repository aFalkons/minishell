# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 23:09:28 by afalconi          #+#    #+#              #
#    Updated: 2023/10/07 15:04:03 by afalconi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell
LIBFT = ./include/libft
LIB_L = $(LIBFT)/bin/libft.a
LIBS = $(LIB_L)
SRCS =	minishell.c src/check_errors.c src/setup.c src/lexical/lx_init.c \
		src/lexical/lx_token_ls.c src/lexical/lx_create_insert_list.c src/destroy_ls.c\
		src/lexical/lx_list_CMD_ARG.c src/lexical/lx_ck_list_token.c \
		src/parser/ps_init.c src/executor/ex_init.c src/executor/ex_cmd.c src/executor/ex_cl_s.c \
		src/executor/ex_ck_cmd.c src/executor/ex_out_app.c src/executor/ex_real_cmd.c src/ping.c\
		src/parser/ps_redirection_setup.c src/executor/ex_ck_redirection.c src/executor/ex_inp_hdoc.c \
		src/lexical/lx_remove_usleschar.c src/lexical/lx_set_redirection.c src/executor/ex_or.c\
		src/executor/ex_pipe.c src/parser/ps_handler_HDOC.c src/parser/ps_pipe_setup.c\

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -Iinclude

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
