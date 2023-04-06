/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:14:00 by gmeoli            #+#    #+#             */
/*   Updated: 2021/12/13 21:39:08 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	fact;

	i = 1;
	fact = 1;
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		fact = fact * i;
		i++;
	}
	return (fact);
}
