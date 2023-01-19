# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 15:49:15 by diomarti          #+#    #+#              #
#    Updated: 2023/01/19 13:55:04 by diomarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_lstnew ft_lstadd_front ft_lstlast ft_lstadd_back ft_lstclear\
	ft_atoi

CC =gcc
RM =rm -f
CFLAGS = -Wall -Werror -Wextra -I.

all:$(NAME)

$(NAME): $(SRC:=.o)
			ar rc $(NAME) $(SRC:=.o)
clean:
	$(RM)	$(SRC:=.o)
fclean: clean
		$(RM)	$(NAME)
re:	fclean	$(NAME)
