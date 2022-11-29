#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>

class Contact{
	private:
		std::string	info[5];
	public:
		Contact(void);
		~Contact(void);

		void	addInfo(void);
		std::string	getInfo(int index);
};

#endif
