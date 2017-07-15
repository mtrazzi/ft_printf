# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/27 16:05:15 by mtrazzi           #+#    #+#              #
#    Updated: 2017/07/15 18:53:40 by mtrazzi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_assign_type.c ft_change.c ft_conv_d.c ft_free.c ft_init.c ft_insert.c ft_next_conversion.c ft_parse.c ft_parse_opt.c ft_printf.c  utils.c ft_value.c ft_conv_s.c ft_print_S.c ft_print_C.c ft_print_uni.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC)
	ar rc $(NAME) $(OBJ)
	
clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
