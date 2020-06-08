# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aseppala <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 10:09:10 by aseppala          #+#    #+#              #
#    Updated: 2019/11/20 19:51:43 by aseppala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = #-Wall -Wextra -Werror

SRC = ft_printf.c specs.c parse_specs.c conversion.c type.c fmt.c
OBJ = $(SRC:.c=.o) 
HDR = .

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc -c $(FLAGS) $(SRC) -I $(HDR)
	ar rc $(NAME) $(OBJ) libft/*.o
	ranlib $(NAME)

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
