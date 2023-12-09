# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 23:09:28 by afalconi          #+#    #+#              #
#    Updated: 2023/12/01 23:23:25 by afalconi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= bin/minishell
LIBFT		= ./include/libft
LIB_L		= $(LIBFT)/bin/libft.a
LIBS		= $(LIB_L)
BUILTINS	= ./src/builtins
EXECUTOR	= ./src/executor
EXPANSION	= ./src/expansion
LEXICAL		= ./src/lexical
PARSER		= ./src/parser
WILDCARD	= ./src/wildcard

SRCS =	minishell.c \
		src/check_errors.c \
		src/setup.c \
		src/destroy_ls.c \
		\
		$(LEXICAL)/lx_set_redirection.c $(LEXICAL)/lx_list_CMD_ARG.c \
		$(LEXICAL)/lx_ck_list_token.c $(LEXICAL)/lx_init.c \
		$(LEXICAL)/lx_token_ls.c $(LEXICAL)/lx_create_insert_list.c \
		\
		$(PARSER)/ps_pipe_setup.c $(PARSER)/ps_handler_HDOC.c \
		$(PARSER)/ps_init.c $(PARSER)/ps_redirection_setup.c \
		\
		$(EXECUTOR)/ex_init.c $(EXECUTOR)/ex_cmd.c\
		$(EXECUTOR)/ex_ck_redirection.c $(EXECUTOR)/ex_inp_hdoc.c \
		$(EXECUTOR)/ex_real_cmd.c src/ping.c $(EXECUTOR)/ex_pipe.c \
		$(EXECUTOR)/ex_ck_cmd.c $(EXECUTOR)/ex_out_app.c \
		\
		$(BUILTINS)/cd/bl_cd.c $(BUILTINS)/cd/bl_cd_utils.c \
		$(BUILTINS)/echo/bl_echo.c $(BUILTINS)/env/bl_env.c \
		$(BUILTINS)/exit/bl_exit.c $(BUILTINS)/pwd/bl_pwd.c \
		$(BUILTINS)/export/bl_export_add_node.c \
		$(BUILTINS)/export/bl_export_case_egual_sign.c \
		$(BUILTINS)/export/bl_export_update_node.c \
		$(BUILTINS)/export/bl_export_utils_array.c \
		$(BUILTINS)/export/bl_export_utils_list_1.c \
		$(BUILTINS)/export/bl_export_utils_list_2.c \
		$(BUILTINS)/export/bl_export_utils.c $(BUILTINS)/export/bl_export.c \
		$(BUILTINS)/unset/bl_unset.c $(BUILTINS)/unset/bl_unset_utils.c \
		\
		$(EXPANSION)/expansion.c $(EXPANSION)/expansion_utils.c \
		$(EXPANSION)/expansion_cases.c $(EXPANSION)/expansion_replace.c \
		$(EXPANSION)/question_mark/ft_add_last_exit_to_array.c \
		\
		$(WILDCARD)/wildcard.c $(WILDCARD)/wildcard_utils.c \

OBJS		=	$(addprefix obj/, $(notdir $(SRCS:.c=.o)))
VPATH		=	$(sort $(dir $(SRCS)))
CC			=	gcc
CFLAGS		=	-g -Wall -Wextra -Werror -Iinclude
BIN_DIR		=	bin


RED			=	\033[0;31m
YELLOW		=	\033[93m
ORANGE		=	\033[38;5;208m
GREEN		=	\033[32m
RESET		=	\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo .
	@echo "$(YELLOW)compiling...$(RESET)"
	@make -s -C $(LIBFT)
	@echo .
	@echo "$(YELLOW)compiling...$(RESET)"
	@if [ ! -d $(BIN_DIR) ]; then mkdir -p $(BIN_DIR); fi
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) -lncurses -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include
	@echo .
	@echo "$(YELLOW)compiling...$(RESET)"
	@echo .
	@echo "$(GREEN)minishell is ready$(RESET)"

obj/%.o: %.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "."
	@make clean -s -C $(LIBFT)
	@rm -rf obj
	@sleep 0.5
	@echo "$(RED)the object files have been removed$(RESET)"

fclean: clean
	@echo "."
	@make fclean -s -C $(LIBFT)
	@rm -rf bin
	@sleep 0.5
	@echo "$(ORANGE)the executable has been removed$(RESET)"

re: fclean all
	@make re -s -C $(LIBFT)

.PHONY: all clean fclean re
