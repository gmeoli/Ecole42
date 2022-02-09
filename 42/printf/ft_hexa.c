/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:01:31 by gmeoli            #+#    #+#             */
/*   Updated: 2022/02/09 19:02:54 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*reverse(char *str)
{
	char	*ritorno;
	int		i;
	int		len;

	len = ft_strlen(str);
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
	return (ritorno);
	free (ritorno);
}

char	*fill_base(char *exa)
{
	int i;
	i = 0;
	exa[i] = '0';
	exa[++i] = '1';
	exa[++i] = '2';
	exa[++i] = '3';
	exa[++i] = '4';
	exa[++i] = '5';
	exa[++i] = '6';
	exa[++i] = '7';
	exa[++i] = '8';
	exa[++i] = '9';
	exa[++i] = 'a';
	exa[++i] = 'b';
	exa[++i] = 'c';
	exa[++i] = 'd';
	exa[++i] = 'e';
	exa[++i] = 'f';
	exa[++i] = '\0';
	return (exa);
}

int	ft_hexa(unsigned long int x)
{
	int		rest;
	int		i;
	char	result[200];
	char	base[17];
	int		count;

	i = 0;
	rest = 0;
	fill_base(base);
	//write(1, "0x", 2);
	//count = 2;
	count = 0;
	if (x == 0)
		result[0] = '0';
	else
		while (x > 0)
		{
			rest = x % 16;
			result[i++] = base[rest];
			x = x / 16;
		}
	result[i] = 0;
	return (count += ft_putstr(reverse(result)));
}
