# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 13:10:41 by diomarti          #+#    #+#              #
#    Updated: 2023/02/01 14:25:49 by diomarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ${wildcard *.c} ${wildcard SRCS/*.c} ${wildcard SRCS/*/*.c} ${wildcard ft_printf/*.c} ${wildcard ft_printf/*/*.c}

OBJS	=${SRCS:.c=.o}

NAME	= push_swap

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address

all: ${NAME}

${NAME}: ${OBJS}
		@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

dg:
		@${CC} -Wall -Werror -Wextra -g  ${SRCS} -o ${NAME}

clean:
		@rm -rf ${OBJS}

fclean: clean
		@rm -rf ${NAME}

fclean_all: fclean

re: fclean ${NAME}

.PHONY: all clean fclean re