/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 03:59:10 by gmeoli            #+#    #+#             */
/*   Updated: 2022/01/21 16:27:14 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	int		j;
	size_t	a;
	char	*r;

	if (!s)
		return (NULL);
	if (ft_strlen(s) > len)
		a = len;
	else
		a = ft_strlen(s);
	r = ft_calloc(a + 1, sizeof(char));
	if (!r)
		return (NULL);
	i = -1;
	j = -1;
	while (s[++i])
		if (i >= (int)start && ++j < (int)len)
			r[j] = s[i];
	r[j + 1] = 0;
	return (r);
}
