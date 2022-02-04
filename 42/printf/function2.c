/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 23:03:56 by gmeoli            #+#    #+#             */
/*   Updated: 2022/01/22 23:32:30 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_recursive(long long int n, char *base, int len)
{
	if (n < len)
		ft_putchar(base[n]);
	else
		{
			ft_recursive(n / len, base, len);
			ft_putchar(base[n % len] - '0');
		}
}

void	ft_putnumber_base(long long int n, char *base)
{
	int	len;
	if (n < 0)
	{
		n *= -1;
		write (1, "-", 1);
	}
	len = ft_strlen(base);
	ft_recursive(n, base, len);
}

/*static char	*ft_itoadue(char *a, long b, int len, int sign)
{
	if (!a)
		return (NULL);
	a[len] = 0;
	while (len)
	{
		len--;
		a[len] = (b % 10) + 48;
		b /= 10;
	}
	if (sign == 1)
		a[0] = '-';
	return (a);
}

char	*ft_itoa(int n)
{
	int		m;
	int		len;
	int		sign;
	char	*a;
	long	b;

	len = 1;
	m = 1;
	sign = 0;
	b = n;
	if (b < 0)
	{
		len++;
		b *= -1;
		sign = 1;
	}
	while ((b / m) > 9)
	{
		len++;
		m *= 10;
	}
	a = (char *)malloc(sizeof(char) * (len + 1));
	return (ft_itoadue(a, b, len, sign));
}

#include "printf.h"

void	ft_recursive(long long int n, char *base, int len)
{
	if (n >= len)
		ft_recursive(n / len, base, len);
	ft_putchar(base[n % len]);
}

void	ft_putnumber_base(long long int n, char *base)
{
	int	i;
	int	len;

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	len = ft_strlen(base);
	ft_recursive(n, base, len);
}*/
