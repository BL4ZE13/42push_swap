/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:40:28 by diomarti          #+#    #+#             */
/*   Updated: 2023/03/11 16:40:28 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	result_line(char *line, t_list **a, t_list **b)
{
	if (!ft_strncmp(line, "sa\n", 3) || !ft_strncmp(line, "sb\n", 3) ||
		!ft_strncmp(line, "ss\n", 3))
		check_swap(line, a, b);
	else if (!ft_strncmp(line, "pa\n", 3) || !ft_strncmp(line, "pb\n", 3))
		check_push(line, a, b);
	else if (!ft_strncmp(line, "rra\n", 4) || !ft_strncmp(line, "rrb\n", 4) ||
		!ft_strncmp(line, "rrr\n", 4))
		check_rev(line, a, b);
	else if (!ft_strncmp(line, "ra\n", 3) || !ft_strncmp(line, "rb\n", 3) ||
		!ft_strncmp(line, "rr\n", 3))
		check_rot(line, a, b);
	else
		exit(write(2, "Error\n", 6));
}

void	put_list_bonus(t_list **s, int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		ft_lstadd_back(s, ft_lstnew(ft_atoi(argv[i])));
}

void	read_line(char *line, t_list **a, t_list **b)
{
	line = get_next_line(0);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			exit(write(2, "Error\n", 6));
		}
		result_line(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	if (is_sort(a) && ft_lstsize(*b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*line;

	if (argc == 1 || ft_strlen(argv[1]) == 0)
		return (0);
	else if (check_all(argc, argv) != 1)
		exit(write(2, "Error\n", 6));
	a = NULL;
	b = NULL;
	line = NULL;
	put_list_bonus(&a, argc, argv);
	read_line(line, &a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
