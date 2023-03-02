/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:35:58 by diomarti          #+#    #+#             */
/*   Updated: 2023/02/24 16:39:46 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_clear_all(t_list **a, t_list **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
}

void	ft_initialize_lst(t_list **a, t_list **b)
{
	*a = NULL;
	*b = NULL;	
}
