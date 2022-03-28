/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:53:59 by gmeoli            #+#    #+#             */
/*   Updated: 2022/03/28 19:43:41 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	ft_printf("%s ERROR!\n", str);
	exit(0);
}

void	ft_print_struct(t_game *guido)
{
	int	row;

	row = 0;
	write(1, "\nSTART!\n", 8);
	ft_printf("Height: %d\n", guido->height);
	ft_printf("Width: %d\n", guido->width);
	while (guido->matrix[row] != NULL)
	{
		ft_printf("%s\n", guido->matrix[row]);
		row++;
	}
}

void	end_game(t_game *guido)
{
	mlx_destroy_window(guido->mlx, guido->win);
	ft_free_matrix(guido);
	exit(0);
}

void	ft_free_matrix(t_game *guido)
{
	int	row;

	row = 0;
	while (row < guido->height)
	{
		free(guido->matrix[row]);
		row++;
	}
	free(guido->matrix);
}

t_game	ft_allocs_struct()
{
	t_game	guido;

	guido.c = 0;
	guido.e = 0;
	guido.height = 0;
	guido.matrix = 0;
	guido.mlx = NULL;
	guido.move_count = 0;
	guido.p = 0;
	guido.width = 0;
	guido.win = NULL;
	guido.x_player = 0;
	guido.y_player = 0;

	return (guido);
}