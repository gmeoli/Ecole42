/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:21:00 by masebast          #+#    #+#             */
/*   Updated: 2022/01/17 13:28:10 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	x;
	size_t	y;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	x = dst_len;
	y = 0;
	if (dst_len >= dstsize)
	{
		dst_len = dstsize;
	}
	if (dst_len < dstsize - 1 && dstsize > 0)
	{
		while (src[y] && dst_len + y < dstsize - 1)
		{
			dst[x] = src[y];
			x++;
			y++;
		}
		dst[x] = 0;
	}
	return (dst_len + src_len);
}
