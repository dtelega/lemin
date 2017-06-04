#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtelega <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/06 17:27:41 by dtelega           #+#    #+#              #
#    Updated: 2016/12/08 14:07:02 by dtelega          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = ft_intlen.c ft_lenmap.c ft_strrev.c ft_putmap.c ft_lstmap.c ft_lstiter.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstnew.c ft_itoa.c ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_strsplit.c ft_strtrim.c ft_strjoin.c ft_strsub.c ft_strnequ.c ft_strequ.c ft_strmapi.c ft_strmap.c ft_striteri.c ft_striter.c ft_strclr.c ft_strdel.c ft_strnew.c ft_memdel.c ft_memalloc.c ft_putnbr.c ft_strrchr.c ft_strchr.c ft_strlcat.c ft_strncat.c ft_strcat.c ft_toupper.c ft_tolower.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_memccpy.c ft_memcmp.c ft_strnstr.c ft_strdup.c ft_strlen.c ft_memset.c ft_bzero.c ft_memmove.c ft_memchr.c ft_memcpy.c ft_putchar.c ft_putstr.c ft_strcmp.c ft_atoi.c ft_strcpy.c ft_strncpy.c ft_strstr.c ft_strncmp.c

OB = $(SRC:.c=.o)

IN = libft.h

FLAGS = -Wall -Wextra -Werror

all:$(NAME)

%.o: %.c
	@gcc $(FLAGS) -I $(IN) -c $< -o $@

$(NAME): $(OB)
	@ar rc $(NAME) $(OB)

clean:
	@rm -rf $(OB)

fclean: clean
	@rm -rf $(NAME)

re: clean all
