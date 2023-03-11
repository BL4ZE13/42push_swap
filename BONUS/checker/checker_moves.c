/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:43:50 by diomarti          #+#    #+#             */
/*   Updated: 2023/03/11 15:20:42 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	check_push(char *line, t_list **a, t_list **b)
{
	if (!(ft_strncmp(line, "pb\n", 3)))
		m_push(a, b, 3);
	else
		m_push(b, a, 3);	
}

void check_rot(char *line, t_list **a, t_list **b)
{
	if (!ft_strncmp(line, "ra\n", 3))
		m_rotate(a, 3);
	else if (!ft_strncmp(line, "rb\n", 3))
		m_rotate(b, 3);
	else
		m_rr(a, b, 3);
}

void	check_swap(char *line, t_list **a, t_list **b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		m_swap(a, 3);
	else if (!ft_strncmp(line, "sb\n", 3))
		m_swap(b, 3);
	else
		m_ss(a, b, 3);
}

void	check_rev(char *line, t_list **a, t_list **b)
{
	if (!ft_strncmp(line, "rra\n", 4))
		m_rev_rotate(a, 3);
	else if (!ft_strncmp(line, "rrb\n", 4))
		m_rev_rotate(b, 3);
	else
		m_rrr(a, b, 3);
}
