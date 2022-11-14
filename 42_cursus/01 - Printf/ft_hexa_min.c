/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:01:31 by gmeoli            #+#    #+#             */
/*   Updated: 2022/02/11 18:51:36 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*reverse_min(char *str)
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

int	ft_hexa_min(unsigned int x)
{
	int		i;
	char	*result;
	char	*base;
	int		count;

	i = 0;
	count = 0;
	result = malloc(sizeof(char) * 35);
	base = "0123456789abcdef";
	if (x == 0)
	{
		free(result);
		return (write (1, "0", 1));
	}
	while (x > 0)
	{
		result[i++] = base[x % 16];
		x = x / 16;
	}
	result[i] = 0;
	count += ft_putstr(reverse_min(result));
	free(result);
	return (count);
}
