/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:28:23 by diomarti          #+#    #+#             */
/*   Updated: 2023/02/02 15:26:55 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*tds sobem uma posicao, quem ta em primerio passa para ultimo (coluna A)*/
#include "../../push_swap.h"

void	m_rotate(t_list **s, int i)
{
	t_list *tmp;
	t_list *cursor;

	cursor = ft_lstlast(*s);
	cursor->next = *s;
	cursor = *s;
	tmp = (*s)->next;
	cursor->next = NULL;
	*s = tmp;
	
	if (i == 0)
		ft_printf("ra\n");
	if (i == 1)
		ft_printf("rb\n");
}

void	m_rr(t_list **lst_a, t_list **lst_b, int i)
{
	m_rotate(lst_a, 2);
	m_rotate(lst_b, 2);
	if (i == 2)
		ft_printf("rr\n");
}
