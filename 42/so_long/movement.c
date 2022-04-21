/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:02:56 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/04 18:14:40 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_game *guido)
{
	if (guido->matrix[guido->y_player - 1][guido->x_player] != '1' \
		&& (guido->matrix[guido->y_player - 1][guido->x_player] != 'E' \
			|| guido->c == 0))
	{
		if (guido->matrix[guido->y_player - 1][guido->x_player] == 'C')
			guido->c--;
		if (guido->matrix[guido->y_player - 1][guido->x_player] == 'E')
			end_game(guido);
		guido->move_count += 1;
		guido->matrix[guido->y_player][guido->x_player] = '0';
		guido->matrix[guido->y_player - 1][guido->x_player] = 'P';
		guido->y_player -= 1;
	}
}

void	ft_move_right(t_game *guido)
{
	if (guido->matrix[guido->y_player][guido->x_player + 1] != '1' \
		&& (guido->matrix[guido->y_player][guido->x_player + 1] != 'E' \
			|| guido->c == 0))
	{
		if (guido->matrix[guido->y_player][guido->x_player + 1] == 'C')
			guido->c--;
		if (guido->matrix[guido->y_player][guido->x_player + 1] == 'E')
			end_game(guido);
		guido->move_count += 1;
		guido->matrix[guido->y_player][guido->x_player] = '0';
		guido->matrix[guido->y_player][guido->x_player + 1] = 'P';
		guido->x_player += 1;
	}
}

void	ft_move_left(t_game *guido)
{
	if (guido->matrix[guido->y_player][guido->x_player - 1] != '1' \
		&& (guido->matrix[guido->y_player][guido->x_player - 1] != 'E' \
			|| guido->c == 0))
	{
		if (guido->matrix[guido->y_player][guido->x_player - 1] == 'C')
			guido->c--;
		if (guido->matrix[guido->y_player][guido->x_player - 1] == 'E')
			end_game(guido);
		guido->move_count += 1;
		guido->matrix[guido->y_player][guido->x_player] = '0';
		guido->matrix[guido->y_player][guido->x_player - 1] = 'P';
		guido->x_player -= 1;
	}
}

void	ft_move_down(t_game *guido)
{
	if (guido->matrix[guido->y_player + 1][guido->x_player] != '1' \
		&& (guido->matrix[guido->y_player + 1][guido->x_player] != 'E' \
			|| guido->c == 0))
	{
		if (guido->matrix[guido->y_player + 1][guido->x_player] == 'C')
			guido->c--;
		if (guido->matrix[guido->y_player + 1][guido->x_player] == 'E')
			end_game(guido);
		guido->move_count += 1;
		guido->matrix[guido->y_player][guido->x_player] = '0';
		guido->matrix[guido->y_player + 1][guido->x_player] = 'P';
		guido->y_player += 1;
	}
}
