#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <string.h>

class PhoneBook
{
	public:
		Contact	contact[8];
		int		index;
};

#endif
