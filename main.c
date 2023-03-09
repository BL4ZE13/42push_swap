/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:42:25 by diomarti          #+#    #+#             */
/*   Updated: 2023/03/09 13:33:41 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_list(t_list **s, int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		ft_lstadd_back(s, ft_lstnew(ft_atoi(argv[i])));
}

void	call_case(t_list **a, t_list **b, int argc)
{
	if (is_sort(a))
		return ;
	if (argc == 3)
		alg_2(a);
	if (argc == 4)
		alg_3(a);
	if (argc == 5 || argc == 6)
		alg_5(a, b);
	if (argc > 6 && argc < 501)
		alg_100(a, b);
	if (argc >= 501)
		alg_500(a, b);
}	

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	
	a = NULL;
	b = NULL;
	if (check_all(argc, argv) != 1 || argc < 3)
		return (0);
	put_list(&a, argc, argv);
	get_index(&a);
	// ft_printf("A: ");
	// print_lst(&a);
	// ft_printf("\nB: ");
	// print_lst(&b);
	// ft_printf("\n////////////////////////////////\n");
	call_case(&a, &b, argc);
	// ft_printf("////////////////////////////////\n");
	// ft_printf("A: ");
	// print_lst(&a);
	// ft_printf("\nB: ");
	// print_lst(&b);
	// ft_printf("\n");
	// ft_printf("Is sorted: ");
	// if (is_sort(&a))
	// 	ft_printf("OK\n");
	// else
	// 	ft_printf("KO\n");
	ft_lstclear(&a);
	ft_lstclear(&b);
}

