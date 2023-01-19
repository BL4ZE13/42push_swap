# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 13:10:41 by diomarti          #+#    #+#              #
#    Updated: 2023/01/19 14:01:53 by diomarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap


CC	= gcc
CFLAGS	= -Wall -Werror -Wextra
RM = rm -rf

HEADER = push_swap.h

LIBFT	= ./libft/libft.a
LIBFT_PATH	= ./libft

FT_PRINTF	= ./ft_printf/libftprintf.a
FT_PRINTF_PATH	= ./ft_printf

INC	= -I ./ft_printf -I ./includes -I ./libft

SRCS_PATH	= ./utils

OBJ_PATH	= ./objects

SRCS_NAME	= move_sa.c\

OBJS	= $(addprefix $(OBJ_PATH)/, $(SRCS_NAME:.c=.o))
SRCS	= $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

#RULES

all: $(NAME)

$(NAME) : $(OBJS)
		make -C $(LIBFT_PATH)
		make -C $(FT_PRINTF_PATH)
		$(CC) $(CFLAGS) $(OBJS) $(INC) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(OBJ_PATH)/%.o	: $(SRCS_PATH)/%.c
		mkdir -p objects
		$(CC) -c $(CFLAGS) $(INC) $< -o $@

clean:
		make clean -C $(LIBFT_PATH)
		make clean -C $(FT_PRINTF_PATH)
		rm -rf $(OBJ_PATH)

fclean:	clean
		make fclean -C $(LIBFT_PATH)
		make fclean -C $(FT_PRINTF_PATH)
		rm -f $(NAME)

re: fclean all

#.PHONY: all, clean, fclean, re 