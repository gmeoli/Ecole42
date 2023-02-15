#include <iostream>

bool ft_check(std::string s) {
	int	len = s.length();
	int	i = 0;
	if ((s[0] >= '0' && s[0] <= '9') || ((s[0] == '-' || s[0] == '+') && isdigit(s[1]))) {
		
	}
	return true;
}

int main(int ac, char **av) {

	if (ac != 2) {
		std::cout << "Error\nUsage: ./convert [string]"<< std::endl;
		return 1;
	}

	std::string	s;
	double		n;

	s = av[1];
	if (!ft_check(s)) {
		std::cout << "Error\nWrong argument!"<< std::endl;
		return 1;
	}

	return 0;
}
