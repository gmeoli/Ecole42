#include <iostream>
#include <string>

int main(){

	std::string var = "HI THIS IS BRAIN";
	std::string *stringPTR = &var;
	std::string	&stringREF = var;

	std::cout << "Memory address of string var: " << &var << std::endl;
	std::cout << "Memory address held by stringPTR: " << &stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << "Value of string var: " << var << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}
