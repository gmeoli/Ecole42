/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:46:48 by ebondi            #+#    #+#             */
/*   Updated: 2022/12/10 20:28:40 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}

int	check_name(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4 || str[len - 1] != 'b' || str[len - 2] != 'u' \
			|| str[len - 3] != 'c' || str[len - 4] != '.')
		return (1);
	return (0);
}
