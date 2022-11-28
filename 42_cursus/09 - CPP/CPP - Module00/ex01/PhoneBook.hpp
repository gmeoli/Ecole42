#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <string.h>

class PhoneBook
{
	private:
	
	public:
		Contact	contact[8];

		PhoneBook(void);
		~PhoneBook(void);
};

#endif
