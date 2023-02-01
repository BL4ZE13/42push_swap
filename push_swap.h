/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:13:08 by diomarti          #+#    #+#             */
/*   Updated: 2023/01/31 16:54:04 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#	define PUSH_SWAP_H

//includes

#	include <stdio.h>
#	include <string.h>
#	include <stdlib.h>
#	include <unistd.h>
#	include <limits.h>
#	include "ft_printf/ft_printf.h"

//lists
typedef struct s_list
{
	int			content;
	struct s_list *next;
	struct s_list *prev;
}						t_list;
	

//functions
void	m_sa(t_list *s);
void	m_sb(t_list *s);
void	m_ss(t_list *s);
void	m_pa(t_list *s);
void	m_pb(t_list *s);
void	m_ra(t_list *s);
void	m_rb(t_list *s);
void	m_rr(t_list *s);
void	m_rra(t_list *s);
void	m_rrb(t_list *s);
void	m_rrr(t_list *s);
int	ft_atoi(const char *str);
void	print_lst(t_list **stack);

//errors
int check_dup(int argc, char **argv);
int	check_valid(int argc, char **argv);
int check_digit(int argc, char **argv);
int	check_signal(int argc, char **argv);
int	check_all(int argc, char **argv);


//lst
t_list	*ft_lstadd_back(t_list **lst, t_list *new_node);
int	ft_lstadd_front(t_list **lst, t_list *new_node);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);


#	endif