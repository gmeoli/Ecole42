#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ft_strlen(const char *str){int	i;i = 0;while (str[i])i++;return (i);}

int ft_print_error(const char *str, int ret){write(1, str, ft_strlen(str));return (ret);}

int main(int ac, char **av)
{
	FILE	*fd;
	int		WIDTH, HEIGHT;
	char	BACKGROUND;
	char	**matrix;
	int		i, j;
	int		scan_ret;

	if (ac == 2)
	{
		if (!(fd = fopen(av[1], "r")))
			return (ft_print_error("Error: Operation file corrupted\n", 1));
		scan_ret = fscanf(fd, "%d %d %c\n", &WIDTH, &HEIGHT, &BACKGROUND);
		if (scan_ret == 3)
		{
			if ((WIDTH > 0 && WIDTH <= 300) && (HEIGHT > 0 && HEIGHT <= 300))
			{
				matrix = malloc(sizeof(char *) * HEIGHT + 1);
				i = 0;
				while (i < HEIGHT)
				{
					matrix[i] = malloc(sizeof(char) * WIDTH + 1);
					j = 0;
					while (j < WIDTH)
					{
						matrix[i][j] = BACKGROUND;
						j++;
					}
					matrix[i][j] = '\0';
					i++;
				}
				matrix[i] = NULL;
			}
			else
				return (ft_print_error("Error: Operation file corrupted\n", 1));
		}
		else
			return (ft_print_error("Error: Operation file corrupted\n", 1));
	
	float	Y, X, radius, appoggio;
	char	c, stamp;

	while ((scan_ret = fscanf(fd, "%c %f %f %f %c\n", &c, &X, &Y, &radius, &stamp)) == 5)
	{
		i = 0;
		while (i < HEIGHT)
		{
			j = 0;
			while (j < WIDTH)
			{
				appoggio = sqrtf((X - j) * (X - j) + (Y - i) * (Y - i));
				if ((c == 'c' || c == 'C') && radius > 0.00)
				{
					if (c == 'c' && radius - appoggio < 1.00 && radius - appoggio >= 0)
						matrix[i][j] = stamp;
					else if (c == 'C' && radius - appoggio >= 0 )
						matrix[i][j] = stamp;
				}
				else
					return (ft_print_error("Error: Operation file corrupted\n", 1));
				j++;
			}
			i++;
		}
	}
	if (scan_ret != -1)
		return (ft_print_error("Error: Operation file corrupted\n", 1));
	i = 0;
	while (matrix[i])
	{
		if (i != 0 && j % WIDTH == 0)
			write(1, "\n", 1);
		write(1, matrix[i], ft_strlen(matrix[i]));
		i++;
	}
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	fclose(fd);
	return (0);
	}
	else
		return (ft_print_error("Error: argument\n", 1));
}
