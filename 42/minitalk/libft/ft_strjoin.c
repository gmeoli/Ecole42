/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 04:03:34 by gmeoli            #+#    #+#             */
/*   Updated: 2022/01/21 04:03:56 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*r;

	if (!s1 || !s2)
		return (NULL);
	r = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!r)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
	{
		r[j] = s1[i];
		j++;
	}
	i = -1;
	while (s2[++i])
	{
		r[j] = s2[i];
		j++;
	}
	r[j] = 0;
	return (r);
}
