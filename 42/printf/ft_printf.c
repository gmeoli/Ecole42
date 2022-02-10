/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:41:23 by gmeoli            #+#    #+#             */
/*   Updated: 2022/02/10 18:29:16 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			w;
	int			len;

	w = 0;
	len = 0;
	va_start(args, str);
	while (str[w])
	{
		if (str[w] == '%')
		{
			ft_print_args(&len, str[w + 1], args);
			w++;
		}
		else
		{
			write(1, &str[w], 1);
			len++;
		}
		w++;
	}
	va_end (args);
	return (len);
}

void	ft_print_args(int *len, char c, va_list args)
{
	if (c == 'c')
	{
		ft_putchar(va_arg(args, int));
		*len = *len + 1;
	}
	else if (c == 's')
		*len += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		*len += ft_pointer(va_arg(args, unsigned long int));			
	else if (c == 'd' || c == 'i')
		*len += ft_decimal(va_arg(args, int));
	else if (c == 'x')
		*len += ft_hexa_min(va_arg(args, unsigned int));
	else if (c == 'X')
		*len += ft_hexa_maiu(va_arg(args, unsigned int));
	else if (c == '%')
	{
		ft_putchar('%');
		*len = *len + 1;
	}
}

/*
int  main()
{
	ft_printf("MIO -> %d\n", 4);
	printf("ORIGINAL -> %d\n", 4);
	return (0);
}
*/