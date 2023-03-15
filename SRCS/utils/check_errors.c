/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:20:56 by diomari           #+#    #+#             */
/*   Updated: 2023/03/15 14:45:56 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	check_dup(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_valid(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < INT_MIN || ft_atoi(argv[i]) > INT_MAX)
			exit(write(2, "Error\n", 6));
		i++;
	}
	return (1);
}

int	check_signal(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((ft_isdigit(argv[i][j]))
				|| (argv[i][0] == '-' && ft_isdigit(argv[i][1]))))
				exit(write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
	return (1);
}

int	check_all(int argc, char **argv)
{
	if (check_dup(argc, argv) != 1)
		exit(write(2, "Error\n", 6));
	if (check_valid(argc, argv) != 1)
		exit(write(2, "Error\n", 6));
	if (check_signal(argc, argv) != 1)
		exit(write(2, "Error\n", 6));
	return (1);
}
