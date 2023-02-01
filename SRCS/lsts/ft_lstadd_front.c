/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:12:40 by diomarti          #+#    #+#             */
/*   Updated: 2023/01/31 16:50:45 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_lstadd_front(t_list **lst, t_list *new_node)
{
	if (!lst || !new_node)
		return (0);
	new_node->next = *lst;
	*lst = new_node;
	return (1);
}
