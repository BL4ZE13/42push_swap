/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:21:31 by diomarti          #+#    #+#             */
/*   Updated: 2023/02/08 16:09:40 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_case(t_list *s)
{
	int	a;
	int	b;
	int	c;

	a = s->content;
	b = s->next->content;
	c = s->next->next->content;
	if (a < b && b > c && c > a)
		return (1);
	if (a < b && b > c && c < a)
		return (2);
	if (a > b && b < c && c < a)
		return (3);
	if (a > b && b < c && c > a)
		return (4);
	if (a > b && b > c && c < a)
		return (5);
	else
		return (0);
}

void	alg_3(t_list **a)
{
	t_list	*cursor;
	int	c;

	cursor = *a;
	c = ft_case(cursor);
	if (c == 1)
	{
		m_rev_rotate(a, 0);
		m_swap(a, 0);
	}
	if (c == 2)
		m_rev_rotate(a, 0);
	if (c == 3)
		m_rotate(a, 0);
	if (c == 4)
		m_swap(a, 0);
	if (c == 5)
	{
		m_swap(a, 0);
		m_rev_rotate(a, 0);
	}
}
