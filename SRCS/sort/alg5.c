/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:02:22 by diomarti          #+#    #+#             */
/*   Updated: 2023/03/15 14:47:00 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	is_sort(t_list **a)
{
	t_list	*cursor;

	cursor = *a;
	while (cursor->next)
	{
		if (cursor->content > cursor->next->content)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}

int	find_smaller(t_list **a)
{
	t_list	*cursor;
	t_list	*small;
	int		c;

	cursor = *a;
	small = *a;
	c = 0;
	while (cursor)
	{
		if (cursor->content < small->content)
			small = cursor;
		cursor = cursor->next;
	}
	cursor = *a;
	while (cursor != small)
	{
		c++;
		cursor = cursor->next;
	}
	return (c);
}

void	do_push(t_list **a, t_list **b, int c, int n)
{
	if (c > 2)
	{
		if (n == 1)
			c = 4 - c;
		else
			c = 5 - c;
		while (c)
		{
			m_rev_rotate(a, 0);
			c--;
		}
	}
	else
	{
		while (c)
		{
			m_rotate(a, 0);
			c--;
		}
	}
	m_push(a, b, 1);
}

void	alg_5(t_list **a, t_list **b)
{
	t_list	*cursor;
	int		c;

	cursor = *a;
	if (ft_lstsize(cursor) == 5)
	{
		c = find_smaller(&cursor);
		do_push(a, b, c, 0);
		cursor = *a;
	}
	c = find_smaller(&cursor);
	do_push(a, b, c, 1);
	if (!(is_sort(a)))
		alg_3(a);
	while (*b)
		m_push(b, a, 0);
}
