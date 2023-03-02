/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_to_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:59:19 by diomarti          #+#    #+#             */
/*   Updated: 2023/02/22 16:43:52 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*find_index(t_list *a, t_list *b)
{
	t_list	*c_a;
	int		c_b;

	c_a = a;
	c_b = b->content;
	if (c_b > ft_lstlast(a)->content
		&& last_great(&a) == ft_lstlast(a))
		return (c_a);
	if (c_b < ft_small(a)->content)
	{
		c_a = ft_small(a);
		return (c_a);
	}
	if (c_a->content > c_b && ft_lstlast(a)->content < c_b)
		return (c_a);
	if (c_b > last_great(&a)->content)
	{
		c_a = last_great(&a)->next;
		return (c_a);
	}
	while (!(c_a->content < c_b && c_a->next->content > c_b))
		c_a = c_a->next;
	while (c_a->content < c_b)
		c_a = c_a->next;
	return (c_a);
}

t_list	*last_great(t_list **a)
{
	t_list	*great;
	t_list	*cursor;

	cursor = *a;
	great = cursor;
	while (cursor)
	{
		if (cursor->content > great->content)
			great = cursor;
		cursor = cursor->next;
	}
	return (great);
}

int	rot_cost(t_list *a, t_list *index)
{
	return (ft_lstsize(a) - ft_lstsize(index));
}

int rr_cost(t_list *index)
{
	return (ft_lstsize(index));
}

void	final_sort(t_list **a, int argc)
{
	if (ft_lstsize(last_great(a)) > argc / 2)
		while (!(is_sort(a)))
			m_rotate(a, 0);
	else
		while (!(is_sort(a)))
			m_rev_rotate(a, 1);
}
