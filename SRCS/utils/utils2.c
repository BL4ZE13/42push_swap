/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:00:36 by diomarti          #+#    #+#             */
/*   Updated: 2023/02/22 15:38:43 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int ft_cost(t_list **a, t_list **b, t_list *index, t_list *c)
{
	int	cost;

	if (rot_cost(*b, c) > rr_cost(c))
	{
		if (rot_cost(*a, index) > rr_cost(index))
			cost = rr_cost(c) + rr_cost(index);
		else
			cost = rr_cost(c) + rot_cost(*a, index);
	}
	else
	{
		if (rot_cost(*a, index) > rr_cost(index))
			cost = rot_cost(*b, c) + rr_cost(index);
		else
			cost = rot_cost(*b, c) + rot_cost(*a, index);
	}
	return (cost);
}

void	joint_moves(t_list **a, t_list **b, t_list *best, t_list *index)
{
	if (*a != index && *b != best)
	{
		if (rot_cost(*b, best) > rr_cost(index))
		{
			if (rot_cost(*a, index) > rr_cost(index))
				m_rrr(a, b, 2);
		}
		else
		{
			if (rot_cost(*a, index) < rr_cost(index))
				m_rr(a, b, 0);
		}
	}
}
