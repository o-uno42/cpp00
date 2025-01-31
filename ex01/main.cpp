#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	Contact		contact;

	while (1)
	{
		std::string	input;

		std::cout << "You can ADD or SEARCH a contact.\nType EXIT to exit PhoneBook." << std::endl;
		if(!(std::getline(std::cin, input)))
            break;
		if ((input != "ADD" && input != "SEARCH" && input != "EXIT"))
			std::cout << "Write ADD or SEARCH.";
		else if (input == "ADD")
		{
			if (phoneBook.index > 7)
				phoneBook.index = 7;
			phoneBook.addContact();
			phoneBook.index++;
		}
		else if (input == "SEARCH")
			phoneBook.searchContact();
		else
		{
			std::cout << "Bye!" << std::endl;
			break ;
		}
		std::cout << std::endl;
	}
	return 0;
}