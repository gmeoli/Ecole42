/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:29:50 by abertill          #+#    #+#             */
/*   Updated: 2021/12/12 22:00:34 by abertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	scien_n(char *buff, int j, char **argvj);
int		billion(char **argv, int j);

// trova il testo del numero
int	jump_to_printable(char *buff, int i)
{
	i += 1;
	while (buff[i] != '\0')
	{
		if (buff[i] == ' ' || buff[i] == ':')
			i++;
		else
			return (i);
	}
	return (i);
}

// scrivi il testo del numero
void	write_dict(char *buff, int i)
{
	char	c;

	while (buff[i] >= 32 && buff[i] <= 127)
	{
		c = buff[i];
		write(1, &c, 1);
		i++;
	}
}

void	print_nbr1_9(char *buff, char **argv, int j)
{
	int	i;

	i = 1;
	while (i <= 691)
	{	
		if (buff[i] == argv[1][j] && buff[i -1] < 48 && buff[i +1] > 57)
		{	
			i = jump_to_printable(buff, i);
			write_dict(buff, i);
		}
		i++;
	}
}

// printa i numeri dal dieci al venti, e le decine
void	print_nbr10_20(char *buff, char **argv, int j, char j_pre)
{
	int	i;

	i = 1;
	while (i <= 691)
	{
		if (buff[i] == argv[1][j] && buff[i +1] == j_pre &&
			buff[i -1] < 48 && buff[i +2] > 57)
		{
			i += 1;
			i = jump_to_printable(buff, i);
			write_dict(buff, i);
		}
		i++;
	}
}

// funzione generale per stampare le a coppie di tre
int	triple(char *buff, char **argv, int j)
{
	char	j_prev;

	if (billion(argv, j) == 1)
		scien_n(buff, j, argv);
	if ((j % 3 == 0 || j % 3 == 2) && argv[1][j] != '0')
	{
		print_nbr1_9(buff, argv, j);
		scien_n(buff, j, argv);
	}
	if (j % 3 == 1 && argv[1][j] != '0')
	{
		if ((argv[1][j -1]) == '0' || argv[1][j] == '1')
		{	
			j_prev = argv[1][j -1];
			print_nbr10_20(buff, argv, j, j_prev);
			scien_n(buff, j, argv);
			return (1);
		}
		else if (argv[1][j] > '1' && argv[1][j] <= '9')
		{
			j_prev = '0';
			print_nbr10_20(buff, argv, j, j_prev);
		}
	}
	return (0);
}
