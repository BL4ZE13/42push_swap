/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg100.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:49:39 by diomarti          #+#    #+#             */
/*   Updated: 2023/03/15 14:48:21 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	top_to_lst(t_list **s, int i, int o)
{
	if (i == -1)
		return ;
	if (i < (ft_lstsize(*s) / 2))
		m_rotate(s, o);
	else
		m_rev_rotate(s, o);
}

int	check_index(t_list **lst, int i)
{
	t_list	*cursor;
	int		c;
	int		trigger;

	c = 0;
	trigger = -1;
	cursor = *lst;
	while (cursor)
	{
		if (cursor->index == i)
		{
			trigger = 0;
			break ;
		}
		c++;
		cursor = cursor->next;
	}
	if (trigger == -1)
		return (-1);
	return (c);
}

int	check_big_index(t_list **lst)
{
	t_list	*cursor;
	int		big;

	cursor = *lst;
	big = cursor->index;
	while (cursor)
	{
		if (cursor->index > big)
			big = cursor->index;
		cursor = cursor->next;
	}
	return (big);
}

void	put_in_b(t_list **a, t_list **b, int size)
{
	int	chunk;
	int	c;

	chunk = 30;
	c = 0;
	while (*a != NULL)
	{
		if ((*a)->index < chunk)
		{
			m_push(a, b, 1);
			c++;
		}
		else if (c == chunk)
		{
			if (size > 100)
				chunk += 30;
			else
				chunk += 15;
		}
		else
			top_to_lst(a, check_index(a, (*a)->index), 0);
	}
}

void	alg_100(t_list **a, t_list **b)
{
	int	big;
	int	index;

	put_in_b(a, b, ft_lstsize(*a));
	big = check_big_index(b);
	index = check_index(b, big);
	while ((*b) != NULL && index == check_index(b, big))
		index = put_in_a(a, b, &big, index);
	if ((*b) == NULL && (*a)->content > (*a)->next->content)
		m_swap(a, 0);
}
