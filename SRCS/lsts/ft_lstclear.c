/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:19:16 by diomarti          #+#    #+#             */
/*   Updated: 2023/02/01 14:36:41 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*lst1;

	if (!*lst || !lst)
		return ;
	while (*lst)
	{
		lst1 = (*lst)->next;
		free(*lst);
		*lst = lst1;
	}
	free(lst1);
}
