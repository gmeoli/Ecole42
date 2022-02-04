/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:54:24 by gmeoli            #+#    #+#             */
/*   Updated: 2022/01/22 23:32:33 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_struct_init(t_struct *params)
{
	params -> minus = 0;
	params -> zero = 0;
	params -> hash = 0;
	params -> space = 0;
	params -> plus = 0;
	params -> width = 0;
	params -> precision = 0;
}

int	ft_checkidentifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd'|| c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}
