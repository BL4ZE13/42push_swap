/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:13:08 by diomarti          #+#    #+#             */
/*   Updated: 2023/01/24 18:24:23 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#	define PUSH_SWAP_H

//includes

#	include <stdio.h>
#	include <string.h>
#	include <stdlib.h>
#	include "../libft/libft.h"
#	include "../ft_printf/ft_printf.h"

//lists
typedef struct s_stack
{
	struct s_list *a;
	struct s_list *b;
}						t_stack;


//functions
void	m_sa(t_stack *s);
void	m_sb(t_stack *s);
void	m_ss(t_stack *s);
void	m_pa(t_stack *s);
void	m_pb(t_stack *s);
void	m_ra(t_stack *s);
void	m_rb(t_stack *s);
void	m_rr(t_stack *s);
void	m_rra(t_stack *s);
void	m_rrb(t_stack *s);
void	m_rrr(t_stack *s);


#	endif