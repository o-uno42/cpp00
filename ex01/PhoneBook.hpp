#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

#include <iomanip>
#include <cstdlib>

class PhoneBook{
	private:

		Contact 		contacts[8];

	public:

		PhoneBook(void);
		~PhoneBook(void);

		int					index;
		std::string		selectedIndex;
		void			addContact();
		void			searchContact();
		bool		 	newLine(std::string);
		std::string 	truncate(const std::string& str) const;
};

#endif