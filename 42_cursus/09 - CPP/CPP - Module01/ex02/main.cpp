#include <iostream>
#include <string>

int main(){

	std::string STRING = "HI THIS IS BRAIN";
	std::string *PTR;
	std::string &REF;

	std::cout << "Memory address STRING: " << &STRING << std::endl;
	std::cout << "Memory address PTR: " << &PTR << std::endl;
	std::cout << "Memory address REF: " << &REF << std::endl; 

    return 0;
}
