#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char const *str) {int i = 0; while (str[i]) i++; return (i);}

int	str_error(char const *str, int ret){write(1, str, ft_strlen(str));return (ret);}

int main(int ac, char **av){
	FILE	*fd;
	char 	background;
	int 	height = 0;
	int 	width = 0;
	int		scan_ret = 0;
	int 	i = 0;
	char	*drawing = NULL;
	if (ac != 2)
		return (str_error("Error: argument\n", 1));
	if (!(fd = fopen(av[1], "r")))
		return (str_error("Error: Operation file corrupted\n", 1));
	scan_ret = fscanf(fd, "%d %d %c\n", &width, &height, &background);
	if (scan_ret == 3)
	{
		if (width > 0 && width <= 300 && height > 0 && height <= 300)
		{
			drawing = (char *)malloc(sizeof(char) * (width * height));
			if (!drawing)
				return (1);
			while (i < (width * height))
			{
				drawing[i] = background;
				i++;
			}
			drawing[i] = '\0';
		}
	}
	char	type;
	float	Y;
	float	X;
	float	r_height;
	float	r_width;
	char	color;
	int		x = 0;
	int		y = 0;
	scan_ret = fscanf(fd, "%c %f %f %f %f %c\n", &type, &X, &Y, &r_width, &r_height, &color);
	if (((r_width <= 0.00000000) || (r_height <= 0.00000000) || ((type != 'R') && (type != 'r'))))
		return (str_error("Error\n", 1));
	while (scan_ret == 6)
	{
		y = 0;
		while (y < height)
		{
			x = 0;
			while (x < width)
			{
				if ((X <= x && (x <= X + r_width)) && (Y <= y && (y <= Y + r_height)))
				{
					if ((x - X) < 1.00000000 || ((X + r_width) - x < 1.00000000) || (y - Y) < 1.00000000 || ((Y + r_height) - y < 1.00000000))
						drawing[(y * width) + x] = color;
					else if (type == 'R')
						drawing[(y * width) + x] = color;
				}
				x++;
			}
			y++;
		}
		scan_ret = fscanf(fd, "%c %f %f %f %f %c\n", &type, &X, &Y, &r_width, &r_height, &color);
	}
	if (scan_ret == -1)
	{
		i = 0;
		while (drawing[i])
		{
			if (i != 0 && i % width == 0)
				write (1, "\n", 1);
			write(1, &drawing[i], 1);
			i++;
		}
	}
	free(drawing);
	fclose(fd);
	return (0);
}