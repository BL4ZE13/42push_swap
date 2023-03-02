/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:51:37 by diomarti          #+#    #+#             */
/*   Updated: 2023/02/22 16:29:24 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	print_lst(t_list **stack)
{
	t_list	*cursor;

	cursor = *stack;
	while (cursor)
	{
		ft_printf("%d, ", cursor->content);
		cursor = cursor->next;
	}
}