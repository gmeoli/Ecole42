/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:18:31 by gmeoli            #+#    #+#             */
/*   Updated: 2022/03/19 14:31:44 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct	s_game {
	char	**matrix;
	int		width;
	int		height;
	void	*mlx;
	void	*win;
}	t_game;

int	ft_fill_matrix(char *maps, &guido);
int	ft_height(char *maps);
int	ft_width(char *maps);


#endif
