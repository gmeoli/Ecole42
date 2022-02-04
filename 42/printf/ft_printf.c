/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:41:23 by gmeoli            #+#    #+#             */
/*   Updated: 2022/01/22 23:32:36 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_identifier(char c, va_list arg, t_struct *params)
{
	char	*dbase;

	if (params)
	dbase = "0123456789";
	if (c == 'c')
		ft_putchar(va_arg(arg, int));
	/*else if (c == 's')
		ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		ft_putnumber_base(va_arg(arg, long long int), dbase, params);
	else if (c == 'd')
		ft_putnumber_base(va_arg(arg, int), dbase, params);
	else if (c == 'i')
		ft_resolve_i
	else if (c == 'u')9
		ft_resolve_u
	else if (c =='x')
		ft_resolve_x
	else if (c == 'X')
		ft_resolve_X
	else if (c == '%')
		ft_resolvemodule*/
}

int	ft_checkflags(const char *str, t_struct *params)
{
	int	i;

	i = 0;
	while (ft_checkidentifier(str[i]) == 0) 
	{
		if (str[i] == '-')
			params -> minus = 1;
		if (str[i] == '0')
			params -> zero = 1;
		if (str[i] == '.')
			ft_precision(str, i, params);
		if (ft_isdigit(str[i]) && params -> precision == 0)
		{
			params -> width *= 10;
			params -> width += str[i] - '0';
		}
		if (str[i] == '#')
			params -> hash = 1;
		if (str[i] == ' ')
			params -> space = 1;
		if (str[i] == '+')
			params -> plus = 1;
		i++;
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	int			i;
	t_struct	params;
	

	va_start(arg, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			//ft_struct_init(&params);
			//i += ft_checkflags(str + i + 1, &params);
			ft_identifier(str[i + 1], arg, &params);
		}
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	main()
{
	//char	*s = "ciao";
	int		num;
	char	c;

	num = 125;
	c = 'a';
	//printf("ciao stronzi %-10.15d", num, s);
	ft_printf("ciao stronzi %c", c);
}

void	ft_print_params(t_struct *params)
{
	printf("%d\n", params -> minus);
	printf("%d\n", params -> zero);
	printf("%d\n", params -> hash);
	printf("%d\n", params -> space);
	printf("%d\n", params -> plus);
	printf("%d\n", params -> width);
	printf("%d\n", params -> precision);
}
