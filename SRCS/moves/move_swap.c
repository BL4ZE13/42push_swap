/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:29:00 by diomarti          #+#    #+#             */
/*   Updated: 2023/02/01 15:37:20 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	m_swap(t_list **s, int i)
{
	t_list *cursor;
	t_list *tmp;

	cursor = *s;
	tmp = cursor->next->next;
	cursor = cursor->next;
	cursor->next = *s;
	*s = cursor;
	cursor = cursor->next;
	cursor->next = tmp;
	if (i == 0)
		ft_printf("sa\n");
	if (i == 1)
		ft_printf("sb\n");
}

void	m_ss(t_list **la, t_list **lb, int i)
{
	m_swap(la, 2);
	m_swap(lb, 2);
	if (i == 2)
		ft_printf("ss\n");
}
