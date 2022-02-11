/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:49:18 by gmeoli            #+#    #+#             */
/*   Updated: 2022/02/11 17:44:08 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*reverse(char *str)
{
	char	*ritorno;
	int		i;
	int		len;

	len = ft_strlen(str);
	if (len == 1)
		return (str);
	i = 0;
	ritorno = (char *)malloc(sizeof(char) * len + 1);
	if (!ritorno)
		return (NULL);
	while (len--)
	{
		ritorno[i] = str[len];
		i++;
	}
	ritorno[i] = 0;
	while (len != i)
	{
		str[len] = ritorno[len];
		len++;
	}
	str[len] = 0;
	free(ritorno);
	return (str);
}

int	ft_pointer(unsigned long int x)
{
	int		rest;
	int		i;
	char	*result;
	int		count;

	i = 0;
	rest = 0;
	count = 0;
	result = malloc(sizeof(char) * 35);
	if (x == 0)
	{
		free(result);
		return (write (1, "0x0", 3));
	}
	count += write(1, "0x", 2);
	while (x > 0)
	{
		result[i++] = "0123456789abcdef"[x % 16];
		x = x / 16;
	}
	result[i] = 0;
	count += ft_putstr(reverse(result));
	free(result);
	return (count);
}
