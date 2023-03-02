/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:13:08 by diomarti          #+#    #+#             */
/*   Updated: 2023/02/27 14:48:06 by diomarti         ###   ########.fr       */
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
	int			content;
	struct s_list *next;
	struct s_list *prev;
}						t_list;

typedef	struct	s_chunk
{
	int min_c;
	int max_c;
	int i_max;
	int i_min;
}						t_chunk;
	
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
t_list		*ft_small(t_list *s);
void		put_list(t_list **s, int argc, char **argv);
void		call_case(t_list **a, t_list **b, int argc);
int			ft_isdigit(int c);
void		inc_chunk(t_chunk *chunk, int *lst, int len, int o);
int			exist_c(t_list **a, t_chunk c);
void		push_chunk(t_list **a, t_list **b, t_chunk c, int n);
void		joint_moves(t_list **a, t_list **b, t_list *best, t_list *index);


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
int 		ft_cost(t_list **a, t_list **b, t_list *index, t_list *c);
t_list		*best_to_do(t_list **a, t_list **b);


//cost
t_list		*find_index(t_list *a, t_list *b);
t_list		*last_great(t_list **a);
int			rot_cost(t_list *a, t_list *index);
int			rr_cost(t_list *index);
void		final_sort(t_list **a, int argc);


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
void 		alg_100(t_list **a, t_list **b, int argc);


//BONUS

typedef struct s_checker
{
	int		c;
	char	*moves;
}	t_chercker;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		check_p(char *moves, t_list **a, t_list **b);
void		check_rot(char *moves, t_list **a, t_list **b);
void		check_s(char *moves, t_list **a, t_list **b);
void		check_rev(char *moves, t_list **a, t_list **b);
void		ft_clear_all(t_list **a, t_list **b);
void		ft_initialize_lst(t_list **a, t_list **b);

#	endif