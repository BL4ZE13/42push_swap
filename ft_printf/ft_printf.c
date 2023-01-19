/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:46:10 by diomarti          #+#    #+#             */
/*   Updated: 2022/11/29 12:07:34 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_check(char c, va_list args, int *len, int i)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (c == 's')
		ft_putstring(va_arg(args, char *), len);
	else if (c == 'p')
		ft_puthadress(va_arg(args, unsigned long), len);
	else if (c == 'd')
		ft_putint(va_arg(args, int), len);
	else if (c == 'i')
		ft_putint(va_arg(args, int), len);
	else if (c == 'u')
		ft_putuns(va_arg(args, unsigned int), len);
	else if (c == 'x')
		ft_puthexa(va_arg(args, unsigned int), len, "0123456789abcdef");
	else if (c == 'X')
		ft_puthexa(va_arg(args, unsigned int), len, "0123456789ABCDEF");
	else if (c == '%')
		ft_putchar('%', len);
	else
		i--;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			format_check(format[i], args, &len, i);
			i++;
		}
		else
		{
			ft_putchar((char)format[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}

int main()
{
	ft_printf("%x\n", LONG_MAX);
	printf("%lx\n", LONG_MAX);
}