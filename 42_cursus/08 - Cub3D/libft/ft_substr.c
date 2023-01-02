/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:52:33 by ebondi            #+#    #+#             */
/*   Updated: 2022/10/15 19:32:06 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*r;

	if (!s)
		return (NULL);
	if (ft_strlen(s) > len)
		i = len;
	else
		i = ft_strlen(s);
	r = (char *)malloc(i + 1);
	if (!r)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			r[j] = s[i];
		if (i >= start && j < len)
			j++;
		i++;
	}
	r[j] = 0;
	return (r);
}
