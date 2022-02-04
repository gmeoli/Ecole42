/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:18:55 by gmeoli            #+#    #+#             */
/*   Updated: 2021/12/06 20:19:40 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	cap;

	i = 0;
	cap = 1;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9')
			|| (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (cap && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 32;
			else if (!cap && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] += 32;
			cap = 0;
		}
		else
		{
			cap = 1;
		}
		i++;
	}
	return (str);
}
