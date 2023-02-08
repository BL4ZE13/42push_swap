/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:42:25 by diomarti          #+#    #+#             */
/*   Updated: 2023/02/08 17:16:20 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_list(t_list **s, int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		ft_lstadd_back(s, ft_lstnew(ft_atoi(argv[i])));
	}
}

/* void	call_case(t_list **a, t_list **b, int argc)
{
	if (argc == 3)
		alg_2(a);
	if (argc == 4)
		alg_3(a);


	
}	
 */

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	
	a = NULL;
	b = NULL;
	check_all(argc, argv);
	put_list(&a, argc, argv);
	ft_printf("A: ");
	print_lst(&a);
	ft_printf("B: ");
	print_lst(&b);
	ft_printf("\n/////////\n");
	alg_5(&a, &b);
	ft_printf("A: ");
	print_lst(&a);
	ft_printf("\nB: ");
	print_lst(&b);
	ft_printf("\n");
	ft_printf("Is sorted: ");
	if (is_sort(&a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear(&a);
	ft_lstclear(&b);
}

