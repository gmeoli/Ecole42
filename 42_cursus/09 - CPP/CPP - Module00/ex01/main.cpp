#include "./include/PhoneBook.hpp"
#include <iostream>

int main(void){
	std::string	input;
	PhoneBook	phone;

	std::cout << "\nWelcome to Guido's Phonebook!";
	while (1){
		std::cout << "\nDigita il comando:\n\t- ADD\n\t- SEARCH\n\t- EXIT\nComando --> ";
		getline(std::cin, input);
		if (input == "ADD")
			phone.addContact();
		else if (input == "SEARCH")
			phone.searchContact();
		else if (input == "EXIT"){
			std::cout << "I tuoi contatti sono stati ELIMINATI!\nBye Bye :)\n" << std::endl;
			return 0;
		}
		else
			std::cout << "ERROR: Inserire un comando valido" << std::endl;
	}
	return 0;
}
