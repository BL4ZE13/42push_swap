# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 13:10:41 by diomarti          #+#    #+#              #
#    Updated: 2023/03/15 14:29:36 by diomarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
NAME_BONUS = checker

SRCS	= SRCS/lsts/ft_lstadd_back.c \
			SRCS/lsts/ft_lstadd_front.c \
			SRCS/lsts/ft_lstclear.c \
			SRCS/lsts/ft_lstlast.c \
			SRCS/lsts/ft_lstnew.c \
			SRCS/lsts/ft_lstsize.c \
			SRCS/moves/move_push.c \
			SRCS/moves/move_rev_rotate.c \
			SRCS/moves/move_rotate.c \
			SRCS/moves/move_swap.c \
			SRCS/sort/alg2.c \
			SRCS/sort/alg3.c \
			SRCS/sort/alg5.c \
			SRCS/sort/alg100.c \
			SRCS/sort/alg500.c \
			SRCS/utils/check_errors.c \
			SRCS/utils/ft_atoi.c \
			SRCS/utils/ft_isdigit.c \
			SRCS/utils/ft_strlen.c \
			SRCS/utils/ft_strncmp.c \
			SRCS/utils/print_list.c \
			SRCS/utils/utils.c \
			main.c

SRCS_BONUS =	SRCS/lsts/ft_lstadd_back.c \
			SRCS/lsts/ft_lstadd_front.c \
			SRCS/lsts/ft_lstclear.c \
			SRCS/lsts/ft_lstlast.c \
			SRCS/lsts/ft_lstnew.c \
			SRCS/lsts/ft_lstsize.c \
			SRCS/moves/move_push.c \
			SRCS/moves/move_rev_rotate.c \
			SRCS/moves/move_rotate.c \
			SRCS/moves/move_swap.c \
			SRCS/sort/alg2.c \
			SRCS/sort/alg3.c \
			SRCS/sort/alg5.c \
			SRCS/sort/alg100.c \
			SRCS/sort/alg500.c \
			SRCS/utils/check_errors.c \
			SRCS/utils/ft_atoi.c \
			SRCS/utils/ft_isdigit.c \
			SRCS/utils/ft_strlen.c \
			SRCS/utils/ft_strncmp.c \
			SRCS/utils/print_list.c \
			SRCS/utils/utils.c \
			BONUS/checker/checker_moves.c \
			BONUS/checker/checker.c\
			BONUS/gnl/get_next_line_utils.c \
			BONUS/gnl/get_next_line.c \

OBJS	=	${SRCS:.c=.o}
OBJS_BONUS	=${SRCS_BONUS:.c=.o}

FT_PRINTF = ./ft_printf/libftprintf.a
FT_PRINTF_PATH = ./ft_printf

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address

all: ${NAME}

${NAME}: ${OBJS}
		make -C ${FT_PRINTF_PATH}
		@${CC} ${CFLAGS} ${OBJS} ${FT_PRINTF} -o ${NAME}

bonus: ${OBJS_BONUS}
		make -C ${FT_PRINTF_PATH}
		@${CC} ${CFLAGS} ${OBJS_BONUS} ${FT_PRINTF} -o ${NAME_BONUS}

dg:
		@${CC} -Wall -Werror -Wextra -g  ${SRCS} -o ${NAME}

clean:
		@rm -rf ${OBJS}
		@make clean -C ${FT_PRINTF_PATH}

fclean: clean
		@rm -rf ${NAME}
		@make fclean -C ${FT_PRINTF_PATH}
		@rm -rf ${OBJS_BONUS} ${NAME_BONUS}

fclean_all: fclean

re: fclean ${NAME}

rebonus: fclean bonus

.PHONY: all clean fclean re