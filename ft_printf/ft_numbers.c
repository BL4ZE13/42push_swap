/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:48:17 by diomarti          #+#    #+#             */
/*   Updated: 2022/11/21 15:41:24 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%d,%i
void	ft_putint(int n, int *len)
{
	char	c;

	c = n + 48;
	if (n >= INT_MIN && n <= INT_MAX)
	{
		if (n > 9)
		{
			ft_putint(n / 10, len);
			ft_putint(n % 10, len);
		}
		else if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			(*len) += 11;
			return ;
		}
		else if (n < 0)
		{
			n = -n;
			ft_putchar('-', len);
			ft_putint(n, len);
		}
		else
			ft_putchar(c, len);
	}
}

//%u
void	ft_putuns(unsigned int n, int *len)
{
	if (n > 9)
		ft_putuns(n / 10, len);
	ft_putchar(((n % 10) + 48), len);
}

//%p hexa adress
void	ft_puthadress(unsigned long n, int *len)
{
	char	str[17];
	char	*h_base;
	int		i;

	i = 0;
	h_base = "0123456789abcdef";
	if (n == 0)
	{
		write(1, "(nil)", 5);
		(*len) += 5;
	}
	else
	{
		write(1, "0x", 2);
		(*len) += 2;
	}
	while (n != 0)
	{
		str[i] = h_base[n % 16];
		n /= 16;
		i++;
	}
	while (i--)
		ft_putchar(str[i], len);
}

//%x %X
void	ft_puthexa(unsigned int n, int *len, const char *c)
{
	char	str[17];
	int		i;

	i = 0;
	if (n == 0)
		ft_putchar('0', len);
	while (n != 0)
	{
		str[i] = c[n % 16];
		n /= 16;
		i++;
	}
	while (i--)
		ft_putchar(str[i], len);
}
