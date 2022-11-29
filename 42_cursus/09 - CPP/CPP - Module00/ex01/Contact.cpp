#include "Contact.hpp"

Contact::Contact(void){
	info[0] = std::string("Nome");
	info[1] = std::string("Cognome");
	info[2] = std::string("Nickname");
	info[3] = std::string("Numero telefono");
	info[4] = std::string("Segno zodiacale");
	return ;
}

Contact::~Contact(void){
	return ;
}

void	Contact::addInfo(void){
	std::string	str;

	std::cout << "\nRiempi il modulo!" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		str.clear();
		while (str.size() == 0)
		{
			std::cout << "Inserire il " << info[i] << ": ";
			getline(std::cin, str);
			if (str.size() == 0)
				std::cout << "Riempire con il " << info[i] << ": ";
		}
		info[i] = str;
	}
}

std::string	Contact::getInfo(int index){
	return (info[index]);
}
