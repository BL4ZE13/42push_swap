/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:28:07 by diomarti          #+#    #+#             */
/*   Updated: 2023/03/15 14:49:28 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*tds descem uma posicao, quem ta em ultimo passa para primeiro (coluna A)*/
#include "../../push_swap.h"

void	m_rev_rotate(t_list **s, int i)
{
	t_list	*cursor;
	t_list	*tmp;

	cursor = ft_lstlast(*s);
	cursor->next = *s;
	tmp = *s;
	while (tmp->next != cursor)
		tmp = tmp->next;
	tmp->next = NULL;
	*s = cursor;
	if (i == 0)
		ft_printf("rra\n");
	if (i == 1)
		ft_printf("rrb\n");
}

void	m_rrr(t_list **lst_a, t_list **lst_b, int i)
{
	m_rev_rotate(lst_a, 2);
	m_rev_rotate(lst_b, 2);
	if (i == 2)
		ft_printf("rrr\n");
}
