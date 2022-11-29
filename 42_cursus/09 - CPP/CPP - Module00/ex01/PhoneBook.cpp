#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	index = 0;
	thelast = 0;
	return ;
}

PhoneBook::~PhoneBook(void){
	return ;
}

void	PhoneBook::searchContact(void){
	Contact tmp;

	if (index == 0)
		std::cout << "Non ci sono contatti nella rubrica. Digita ADD per aggiungere." << std::endl;
	else{
		std::cout << "|\tIndex\t|\tNome\t|\tCognome\t|\tNickname\t|" << std::endl;

	}
}

void	PhoneBook::addContact(void){
	Contact tmp;

	tmp.addInfo();
	if (index == 8){
		if (thelast == 8)
			thelast = 0;
		contact[thelast++] = tmp;
	}
	else
		contact[index++] = tmp;
	return ;
}
