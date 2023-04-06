/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:34:59 by gmeoli            #+#    #+#             */
/*   Updated: 2021/12/04 20:38:10 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	scrivi(char *c)
{
	write(1, &c, 1);
}

char	rush_01(char *in)  //motore del programma
{
/*
	int	i;
	int k;

	i = 0;
	k = 16
	while (k > 0)
	{
		if (in[i] = 1)
			out[i] = 4
				k--1  
*/
	int	r;
	int	c;
	char matrix[r][c];

	r = 0;
	c = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			write(1, "x ", 2);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}
