/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:41:27 by diomarti          #+#    #+#             */
/*   Updated: 2022/11/28 13:53:54 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%c
void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

//%s
void	ft_putstring(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i], len);
		i++;
	}
}
