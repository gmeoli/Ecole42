/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:29:09 by abertill          #+#    #+#             */
/*   Updated: 2021/12/12 19:44:30 by abertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i] != '\0')
		i++;
	return (i);
}

char	ft_rev_argv(char **argv)
{
	int	i;
	int	size;
	int	temp;

	i = 0;
	size = ft_strlen(argv) - 1;
	while (i <= size)
	{
		temp = argv[1][i];
		argv[1][i] = argv[1][size];
		argv[1][size] = temp;
		i++;
		size--;
	}
	return (**argv);
}

int	num_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i] != '\0')
		i++;
	i -= 1;
	return (i);
}
