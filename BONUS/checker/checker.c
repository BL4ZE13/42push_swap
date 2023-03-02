/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:35:53 by diomarti          #+#    #+#             */
/*   Updated: 2023/02/27 14:25:32 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	check_moves(char *moves, int o)
{
	int c;

	if (moves)
	{
		c = 0;
		if (!(ft_strncmp(moves, "pa\n", 3)) || !(ft_strncmp(moves, "pb\n", 3)))
			c += 1;
		if (!(ft_strncmp(moves, "rra\n", 4)) || !(ft_strncmp(moves, "rrb\n", 4))
			|| !(ft_strncmp(moves, "rrr\n", 4)))
			c += 2;
		if (!(ft_strncmp(moves, "ra\n", 3)) || !(ft_strncmp(moves, "rb\n", 3))
			|| !(ft_strncmp(moves, "rr\n", 3)))
			c += 3;
		if (!(ft_strncmp(moves, "sa\n", 3)) || !(ft_strncmp(moves, "sb\n", 3))
			|| !(ft_strncmp(moves, "ss\n", 3)))
			c += 4;
		if (c == 0 && o == 1)
			exit(write(2, "Error\n", 6));
		return (c);
	}
	return (5);
}

static void do_moves(char *moves, t_list **a, t_list **b)
{
	int	c;

	c = check_moves(moves, 0);
	if (c == 1)
		check_p(moves, a, b);
	if (c == 2)
		check_rev(moves, a, b);
	if (c == 3)
		check_rot(moves, a, b);
	if (c == 4)
		check_s(moves, a, b);
}

static void check_sort(t_list *a, t_list *b, t_chercker *checks)
{
	if (check_moves((*checks).moves, 0) != 0)
	{
		if (is_sort(&a) && ft_lstsize(b) == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	free((*checks).moves);
}

static void	put_stack(t_list **a, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
}

int main(int argc, char **argv)
{
	t_list 		*a;
	t_list 		*b;
	t_chercker	checks;

	if (check_all(argc, argv) || argc < 3)
		return (0);
	checks.c = 1;
	checks.moves = malloc(5);
	if (!checks.moves)
		return (0);
	ft_initialize_lst(&a, &b);
	put_stack(&a, argc, argv);
	while (checks.c != 0)
	{
		free(checks.moves);
		checks.moves = get_next_line(0);
		if (check_moves(checks.moves, 1) == 0)
			break ;
		do_moves(checks.moves, &a, &b);
		if (check_moves(checks.moves, 0) == 5 || checks.moves == NULL)
			checks.c = 0;		
	}
	check_sort(a, b, &checks);
	ft_clear_all(&a, &b);
	return (0);
}
