#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

static bool isNumber(const std::string &s) {
  try {
    std::stoi(s);
    return true;
  } catch (const std::invalid_argument&) {
    return false;
  }
}

static bool checkSpecial(std::string s[5], std::string input) {
	for (int i = 0; i < 5; i++)
		if (!input.compare(s[i]))
			return true;
	return false;
}

static void convert(std::string s) {
	int			n;
	float		f;
	double		d;
	char		c;

	try {
		n = std::stoi(s);
		f = std::stof(s);
		d = std::stod(s);
	}
	catch (const std::invalid_argument&) {
		n = static_cast<int>(s[0]);
		f = static_cast<float>(n);
		d = static_cast<double>(n);
	}
	c = static_cast<char>(n);
	c = n;
	if (c >= 32 && c != 127)
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << n << "\nfloat: " << std::fixed << std::setprecision(1) << f << "f\ndouble: " << d << std::endl;
}

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error\nInsert ./convert [char or number]" << std::endl;
		return 1;
	}

	std::string	s = av[1];
	std::string type[5] = { "-inff", "+inff", "-inf", "+inf", "nan"};
	if (checkSpecial(type, s))
	{
		std::cout << "char: impossible\nint: impossible" << std::endl;
		if (!s.compare(type[0]) || !s.compare(type[1]))
			std::cout << "float: nanf\ndouble: nan" << std::endl;
		else
			std::cout << "float: " << s << "\ndouble: " << s << std::endl;
	}
	else if (!isNumber(s) && s.length() != 1) {
		std::cerr << "Error\nInput is not a char/number" << std::endl;
		return 1;
	}
	else
		convert(s);

	return 0;
}
