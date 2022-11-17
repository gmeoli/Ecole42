/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:07:44 by masebast          #+#    #+#             */
/*   Updated: 2022/01/17 16:30:43 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == 0)
	{
		return ((char *)(haystack));
	}
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[j] && haystack[i + j]
			&& needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
			{
				return ((char *)(haystack + i));
			}
		}
		i++;
		j = 0;
	}
	return (NULL);
}
