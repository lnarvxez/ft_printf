# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 16:31:58 by lnarvaez          #+#    #+#              #
#    Updated: 2022/04/22 16:31:59 by lnarvaez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB		= ar rcs
RM		= rm -f
CC		= gcc
CCFLAGS	= -Wextra -Werror -Wall
NAME	= libftprintf.a
SRC		=	ft_printf.c ft_printstrnbr.c ft_itoa.c ft_printhexa.c ft_printunbr.c \
			ft_printptr.c

OBJ = $(SRC:.c=.o)
INCLUDE = ft_printf.h

all : $(NAME)
$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

