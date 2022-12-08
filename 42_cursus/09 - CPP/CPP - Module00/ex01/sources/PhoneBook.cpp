#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	this->index = 0;
	this->thelast = 0;
	return ;
}

PhoneBook::~PhoneBook(void){
	return ;
}

void	PhoneBook::searchContact(void){
	Contact	user;
	int i = -1, j = -1;

	if (index == 0)
		std::cout << "Non ci sono contatti nella rubrica. Digita ADD per aggiungere." << std::endl;
	else{
		std::cout << "|     Index|      Nome|   Cognome|  Nickname|" << std::endl;
		while (++i < index){
			std::cout << "|         " << i + 1 << "|";
			while (++j < 3){
				if (contact[i].getInfo(j).size() > 10)
					std::cout << contact[i].getInfo(j).substr(0, 9) << ".|";
				else
					std::cout << std::setw(10) << contact[i].getInfo(j) << "|";
			}
			std::cout << std::endl;
			j = -1;
		}

		std::string	indice;
		while (1){
			std::cout << "Inserire l'indice del contatto da visualizzare (1 to "<< index <<") o premere 0 per tornare indietro" << std::endl;
			std::cout << "Comando --> ";
			getline(std::cin, indice);
			if (indice.size() == 0)
				continue;
			if (indice[0] == '0')
				return ;
			if (indice[0] >= '1' && indice[0] <= '8' && indice.size() == 1){
				if (indice[0] - '0' <= index)
				{
					user = contact[indice[0] - '0' - 1];
					std::cout << "\nNome: " << user.getInfo(0) << std::endl;
					std::cout << "Cognome: " << user.getInfo(1) << std::endl;
					std::cout << "Nickname: " << user.getInfo(2) << std::endl;
					std::cout << "Numero Telefono: " << user.getInfo(3) << std::endl;
					std::cout << "Segno Zodiacale: " << user.getInfo(4) << std::endl;
					return ;
				}
				else
					std::cout << "ERROR: Inserire un indice valido\n" << std::endl;
			}
		}
	}
}

void	PhoneBook::addContact(void){
	Contact user;

	user.addInfo();
	if (this->index == 8){
		if (this->thelast == 8)
			this->thelast = 0;
		this->contact[this->thelast++] = user;
	}
	else
		this->contact[this->index++] = user;
	return ;
}
