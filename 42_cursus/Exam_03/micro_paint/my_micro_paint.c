#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_strlen(const char *str){int i = 0;while(str[i])i++;return(i);}

int print_err(const char *str, int err){write(1, str, ft_strlen(str));return(err);}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		FILE *fd;
		char **matrix, BACKGROUND;
		int i, j, scan_ret, WIDTH, HEIGHT;

		if (!(fd = fopen(av[1], "r")))
			return (print_err("Error: Operation file corrupted\n", 1));
		scan_ret = fscanf(fd, "%d %d %c\n", &WIDTH, &HEIGHT, &BACKGROUND);
		if (scan_ret == 3)
		{
			if ((WIDTH > 0 && WIDTH <= 300) && (HEIGHT > 0 && HEIGHT <= 300))
			{
				matrix = malloc(sizeof(char *) * HEIGHT + 1);
				if (!matrix)
					return (print_err("Error: Operation file corrupted\n", 1));
				i = 0;
				while (i < HEIGHT)
				{
					matrix[i] = malloc(sizeof(char) * WIDTH + 1);
					if (!matrix[i])
						return (print_err("Error: Operation file corrupted\n", 1));
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
				return (print_err("Error: Operation file corrupted\n", 1));
		}
		else
			return (print_err("Error: Operation file corrupted\n", 1));
		
		float	Xl, Yl, width, height, Xr, Yr;
		char	r, draw;

		while ((scan_ret = fscanf(fd, "%c %f %f %f %f %c\n", &r, &Xl, &Yl, &width, &height, &draw)) == 6)
		{
			if ((r != 'r' && r != 'R') || width <= 0 || height <= 0)
				return (print_err("Error: Operation file corrupted\n", 1));
			Xr = (Xl + width);
			Yr = (Yl + height);
			i = -1;
			while (++i < HEIGHT)
			{
				j = -1;
				while (++j < WIDTH)
				{
					if (r == 'r' && (Xl + 1.00000000) <= j && j <= (Xr - 1.00000000) && (Yl + 1.00000000) <= i && i <= (Yr - 1.00000000))
						continue ;
					if (j < Xl || j > Xr || i < Yl || i > Yr)
						continue ;
					matrix[i][j] = draw;
				}
			}
		}
		if (scan_ret != -1)
			return (print_err("Error: Operation file corrupted\n", 1));
		i = 0;
		while (matrix[i])
		{
			if (i != 0 && (j % WIDTH == 0))
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
		return (print_err("Error: argument\n", 1));
}
