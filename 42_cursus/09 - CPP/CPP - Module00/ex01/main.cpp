#include "PhoneBook.hpp"
#include <iostream>

int main(void){
	std::string	input;
	PhoneBook	phone;
	Contact		contact;

	std::cout<<"\nEnjoy Guido's Phonebook!"<<std::endl;
	std::cout<<"Puoi inserire solamente le parole:"<<std::endl;
	std::cout<<"- ADD"<<std::endl;
	std::cout<<"- SEARCH"<<std::endl;
	std::cout<<"- EXIT"<<std::endl;
	std::cout<<"Inserimento parola --> ";
	getline(std::cin, input);
	phone.index = 0;
	if (input == "ADD"){
		contact.addContact();
		phone.index += 1;
	}
	else if (input == "SEARCH"){
		if (phone.index == 0)
			std::cout << "La rubrica è vuota! Digitare ADD per aggiungere un contatto." << std::endl;
		// Scrivere il resto
	}
	else if (input == "EXIT"){
		std::cout<<"I tuoi contatti sono stati appena ELIMINATI"<<std::endl;
		std::cout<<"Grazie per essere stato con noi!"<<std::endl;
	}
	else
		std::cout<<"Hai inserito una parola non ammessa!"<<std::endl;
	return 0;
}