/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:55:03 by ebondi            #+#    #+#             */
/*   Updated: 2022/01/12 16:45:10 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*a;
	const char	*b;

	i = 0;
	a = s1;
	b = s2;
	while (i < n)
	{
		if (a[i] != b[i])
			return (*(unsigned char *)(a + i) - *(unsigned char *)(b + i));
		i++;
	}
	return (0);
}
