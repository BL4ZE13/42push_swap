/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:47:23 by diomarti          #+#    #+#             */
/*   Updated: 2023/03/08 01:32:36 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	get_index(t_list **a)
{
	t_list *cursor;
	t_list *tmp;
	
	cursor = *a;
	while (cursor)
	{
		cursor->index = 0;
		tmp = *a;
		while (tmp)
		{
			if(cursor != tmp && cursor->content > tmp->content)
				cursor->index++;
			tmp = tmp->next;
		}
		cursor = cursor->next;
	}
}

int	put_in_a(t_list **a, t_list **b, int *big, int index)
{
	if ((*a) && (*a)->next && (*a)->content > (*a)->next->content)
	{
		m_swap(a, 0);
		(*big)--;
		index = check_index(b, *big);
	}
	else if ((check_index(b, ((*big) - 1)) == 0))
	{
		m_push(b, a, 0);
		index = check_index(b, (*big));
	}
	else if (index == 2 && (check_index(b, ((*big) - 1)) == 0))
	{
		m_push(b ,a, 0);
		(*big)--;
		m_rotate(b, 1);
		m_push(b, a, 0);
		(*big)--;
		m_swap(a, 0);
		index = check_index(b, (*big));
	}
	index = put_in_a_2(a, b, big, index);
	return (index);
}

int	put_in_a_2(t_list **a, t_list **b, int *big, int index)
{
	if (index == 1 && (check_index(b, (*big) - 1)) == 0)
	{
		m_swap(b, 1);
		index = check_index(b, (*big));
	}
	else if (check_index(b, (*big)) == 0)
	{
		m_push(b, a, 0);
		(*big)--;
		index = check_index(b, (*big));
	}
	else
	{
		top_to_lst(b, index, 1);
		index = check_index(b, (*big));
	}
	return (index);
}