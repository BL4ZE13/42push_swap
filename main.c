/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:42:25 by diomarti          #+#    #+#             */
/*   Updated: 2023/01/30 17:18:18 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list *a;
	//t_list *b;
	int i;
	(void)argc;
	
	a = NULL;
	i = 0;
	while (argv[i++])
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i])));
	//b = NULL;
	print_lst(&a);
}

