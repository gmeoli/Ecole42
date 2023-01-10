#include <iostream>
#include <fstream>

void fac_replacestring(std::string &str, const std::string &s1, const std::string &s2) {
	size_t i = 0, j = 0, end;
	std::string new_str = "";

	end = str.length();
	while (j < end) {
		i = str.find(s1, j);
		if (i > end)
		{
			i = end;
			new_str += str.substr(j, i - j);
		}
		else
			new_str += str.substr(j, i - j) + s2;
		j = i + s1.length();
	}
	str = new_str.substr(0, new_str.length());
}
 
int main(int ac, char **av) {

	std::string line = "";

	if (ac != 4) {
		std::cerr << "Error arguments!\n";
		return 1;
	}
	std::ifstream file(av[1]);
	if (!file.is_open()) {
		std::cerr << "File corrupted!\n";
		return 1;
	}
	std::ofstream oFile((std::string)av[1] + ".replace");
	if (!oFile.is_open()) {
		std::cerr << "oFile not created!\n";
		return 1;
	}
	while (std::getline(file, line)) {
		fac_replacestring(line, av[2], av[3]);
		oFile << line << std::endl;
	}
	std::cout << line;
	oFile.close();
	file.close();
	return 0;
}
