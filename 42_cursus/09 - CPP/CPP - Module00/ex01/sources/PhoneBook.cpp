#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	index = 0;
	thelast = 0;
	return ;
}

PhoneBook::~PhoneBook(void){
	return ;
}

void	PhoneBook::searchContact(void){
	Contact user;

	if (index == 0)
		std::cout << "Non ci sono contatti nella rubrica. Digita ADD per aggiungere." << std::endl;
	else{
		std::cout << "|     Index|      Nome|   Cognome|  Nickname|" << std::endl;
		for (int i = 0; i < index; i++){
			std::cout << "|" << std::setw(10) << index << "|";
			for (int j = 0; j < 3; j++)
			{
				if (contact[i].getInfo(j).size() < 10)
					std::cout << std::setw(10) << contact[i].getInfo(j) << "|";
				else
					std::cout << contact[i].getInfo(j).substr(0, 10) << ".|";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	while (1){
		std::cout << "Inserire l'indice del contatto da visualizzare (1 to "<< index <<") o premere 0 per tornare indietro" << std::endl;
	}
}

void	PhoneBook::addContact(void){
	Contact user;

	user.addInfo();
	if (index == 8){
		if (thelast == 8)
			thelast = 0;
		contact[thelast++] = user;
	}
	else
		contact[index++] = user;
	return ;
}
