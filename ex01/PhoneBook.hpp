#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

#include <iomanip>
#include <cstdlib>

#define RESET	"\033[0m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

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