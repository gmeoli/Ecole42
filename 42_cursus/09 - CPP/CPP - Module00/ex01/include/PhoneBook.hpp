#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.hpp"
#include <algorithm>
# include <cstring>
# include <iomanip>

class PhoneBook{
	private:
		Contact	contact[8];
	public:
		PhoneBook(void);
		~PhoneBook(void);

		int		thelast;
		int		index;
		void	searchContact(void);
		void	addContact(void);
};

#endif
