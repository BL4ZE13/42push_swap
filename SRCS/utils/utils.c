/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:47:23 by diomarti          #+#    #+#             */
/*   Updated: 2023/02/22 16:45:54 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*ft_small(t_list *s)
{
	t_list	*cursor;
	t_list	*small;

	cursor = s;
	small = cursor;
	while (cursor)
	{
		if (cursor->content < small->content)
			small = cursor;
		cursor = cursor->next;
	}
	return (small);
}

void inc_chunk(t_chunk *chunk, int *lst, int len, int o)
{
	if (o == 1)
	{
		chunk->i_min = 0;
		chunk->i_max = len;
	}
	else
	{
		chunk->i_min += len;
		chunk->i_max = chunk->i_min + len;
	}
	chunk->min_c = lst[chunk->i_min];
	chunk->max_c = lst[chunk->i_max];	
}

int	exist_c(t_list **a, t_chunk c)
{
	t_list *cursor;
	
	cursor = *a;
	while (cursor)
	{
		if (cursor->content >= c.min_c && cursor->content <= c.max_c)
			return (1);
		cursor = cursor->next;
	}
	return (0);
}

void	push_chunk(t_list **a, t_list **b, t_chunk c, int n)
{
	if (*a)
	{
		if ((*a)->content >= c.min_c
			&& (*a)->content <= c.max_c)
			m_push(a, b, 1);
		else
		{
			if (n == 2)
			{
				m_push(a, b, 1);
				m_rotate(b, 1);
			}
			else
				m_rotate(a, 0);
		}
	}
}

t_list *best_to_do(t_list **a, t_list **b)
{
	t_list *c;
	t_list *index_c;
	t_list *best;
	t_list *index_best;

	c = *b;
	best = *b;
	index_best = find_index(*a, best);
	while (c)
	{
		index_c = find_index(*a, c);
		if (ft_cost(a, b, index_c, c)
			< ft_cost(a, b, index_best, best))
		{
			best = c;
			index_best = index_c;
		}
		c = c->next;
	}
	return (best);
}