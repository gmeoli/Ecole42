/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:49:04 by gmeoli            #+#    #+#             */
/*   Updated: 2022/03/20 17:45:38 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_width(char *maps)
{
	int		fd;
	char	*result;
	int		width;

	width = 0;
	fd = open(maps, O_RDONLY);
	if (!fd)
		return (0);
	result = get_next_line(fd);
	width = ft_strlen(result) - 1;
	free(result);
	close(fd);
	return (width);
}

int	ft_height(char *maps)
{
	int		fd;
	char	*result;
	int		height;

	result = 0;
	height = 0;
	fd = open(maps, O_RDONLY);
	if (!fd)
		return (0);
	result = get_next_line(fd);
	while (result != NULL)
	{
		height++;
		free(result);
		result = get_next_line(fd);
	}
	free(result);
	close(fd);
	return (height);
}

int	ft_fill_matrix(char *maps, t_game *guido)
{
	int	i;

	i = 0;
	guido->height = ft_height(maps);
	guido->width = ft_width(maps);	
	if (!guido->height || !guido->width)
		return (0);
	guido->matrix = malloc(sizeof(char **) * guido->height + 1);
	guido->matrix[guido->height] = NULL;
	while (i < guido->height)
	{
		guido->matrix[i] = malloc(sizeof(char *) * guido->width + 1);
		guido->matrix[i][guido->width] = '\0';
		i++;
	}
	return(1);
}
