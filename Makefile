#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtelega <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/03 18:18:31 by dtelega           #+#    #+#              #
#    Updated: 2017/06/03 18:18:32 by dtelega          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lemin

FLAGS = -Wall -Wextra -Werror

SRC = errors.c find_par_ways.c free_stuff.c ft_strjoin_free.c get_links.c get_rooms.c help_stuff.c main.c push_ants.c reader.c way_stuff.c get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft/ && $(MAKE)
	@gcc -o $(NAME) $(OBJ) libft/libft.a
	@echo 'OK'

%.o : %.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make clean -C libft/
	@echo 'clean'

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/
	@echo 'fclean'

re: fclean all
