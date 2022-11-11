#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_print_error(const char *str, int ret)
{
	write(1, str, ft_strlen(str));
	return (ret);
}

int main(int ac, char **av)
{
	int		WIDTH;
	int		HEIGHT;
	FILE	*fd;
	char	*drawing;
	char	BACKGROUND;
	int		scan_ret;
	int		i;

	drawing = NULL;
	i = 0;
	if (ac == 2)
	{
		if (!(fd = fopen(av[1], "r")))
			return (ft_print_error("Error: Operation file corrupted\n", 1));
		scan_ret = fscanf(fd, "%d %d %c\n", &WIDTH, &HEIGHT, &BACKGROUND);
		if (scan_ret == 3)
			{
				if ((WIDTH > 0 && WIDTH <= 300) && (HEIGHT > 0 && HEIGHT <= 300))
				{
					drawing = (char *)malloc(sizeof(char) * (WIDTH * HEIGHT) + 1);
					if (!drawing)
						return (1);
					while (i < (WIDTH * HEIGHT))
					{
						drawing[i] = BACKGROUND;
						i++;
					}
					drawing[i] = 0;
				}
				else
					return (ft_print_error("Error: Operation file corrupted\n", 1));
			}
		else
			return (ft_print_error("Error: Operation file corrupted\n", 1));
		if (scan_ret == -1)
		{
			i = 0;
			while (drawing[i])
			{
				if (i != 0 && (i % WIDTH == 0))
					write(1, "\n", 1);
				write(1, &drawing[i], 1);
				i++;
			}
		}
	}
	else
		return (ft_print_error("Error: argument\n", 1));
	free(drawing);
	fclose(fd);
	return (0);
}
