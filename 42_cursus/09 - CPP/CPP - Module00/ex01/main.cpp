#include "PhoneBook.hpp"
#include <iostream>

int main(void){
	std::string	input;
	PhoneBook	phone;

	std::cout<<"\nEnjoy Guido's Phonebook!\nPuoi inserire solamente le parole:\n\t- ADD\n\t- SEARCH\n\t- EXIT\nInserimento parola --> ";
	getline(std::cin, input);
	while (1){
		if (input == "ADD")
			phone.addContact();
		else if (input == "SEARCH")
			phone.searchContact();
		else if (input == "EXIT"){
			std::cout<<"I tuoi contatti sono stati appena ELIMINATI!\nBye Bye :)"<<std::endl;
			return 0;
		}
		else
			std::cout<<"Inserire un comando valido"<<std::endl;
	}
	return 0;
}