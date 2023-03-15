/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:28:28 by diomarti          #+#    #+#             */
/*   Updated: 2023/03/15 14:49:55 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*o 1 elemento do B passa para o topo do A*/
#include "../../push_swap.h"

void	m_push(t_list **src, t_list **dest, int i)
{
	t_list	*cursor_src;
	t_list	*cursor_dest;
	t_list	*tmp;

	cursor_src = *src;
	if (!*dest)
	{
		*dest = *src;
		cursor_dest = *dest;
		*src = cursor_src->next;
		cursor_dest->next = NULL;
	}
	else
	{
		tmp = *dest;
		*dest = *src;
		cursor_dest = *dest;
		*src = cursor_src->next;
		cursor_dest->next = tmp;
	}
	if (i == 0)
		ft_printf("pa\n");
	if (i == 1)
		ft_printf("pb\n");
}
