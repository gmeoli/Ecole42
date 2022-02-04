/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:04:18 by gmeoli            #+#    #+#             */
/*   Updated: 2021/12/08 18:25:46 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	s_dest;
	unsigned int	s_src;

	s_dest = ft_strlen(dest);
	s_src = ft_strlen(src);
	i = 0;
	j = 0;
	if (size == 0)
		return (s_src);
	while (src[i] != 0 && s_dest + i < (size - 1))
	{
		dest[s_dest + i] = src[i];
		i++;
	}
	if (i < size)
		dest[s_dest + i] = 0;
	if (size > s_dest)
		return (s_src + s_dest);
	else
		return (s_src + size);
}
