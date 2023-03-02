/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg100.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:15:30 by diomarti          #+#    #+#             */
/*   Updated: 2023/02/28 12:24:45 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void ft_sort_array(int **lst, int size)
{
	int i;
	int a;
	int tmp;
	
	a = 1;
	while (a > 0)
	{
		a = 0;
		i = 0;
		while (i < (size - 1))
		{
			if ((*lst)[i] > (*lst)[i + 1])
			{
				tmp = (*lst)[i];
				(*lst)[i] = (*lst)[i + 1];
				(*lst)[i + 1] = tmp;
				a++;
			}
			i++;
		}
	}
}

int	*ft_create_array(t_list **a, int size)
{
	int	*lst;
	int i;
	t_list *cursor;

	lst = malloc(size * sizeof(int));
	cursor = *a;
	i = 0;
	while (cursor)
	{
		lst[i] = cursor->content;
		i++;
		cursor = cursor->next;
	}
	ft_sort_array(&lst, size);
	return (lst);
}

int	num_of_chunks(int size)
{
	int nmb_c;

	nmb_c = 1;
	if (size == 100)
		nmb_c = 2;
	else if (size == 500)
		nmb_c = 4;
	return (nmb_c);
}

void p_back_a(t_list **a, t_list **b)
{
	t_list *best;
	t_list *index;

	best = best_to_do(a, b);
	index = find_index(*a, best);
	while (*b != best || *a != index)
	{
		joint_moves(a, b, index, best);
		while (best != *b)
		{
			if (rot_cost(*b, best) > rr_cost(best))
				while (*b != best)
					m_rev_rotate(b, 1);
			else
				while (*b != best)
					m_rotate(b, 1);
		}
		if (rot_cost(*a, index) > rr_cost(index))
			while (*a != index)
				m_rev_rotate(a, 0);
		else
			while (*a != index)
				m_rotate(a, 0);
	}
	m_push(b, a, 0);
}

void alg_100(t_list **a, t_list **b, int argc)
{
	int	*lst;
	int c_size;
	int	max;
	t_chunk	chunk;
	
	c_size = ft_lstsize(*a) / num_of_chunks(ft_lstsize(*a));
	lst = ft_create_array(a, argc);
	max = ft_lstsize(*a);
	inc_chunk(&chunk, lst, c_size, 1);
	while (ft_lstsize(*a) > 3)
	{
		if (exist_c(a, chunk))
			push_chunk(a, b, chunk, num_of_chunks(max));
		else
			inc_chunk(&chunk, lst, c_size, 2);
	}
	free(lst);
	if (!(is_sort(a)))
		alg_3(a);
	while (ft_lstsize(*b) > 0)
		p_back_a(a, b);
	if (!(is_sort(a)))
		final_sort(a, argc);	
}

