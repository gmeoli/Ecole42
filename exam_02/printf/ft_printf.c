/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:30:50 by gmeoli            #+#    #+#             */
/*   Updated: 2022/02/22 17:58:40 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int ft_decimal(int x)
{
	int	count;

	count = 0;
	if (x == -2147483648)
	{
		count = write(1, "-2147483648", 12);
		return (count);
	}
	if (x < 0)
	{
		count += write(1, "-", 1);
		x *= -1;
	}
	if (x >= 10)
	{
		count += ft_decimal( x / 10);
		x = x % 10;
	}
	if (x < 10)
		ft_putchar(x + 48);
	return (count);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_hexa(unsigned int x)
{
	int		i;
	char	*base;
	char	*result;
	int		count;
	int		len;

	i = 0;
	len = 0;
	count = 0;
	base = "0123456789abcdef";
	result = (char *)malloc(sizeof(char) * 35);
	if (x == 0)
	{
		free(result);
		return(write(1, "0", 1));
	}
	while (x > 0)
	{
		result[i] = base[x % 16];
		x /= 16;
		i++;
	}
	len = ft_strlen(result);
	while (len >= 0)
	{
		count += write(1, &result[len], 1);
		len--;
	}
	free(result);
	return (count);
}

void	ft_printf_args(int *len, char c, va_list args)
{
	if (c == 's')
		*len += ft_putstr(va_arg(args, char *));
	else if (c == 'd')
		*len += ft_decimal(va_arg(args, int));
	else if (c == 'x')
	 	*len += ft_hexa(va_arg(args, unsigned int));
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			len;
	int 		i;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_printf_args(&len, str[i + 1], args);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end (args);
	return (len);
}