# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 23:56:29 by afalconi          #+#    #+#              #
#    Updated: 2023/07/17 01:35:26 by afalconi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_strlen.c

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(%.c)
	@$(CC) $(CFLAGS) -c src/$(SRCS)
	@ar rcs $(NAME) $(OBJS)
	@mkdir -p obj
	@mkdir -p bin
	@mv ./*.o ./obj
	@mv ./*.a ./bin

%.c:%.o
	@$(CC) $(CFLAGS) -o $<

clean:
	@rm -rf obj

fclean: clean
	@rm -rf bin

re: fclean all

.PHONY: all clean fclean re
