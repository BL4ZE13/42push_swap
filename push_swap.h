/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:13:08 by diomarti          #+#    #+#             */
/*   Updated: 2023/03/09 23:32:21 by diomarti         ###   ########.fr       */
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
#	include "../42push_swap/BONUS/gnl/get_next_line.h"

//lists
typedef struct s_list
{
	int				content;
	struct s_list 	*next;
	struct s_list 	*prev;
	int				index;
}						t_list;

	
//functions
void		m_swap(t_list **s, int i);
void		m_ss(t_list **la, t_list **lb, int i);
void		m_push(t_list **src, t_list **dest, int i);
void		m_rotate(t_list **s, int i);
void		m_rr(t_list **lst_a, t_list **lst_b, int i);
void		m_rev_rotate(t_list **s, int i);
void		m_rrr(t_list **lst_a, t_list **lst_b, int i);
long long	ft_atoi(const char *str);
void		print_lst(t_list **stack);
void		put_list(t_list **s, int argc, char **argv);
void		call_case(t_list **a, t_list **b, int agrc);
int			ft_isdigit(int c);
void		get_index(t_list **a);
void		put_list(t_list **s, int argc, char **argv);



//errors
int			check_dup(int argc, char **argv);
int			check_valid(int argc, char **argv);
int			check_signal(int argc, char **argv);
int			check_all(int argc, char **argv);


//lst
void		ft_lstadd_back(t_list **lst, t_list *new_node);
int			ft_lstadd_front(t_list **lst, t_list *new_node);
void		ft_lstclear(t_list **lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(int content);
int			ft_lstsize(t_list *lst);


//alg2
void		alg_2(t_list **a);


//alg3
int			ft_case(t_list *s);
void		alg_3(t_list **a);


//alg5
int			is_sort(t_list **a);
int			find_smaller(t_list **a);
void		do_push(t_list **a, t_list **b, int c, int n);
void		alg_5(t_list **a, t_list **b);


//alg100
void		top_to_lst(t_list **s, int i, int o);
int 		check_index(t_list **s, int i);
int			check_big_index(t_list **lst);
void		put_in_b(t_list **a, t_list **b, int size);
int			put_in_a(t_list **a, t_list **b, int *big, int index);
int			put_in_a_2(t_list **a, t_list **b, int *big, int index);
void		alg_100(t_list **a, t_list **b);


//alg500
int 		check_pos(t_list **b, int big, int size);
void		sort_to_a(t_list **a, t_list **b);
void		alg_500(t_list **a, t_list **b);

//bonus
void		check_push(char *moves, t_list **a, t_list **b);
void 		check_rot(char *moves, t_list **a, t_list **b);
void		check_swap(char *moves, t_list **a, t_list **b);
void		check_rev(char *moves, t_list **a, t_list **b);
void		read_line(char *moves, t_list **a, t_list **b);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		put_list_bonus(t_list **s, int argc, char **argv);

#	endif