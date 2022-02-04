/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:44:53 by gmeoli            #+#    #+#             */
/*   Updated: 2021/12/15 22:38:11 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*pippo;
	int	i;

	i = 0;
	pippo = malloc(sizeof(int) * (max - min));
	if (min >= max || pippo == NULL)
	{
		pippo = NULL;
		return (pippo);
	}
	while (min < max)
	{
		pippo[i] = min;
		min++;
		i++;
	}
	return (pippo);
}
