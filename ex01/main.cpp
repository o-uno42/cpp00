#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	Contact		contact;

	while (1)
	{
		std::string	input;

		std::cout << "You can " << CYAN << "ADD" << RESET << " or " << YELLOW << "SEARCH" << RESET << " a contact.\nType " << MAGENTA << "EXIT" << RESET " to exit PhoneBook." << std::endl;
		if(!(std::getline(std::cin, input)))
            break;
		if ((input != "ADD" && input != "SEARCH" && input != "EXIT"))
			std::cout << "\nWrite " << CYAN "ADD" << RESET << " or " << YELLOW << "SEARCH." << RESET << std::endl;
		else if (input == "ADD")
		{
			if (phoneBook.index > 7)
				phoneBook.index = 7;
			phoneBook.addContact();
			phoneBook.index++;
		}
		else if (input == "SEARCH")
		{
			phoneBook.searchContact();
			std::cout << std::flush;
		}
		else
		{
			std::cout << MAGENTA << "Bye!" << RESET << std::endl;
			break ;
		}
		std::cout << std::endl;
	}
	return 0;
}