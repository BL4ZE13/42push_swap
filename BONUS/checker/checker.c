/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiguel- <tmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:20:03 by tmiguel-          #+#    #+#             */
/*   Updated: 2023/03/01 10:20:03 by tmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	check_moves(char *moves)
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
		else
			exit(write(2, "Error\n", 6));
		return (c);
	}
	return (5);
}

static void do_moves(char *moves, t_list **a, t_list **b)
{
	int	c;

	c = check_moves(moves);
	if (c == 1)
		check_push(moves, a, b);
	if (c == 2)
		check_rev(moves, a, b);
	if (c == 3)
		check_rot(moves, a, b);
	if (c == 4)
		check_swap(moves, a, b);
}

void	read_line(char *moves, t_list **a, t_list **b)
{
	moves = get_next_line(0);
	while (moves)
	{
		if (moves[0] == '\n')
		{
			free(moves);
			exit(write(2, "Error\n", 6));
		}
		do_moves(moves, a, b);
		free(moves);
		moves = get_next_line(0);
	}
	if (is_sort(a) == 1 && ft_lstsize(*b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	put_list_bonus(t_list **s, int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		ft_lstadd_back(s, ft_lstnew(ft_atoi(argv[i])));
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*moves;

	if (argc == 1 || ft_strlen(argv[1]) == 0)
		return (0);
	else if (check_all(argc, argv) != 1)
		exit(write(2, "Error\n", 6));
	a = NULL;
	b = NULL;
	moves = NULL;
	put_list_bonus(&a, argc, argv);
	read_line(moves, &a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
