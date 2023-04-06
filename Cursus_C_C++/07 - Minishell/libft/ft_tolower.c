/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:47:16 by masebast          #+#    #+#             */
/*   Updated: 2022/01/14 11:52:58 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int	result;

	result = c;
	if (c >= 'A' && c <= 'Z')
	{
		result = c + 32;
		return (result);
	}
	else
	{
		return (result);
	}
}
