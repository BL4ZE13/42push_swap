/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:51:37 by diomarti          #+#    #+#             */
/*   Updated: 2023/03/15 14:46:28 by diomarti         ###   ########.fr       */
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
