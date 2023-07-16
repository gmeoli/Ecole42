/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:18:10 by masebast          #+#    #+#             */
/*   Updated: 2022/01/25 12:33:24 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	size;
	char	*result;

	if (!s1 || !set)
	{
		return (NULL);
	}
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
	}
	size = ft_strlen(s1);
	while (size && ft_strchr(set, s1[size]))
	{
		size--;
	}
	result = ft_substr((char *)s1, 0, size + 1);
	return (result);
}
