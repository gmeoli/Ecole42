/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:31:49 by ebondi            #+#    #+#             */
/*   Updated: 2022/01/17 16:34:12 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	s_len;
	size_t	d_len;

	i = 0;
	s_len = ft_strlen(src);
	d_len = ft_strlen(dest);
	if (size == 0)
		return (s_len);
	while (src[i] != '\0' && (d_len + i) < (size - 1))
	{
		dest[d_len + i] = src[i];
		i++;
	}
	if (i != size && d_len < (size - 1))
		dest[d_len + i] = '\0';
	if (size > d_len)
		return (s_len + d_len);
	else
		return (s_len + size);
}
