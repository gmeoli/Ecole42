/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:08:15 by ebondi            #+#    #+#             */
/*   Updated: 2022/01/17 02:23:22 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoadue(char *a, long b, int len, int sign)
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
