# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 23:56:29 by afalconi          #+#    #+#              #
#    Updated: 2023/09/06 05:13:12 by afalconi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRCS	=	src/ft_strlen.c src/ft_calloc.c src/ft_exit.c src/ft_strndup.c \
			src/ft_putstr_fd.c src/ft_print_message.c src/ft_strlcpy.c \
			src/ft_strncmp.c src/ft_strdup.c src/ft_strjoin.c \
			src/ft_count_char_split.c src/ft_split.c src/ft_substr.c \
			src/ft_contchar.c src/ft_matrixdup.c src/ft_print_list.c \
			src/ft_print_tree.c src/ft_isnumeric.c src/ft_atoi.c

OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@mkdir -p obj
	@mkdir -p bin
	@mv $(OBJS) ./obj
	@mv $(NAME) ./bin

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf obj

fclean: clean
	@rm -rf bin

re: fclean all

.PHONY: all clean fclean re
