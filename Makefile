# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 20:12:39 by pdonnie           #+#    #+#              #
#    Updated: 2019/12/15 07:52:24 by pdonnie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pdonnie.filler
CC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCES_PATH = ./sources/
OBJECTS_PATH = ./objects/
LIBFT_DIR = ./libft
PRINTF_DIR = ./libft/printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
INCLUDE = include/filler.h
INCLUDES = -I ./libft/includes/libft.h -I ./include/filler.h

SOURCES_NAME = main.c error.c get_maps.c tools.c
SOURCES = $(addprefix $(SOURCES_PATH), $(SOURCES_NAME))
OBJECTS_NAME = $(SOURCES_NAME:%.c=%.o)
OBJECTS = $(addprefix $(OBJECTS_PATH), $(OBJECTS_NAME))

all : $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(PRINTF) -o $@ $(OBJECTS)

$(LIBFT): FORCE
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)

FORCE:

$(OBJECTS_PATH)%.o: $(SOURCES_PATH)%.c $(INCLUDE)
	@mkdir $(OBJECTS_PATH) 2>/dev/null || echo "" > /dev/null
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean :
		@/bin/rm -f $(OBJECTS)
	    @/bin/rm -rf $(OBJECTS_PATH)
	    @/bin/rm -f *.h.gch
	    @/bin/rm -f .*.swp
		@make clean -C $(LIBFT_DIR)
		@make clean -C $(PRINTF_DIR)

fclean : clean
		@make fclean -C $(LIBFT_DIR)
		@make fclean -C $(PRINTF_DIR)
		@/bin/rm -f $(NAME)

re : fclean all
