/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:56:13 by masebast          #+#    #+#             */
/*   Updated: 2022/01/17 16:11:12 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
	{
		i++;
	}
	if ((char) *(s + i) == (char)c)
	{
		return ((char *)(s + i));
	}
	return (NULL);
}
