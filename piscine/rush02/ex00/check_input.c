/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:50:51 by abertill          #+#    #+#             */
/*   Updated: 2021/12/12 21:56:25 by abertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_argc(int argc)
{
	if (argc < 2 || argc > 3)
		return (0);
	return (1);
}

int	check_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if ((argv[1][i] < 48) || (argv[1][i] > 57))
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int	check_argv_max(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i] != '\0')
		i++;
	i -= 1;
	return (i);
}

int	conditions(int argc, char **argv)
{
	if (check_argc(argc) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (check_argv(argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (check_argv_max(argv) > 37)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (1);
}
