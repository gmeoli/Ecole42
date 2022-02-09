/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:49:18 by gmeoli            #+#    #+#             */
/*   Updated: 2022/02/09 18:47:26 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// int ft_atoi(char *str)
// {
// 	int	i;
// 	int	somma;
// 	int	segno;

// 	segno = 1;
// 	somma = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		while (str[i] >= 9 && str[i] <= 13 || str[i] == 32)
// 			i++;
// 		while (str[i] == 43 || str[i] == 45)
// 		{
// 			if (str[i] == 45)
// 				segno *= -1;
// 			i++;
// 		}
// 		while (str[i] >= 48 && str[i] <= 57)
// 		{
// 			somma = somma * 10 + str[i] - '0';
// 			i++;
// 		}
// 		return (somma * segno);
// 	}
// 	return (0);
// }

// int	ft_pointer(char *base)
// {
// 	int	i;
// 	int	atoi;

// 	i = 0;
// 	atoi = ft_atoi(base);
// 	if (!base)
// 	{
// 		write(1, "(null)", 6);
// 		return (6);
// 	}
// 	write(1, "0x", 2);
// 	while (base[i])
// 	{
		
// 	}
// }