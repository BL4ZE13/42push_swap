# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 13:10:41 by diomarti          #+#    #+#              #
#    Updated: 2023/02/27 14:51:04 by diomarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
NAME_BONUS = checker

SRCS	= ${wildcard *.c} ${wildcard SRCS/*.c} ${wildcard SRCS/*/*.c} ${wildcard ft_printf/*.c}
SRCS_BONUS = ${wildcard BONUS/checker/*.c} ${wildcard BONUS/gnl/*.c} ${wildcard SRCS/*.c} ${wildcard SRCS/*/*.c} ${wildcard ft_printf/*.c}

OBJS	=${SRCS:.c=.o}
OBJS_BONUS	=${SRCS_BONUS:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address

all: ${NAME}

${NAME}: ${OBJS}
		@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
		
bonus: ${OBJS_BONUS}
		@${CC} ${CFLAGS} ${OBJS_BONUS} -o ${NAME_BONUS}

dg:
		@${CC} -Wall -Werror -Wextra -g  ${SRCS} -o ${NAME}

clean:
		@rm -rf ${OBJS}

fclean: clean
		@rm -rf ${NAME}
		@rm -rf ${OBJS_BONUS} ${NAME_BONUS}

fclean_all: fclean

re: fclean ${NAME}

rebonus: fclean bonus

.PHONY: all clean fclean re