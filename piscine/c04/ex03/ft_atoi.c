/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:14:37 by gmeoli            #+#    #+#             */
/*   Updated: 2021/12/10 21:40:47 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	somma;
	int	segno;

	segno = 1;
	somma = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] >= 9 && str[i] <= 13 || str[i] == 32)
			i++;
		while (str[i] == 43 || str[i] == 45)
		{
			if (str[i] == 45)
				segno *= -1;
			i++;
		}
		while (str[i] >= 48 && str[i] <= 57)
		{
			somma = somma * 10 + str[i] - '0';
			i++;
		}
		return (somma * segno);
	}
	return (0);
}
