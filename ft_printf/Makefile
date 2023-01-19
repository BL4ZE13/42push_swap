# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 16:22:40 by diomarti          #+#    #+#              #
#    Updated: 2022/11/28 13:50:33 by diomarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

FILES	=	ft_printf.c ft_numbers.c ft_words.c\

OBJS	=	$(FILES:.c=.o)

RM	= rm -f

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror -I.

all:	$(NAME)

$(NAME):	$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
