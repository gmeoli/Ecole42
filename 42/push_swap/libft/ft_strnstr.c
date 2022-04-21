/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:17:32 by gmeoli            #+#    #+#             */
/*   Updated: 2022/01/20 18:59:07 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	a;

	i = 0;
	j = 0;
	a = 0;
	if (*n == 0)
		return ((char *)h);
	while (h[i] && i < len)
	{
		while (h[i] == n[j] && h[i] && i < len && n[j])
		{
			i++;
			j++;
			if (n[j] == '\0')
				return ((char *)(h + (i - j)));
		}
		j = 0;
		a++;
		i = a;
	}
	return (NULL);
}
