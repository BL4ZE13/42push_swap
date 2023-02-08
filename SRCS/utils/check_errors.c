/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:20:56 by diomari           #+#    #+#             */
/*   Updated: 2023/02/08 17:19:09 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int check_dup(int argc, char **argv)
{
	int	i;
	int	j;
	
	i = 0;
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
	if (argc == 1)
		exit(write(2, "Error\n", 6));
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < INT_MIN || ft_atoi(argv[i]) > INT_MAX)
			exit(write(2, "Error\n", 6));
		i++;		
	}
	return (1);
}

int check_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				exit(write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
	return (1);
}

int	check_signal(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	(void)argc;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				exit(write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
	return (1);
}

int	check_all(int argc, char **argv)
{
	if (check_signal(argc, argv) != 1)
		exit(write(2, "Error\n", 6));
	else if (check_digit(argc, argv) != 1)
		exit(write(2, "Error\n", 6));
	else if (check_valid(argc, argv) != 1)
		exit(write(2, "Error\n", 6));
	else if (check_dup(argc, argv) != 1)
		exit(write(2, "Error\n", 6));
	return (1);	
}
