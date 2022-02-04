/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scien_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:29:28 by abertill          #+#    #+#             */
/*   Updated: 2021/12/12 21:38:24 by abertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	write_dict(char *buff, int i);
void	jump_to_printable(char *buff, int i);

// calcola gli zeri da cercare
int	zeros(int j, int z, char **argv)
{
	if (j > 2 && (j % 3) == 0 && argv[1][j] == '0'
		&& argv[1][j -1] == '0' && (argv[1][j -2] >= '1'
			&& argv[1][j -2] <= '9'))
		z = j - (j % 3);
	if ((j > 2 && ((j % 3) == 0 || (j % 3) == 1)))
		z = j - (j % 3);
	else if ((j > 2 && (j % 3) == 2) || j == 2)
		z = 2;
	else if (j == 2)
		z = 2;
	return (z);
}

// stampa 
void	zeros_found(char *buff, int i)
{
	i += 2;
	jump_to_printable(buff, i);
	write_dict(buff, i);
}

// cerca gli zeri nel buff e stampali con jump_to e write
void	search_zeros(char *buff, int z)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < 691)
	{	
		if (buff[i] != '0')
			i++;
		else if (buff[i] == '0' && (buff [i -1] == '1' || buff [i -1] == '0'))
		{
			k++;
			if (k == z)
			{
				zeros_found(buff, i);
				break ;
			}
			else if (buff[i +1] != '0' )
				k = 0;
			i++;
		}
		else
			i++;
	}
}

// funzione per scrivere million, billion, etc
void	scien_n(char *buff, int i, char **argv)
{
	int	z;

	z = 0;
	z = zeros(i, z, argv);
	search_zeros(buff, z);
}

int	billion(char **argv, int j)
{
	if (j % 3 == 0 && argv[1][j] == '0' && argv[1][j +1] == '0'
			&& (argv[1][j +2] >= '1' && argv[1][j +2] <= '9'))
		return (1);
	else
		return (0);
}
