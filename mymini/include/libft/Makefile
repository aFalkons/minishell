# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 23:56:29 by afalconi          #+#    #+#              #
#    Updated: 2023/11/29 17:19:40 by afalconi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRCS	=	src/ft_strlen.c src/ft_calloc.c src/ft_exit.c src/ft_strndup.c \
			src/ft_putstr_fd.c src/ft_print_message.c src/ft_strlcpy.c \
			src/ft_strncmp.c src/ft_strdup.c src/ft_strjoin.c \
			src/ft_count_char_split.c src/ft_split.c src/ft_substr.c \
			src/ft_count_char.c src/ft_matrixdup.c src/ft_print_list.c \
			src/ft_print_tree.c src/ft_isnumeric.c src/ft_atoi.c \
			src/ft_for_debug.c src/ft_count_char_array.c \
			src/ft_find_char_array.c src/ft_get_size_array.c \
			src/ft_isalnum_char.c src/ft_isalnum_str.c src/ft_isascii_char.c \
			src/ft_isascii_str.c src/ft_isdigit.c src/ft_isdigit_str.c \
			src/ft_print_array.c src/ft_remove_char_in_str.c \
			src/ft_strchr.c src/ft_strcmp.c src/ft_find_index_next_char.c \
			src/ft_strncpy.c src/ft_memcpy.c src/ft_strstr.c src/ft_realloc.c \
			src/ft_copy_array.c src/ft_find_char_index_str.c \
			src/ft_swap_strings.c src/ft_add_string.c src/ft_cmp_len_and_str.c

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
