/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:28:31 by ebondi            #+#    #+#             */
/*   Updated: 2022/01/19 14:45:02 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	const char		*source;

	if (!dst && !src)
		return (NULL);
	dest = dst;
	source = src;
	while (n > 0)
	{
		*dest++ = *source++;
		n--;
	}
	return (dst);
}
