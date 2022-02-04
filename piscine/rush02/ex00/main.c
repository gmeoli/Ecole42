/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:28:48 by abertill          #+#    #+#             */
/*   Updated: 2021/12/12 22:12:17 by abertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	read_dict(char *buff);
int		ft_strlen(char **argv);
void	print_nbr1_9(char *buff, char **argv, int j);
void	print_nbr10_20(char *buff, char **argv, int j, char j_prev);
char	ft_rev_argv(char **argv);
int		triple(char *buff, char **argv, int j);
int		num_argv(char **argv);
int		conditions(int argc, char **argv);

void	spaces(char **argv, int j)
{
	if (j >= 0 && argv[1][j] != '0')
		write(1, " ", 1);
	else if (j < 0)
		write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	char	*buff;
	int		j;
	int		x;

	if (conditions(argc, argv) == 0)
		return (0);
	buff = (char *)malloc(sizeof (char) * 691);
	read_dict(buff);
	j = num_argv(argv);
	ft_rev_argv(argv);
	if (j == 0 && argv[1][0] == '0')
		write (1, "zero", 4);
	while (j >= 0)
	{
		x = triple(buff, argv, j);
		if (x == 1)
		{
			j -= 2;
		}
		else if (x == 0)
			j--;
		spaces(argv, j);
	}
}
