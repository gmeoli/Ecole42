#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.hpp"
#include <algorithm>
# include <cstring>
# include <iomanip>

class PhoneBook{
	private:
		Contact	contact[8];
		int	index;
		int	thelast;
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	searchContact(void);
		void	addContact(void);
};

#endif
