# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 20:12:39 by pdonnie           #+#    #+#              #
#    Updated: 2019/04/06 23:21:03 by pdonnie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCE = array.c ft_itoa.c ft_printf.c ft_putchar.c ft_putnstr.c \
	ft_refill.c ft_strlen.c ft_transform.c \
	operations.c parse.c validation.c csp.c \
	num_sys.c num_sys2.c num_sys3.c num_sys4.c num_sys5.c num_sys6.c num_sys7.c \
	num_sys8.c num_sys9.c num_sys10.c num_sys11.c num_sys12.c ft_strjoin.c \
	float.c float_get_print.c decimal.c decimal_print.c \
	hexadecimal.c hexadecimal_print.c octal.c octal_print.c \
	unsigned.c unsigned_print.c pointer.c

OBJECTS = array.o ft_itoa.o ft_printf.o ft_putchar.o ft_putnstr.o \
	ft_refill.o ft_strlen.o ft_transform.o \
	operations.o parse.o validation.o csp.o \
	num_sys.o num_sys2.o num_sys3.o num_sys4.o num_sys5.o num_sys6.o num_sys7.o \
	num_sys8.o num_sys9.o num_sys10.o num_sys11.o num_sys12.o ft_strjoin.o \
	float.o float_get_print.o decimal.o decimal_print.o \
	hexadecimal.o hexadecimal_print.o octal.o octal_print.o \
	unsigned.o unsigned_print.o pointer.o

all : $(NAME)

$(NAME) : $(OBJECTS)
		ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -I printf.h

clean :
		/bin/rm -f $(OBJECTS)

fclean : clean
		/bin/rm -f $(NAME)

re : fclean all
