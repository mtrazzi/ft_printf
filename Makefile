# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/27 16:05:15 by mtrazzi           #+#    #+#              #
#    Updated: 2017/07/15 20:55:21 by mtrazzi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_assign_type.c ft_change.c ft_conv_d.c ft_free.c ft_init.c ft_insert.c ft_next_conversion.c ft_parse.c ft_parse_opt.c ft_printf.c  utils1.c utils2.c utils3.c utils4.c utils5.c ft_value.c ft_conv_s.c ft_print_s.c ft_print_c.c ft_print_uni.c

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
