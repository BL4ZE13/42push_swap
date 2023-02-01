/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:42:25 by diomarti          #+#    #+#             */
/*   Updated: 2023/02/01 17:20:16 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	int i;
	
	a = NULL;
	b = NULL;
	i = 0;
	while (++i < argc)
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i])));
		// ft_lstadd_back(&b, ft_lstnew(ft_atoi(argv[i])));
	}
	ft_printf("A: ");
	print_lst(&a);
	ft_printf("B: ");
	print_lst(&b);
	ft_printf("\n/////////\n");
	m_push(&a, &b, 1);
	m_push(&a, &b, 1);
	ft_printf("A: ");
	print_lst(&a);
	ft_printf("B: ");
	print_lst(&b);
	ft_lstclear(&a);
	ft_lstclear(&b);
}

