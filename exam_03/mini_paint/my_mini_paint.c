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
	free(drawing);
	fclose(fd);
	return (0);
}
