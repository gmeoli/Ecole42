/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:53:22 by gmeoli            #+#    #+#             */
/*   Updated: 2021/12/14 15:26:50 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	carattere(char c)
{
	write(1, &c, 1);
}

void	stringa(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		carattere(str[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	n;

	n = 1;
	while (n < argc)
	{
		stringa(argv[n]);
		n++;
		carattere('\n');
	}
}
