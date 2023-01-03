#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {

	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream input(filename);
	if (!input) {
		std::cerr << "Error: could not open file " << filename << std::endl;
		return 1;
	}

	std::ofstream output(filename + ".replace");
	if (!output) {
		std::cerr << "Error: could not open file " << filename << ".replace" << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(input, line)) {
		// Sostituisci ogni occorrenza di s1 con s2 nella stringa line
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
		line.replace(pos, s1.length(), s2);
		pos += s2.length();
		}
		output << line << std::endl;
	}

	return 0;
}
