/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg500.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:34:07 by diomarti          #+#    #+#             */
/*   Updated: 2023/03/09 11:34:07 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int check_pos(t_list **b, int big, int size)
{
	int i;
	t_list *cursor;

	i = 0;
	cursor = *b;
	while (cursor->index != big)
	{
		i++;
		cursor = cursor->next;
	}
	size = size - i;
	if (i < size)
		return (0);
	return (1);
}

void	sort_to_a(t_list **a, t_list **b)
{
	while ((*b))
	{
		if (!(*b))
			break ;
		if ((*b)->index != check_big_index(b) && 
			!check_pos(b, check_big_index(b), ft_lstsize(*b)))
			m_rotate(b, 1);
		else if ((*b)->index != check_big_index(b) &&
			check_pos(b, check_big_index(b), ft_lstsize(*b)))
			m_rev_rotate(b, 1);
		else if ((*b)->index == check_big_index(b))
			m_push(b, a, 0);
	}
}

void	alg_500(t_list **a, t_list **b)
{
	int i;

	i = 0;
	while (*a)
	{
		if (i > 1 && (*a)->index <= i)
		{
			m_push(a, b, 1);
			i++;
			m_rotate(b, 1);
		}
		else if ((*a)->index <= i + 30)
		{
			m_push(a, b, 1);
			i++;
		}
		else if ((*a)->index >= i)
		{
			m_rotate(a, 0);
		}
	}
	sort_to_a(a, b);
}
