/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:49:04 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/04 18:50:00 by gmeoli           ###   ########.fr       */
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

static void	ft_strcpy(char *matrix, const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		matrix[i] = str[i];
		i++;
	}
	matrix[i] = '\0';
}

void	ft_fill_matrix(char *maps, t_game *guido)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	guido->height = ft_height(maps);
	guido->width = ft_width(maps);
	guido->matrix = (char **)malloc(sizeof(char *) * guido->height + 1);
	guido->matrix[guido->height] = NULL;
	fd = open(maps, O_RDONLY);
	while (i < guido->height)
	{
		guido->matrix[i] = (char *)malloc(sizeof(char) * guido->width + 1);
		str = get_next_line(fd);
		ft_strcpy(guido->matrix[i], str);
		free(str);
		i++;
	}
	close (fd);
}
