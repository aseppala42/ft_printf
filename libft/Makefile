# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aseppala <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 10:50:45 by aseppala          #+#    #+#              #
#    Updated: 2020/06/17 19:21:39 by aseppala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_isspace.c ft_memset.c ft_strchr.c ft_strnew.c ft_isupper.c ft_putchar.c\
ft_strcmp.c ft_strnstr.c ft_atoi.c ft_lstadd.c ft_putchar_fd.c ft_strcpy.c\
ft_strrchr.c ft_bzero.c ft_lstiter.c ft_putendl.c ft_strdel.c ft_strstr.c\
ft_isalnum.c ft_memalloc.c ft_putendl_fd.c ft_strdup.c ft_strtrim.c ft_isalpha.c\
ft_memccpy.c ft_putnbr.c ft_strlcat.c ft_tolower.c ft_isascii.c ft_memcmp.c\
ft_putnbr_fd.c ft_strlen.c ft_toupper.c ft_isdigit.c ft_memcpy.c ft_putstr.c\
ft_strncat.c ft_islower.c ft_memdel.c ft_putstr_fd.c ft_strncmp.c ft_isprint.c\
ft_memmove.c ft_strcat.c ft_strncpy.c ft_itoa.c ft_lstmap.c ft_realloc.c\
ft_striter.c ft_strmap.c ft_strnequ.c ft_lstdel.c ft_lstnew.c ft_strclr.c\
ft_striteri.c ft_strmapi.c ft_strsplit.c ft_lstdelone.c ft_memchr.c ft_strequ.c\
ft_strjoin.c ft_strndup.c ft_strsub.c ft_chrjoin.c ft_strclen.c ft_strlcpy.c\
ft_joindel.c ft_strcount.c get_next_line.c ft_swap.c ft_strnrev.c\
ft_strrev.c ft_strupr.c ft_strlwr.c ft_strpbrk.c ft_strspn.c ft_strcspn.c\
ft_imaxtoa.c ft_uimaxtoa.c ft_rmchr.c ft_abs.c\
ft_imaxabs.c ft_fabs.c ft_fabsl.c ft_pow.c ft_powl.c ft_ftoa.c ft_sqrt.c\
ft_sqrtl.c ft_ceil.c ft_ceill.c ft_floor.c ft_floorl.c ft_round.c ft_roundl.c\
ft_fequal.c ft_fequall.c ft_fmax.c ft_fmaxl.c ft_fmin.c ft_fminl.c ft_max.c\
ft_min.c ft_fmod.c ft_fmodl.c ft_modf.c ft_modfl.c ft_setprecision.c ft_trunc.c\
ft_truncl.c ft_strtok.c ft_iswspace.c ft_numlen.c
OBJ = $(SRC:.c=.o)
HDR = includes

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRC) -I $(HDR)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
