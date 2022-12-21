/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:15:25 by saazcon-          #+#    #+#             */
/*   Updated: 2022/11/18 19:06:28 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pointer(void *p)
{
	size_t	nbr;

	nbr = (size_t)p;
	write(1, "0x", 2);
	return (ft_putptr_base(nbr) + 2);
}

static int	ft_format(va_list args, char valor)
{
	int	n;

	n = 0;
	if (valor == '%')
		n = n + ft_putchar('%');
	else if (valor == 'c')
		n = n + ft_putchar(va_arg(args, int));
	else if (valor == 's')
		n = n + ft_putstr(va_arg(args, char *));
	else if (valor == 'd' || valor == 'i')
		n = n + ft_putnbr(va_arg(args, int));
	else if (valor == 'p')
		n = n + ft_pointer(va_arg(args, void *));
	else if (valor == 'u')
		n = n + ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (valor == 'x')
		n = n + ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	else if (valor == 'X')
		n = n + ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
	return (n);
}

int	ft_printf(char const *valor, ...)
{
	va_list	args;
	int		n;
	int		i;

	n = 0;
	i = 0;
	va_start(args, valor);
	while (valor[i] != '\0')
	{
		if (valor[i] == '%')
		{
			i++;
			n = n + ft_format(args, valor[i]);
		}
		else
			n = n + write(1, &valor[i], 1);
		i++;
	}
	va_end(args);
	return (n);
}
