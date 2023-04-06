/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:56:41 by gmeoli            #+#    #+#             */
/*   Updated: 2022/01/18 20:45:37 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	j = 0;
	if (size == 0)
		return (src_len);
	while (src[i] != 0 && dst_len + i < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (i < size)
		dst[dst_len + i] = 0;
	if (size > dst_len)
		return (src_len + dst_len);
	else
		return (src_len + size);
}
