/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:20:20 by diomarti          #+#    #+#             */
/*   Updated: 2023/01/31 16:50:35 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*last_node;

	if (!lst || !new_node)
		return NULL;
	if (!*lst)
		*lst = new_node;
	else
	{
		last_node = ft_lstlast(*lst);
		last_node->next = new_node;
	}
	return (new_node);
}
