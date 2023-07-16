/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:15:44 by gmeoli            #+#    #+#             */
/*   Updated: 2021/12/13 22:17:13 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int n)
{
	int	i;

	i = 2;
	if (n <= 1)
		return (0);
	while (i <= n / i)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	is_prime;

	is_prime = ft_is_prime(nb);
	if (is_prime == 1)
		return (nb);
	else
		return (ft_find_next_prime(nb + 1));
}
