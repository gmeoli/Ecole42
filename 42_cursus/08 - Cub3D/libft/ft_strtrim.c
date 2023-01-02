/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:40:13 by ebondi            #+#    #+#             */
/*   Updated: 2022/12/09 17:50:53 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_checkset(char s, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	c;
	int	k;

	if (!s1 || !set)
		return (NULL);
	c = 0;
	while (ft_checkset(s1[c], (char *)set))
		c++;
	k = ft_strlen(s1);
	while (ft_checkset(s1[k -1], (char *)set) && k > c)
		k--;
	return (ft_substr((char *)s1, c, k - c));
}
