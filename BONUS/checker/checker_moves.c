/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:11:04 by diomarti          #+#    #+#             */
/*   Updated: 2023/02/24 16:31:57 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	check_p(char *moves, t_list **a, t_list **b)
{
	if (!(ft_strncmp(moves, "pb\n", 3)))
		m_push(a, b, 3);
	else
		m_push(b, a, 3);	
}

void check_rot(char *moves, t_list **a, t_list **b)
{
	if (!ft_strncmp(moves, "ra\n", 3))
		m_rotate(a, 3);
	else if (!ft_strncmp(moves, "ra\n", 3))
		m_rotate(b, 3);
	else
		m_rr(a, b, 3);
}

void	check_s(char *moves, t_list **a, t_list **b)
{
	if (!ft_strncmp(moves, "sa\n", 3))
		m_swap(a, 3);
	else if (!ft_strncmp(moves, "sb\n", 3))
		m_swap(b, 3);
	else
		m_ss(a, b, 3);
}

void	check_rev(char *moves, t_list **a, t_list **b)
{
	if (!ft_strncmp(moves, "ra\n", 3))
		m_rev_rotate(a, 3);
	else if (!ft_strncmp(moves, "rb\n", 3))
		m_rev_rotate(b, 3);
	else
		m_rrr(a, b, 3);
}
