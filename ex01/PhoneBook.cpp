#include "PhoneBook.hpp"

std::string PhoneBook::truncate(const std::string& str) const {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

std::string	trimSpaces(const std::string& str)
{
	size_t	start = 0;
	size_t	end = str.length();

	while (start < end && std::isspace(str[start]))
		start++;
	while (end > start && std::isspace(str[end -1]))
		end--;
	return str.substr(start, end - start);
}

PhoneBook::PhoneBook() {
    index = 0;
    selectedIndex = "";
}

PhoneBook::~PhoneBook() {
}

Contact::Contact() {
	_firstName = "";
    _lastName = "";
    _nickname = "";
    _phoneNumber = "";
    _darkestSecret = "";
}

Contact::~Contact() {
}

void	PhoneBook::searchContact()
{
	int	i = 0;
	int j = 0;
	int	isNotValid = true;

	while (isNotValid)
	{
		if (index < 1)
		{
			std::cout << "The PhoneBook is empty. Type ADD to add contacts." << std::endl;
			return ;
		}
		else
		{
			std::cout << "------------ Saved contacts ------------" << std::endl;
			while(i < index)
			{
				std::cout<< std::setw(10) << std::right << i + 1 << " | "
						<< std::setw(10) << std::right << truncate(contacts[i].getFirstName()) << " | "
						<< std::setw(10) << std::right << truncate(contacts[i].getLastName()) << " | "
						<< std::setw(10) << std::right << truncate(contacts[i].getNickname()) << " | " << std::endl;
				i++;
			
			}
			std::cout << "Type contact's index to see more: ";
			std::cin >> selectedIndex;
			j = atoi(selectedIndex.c_str());
			j--;
			if (j >= 0 && j <= index && !contacts[j].getFirstName().empty())
			{
				std::cout << "------------ [" << selectedIndex << "] -------------" << std::endl;
				std::cout << "First name:     " << contacts[j].getFirstName() << std::endl;
				std::cout << "Last name:      " << contacts[j].getLastName() << std::endl;
				std::cout << "Nickname:       " << contacts[j].getNickname() << std::endl;
				std::cout << "Phone number:   " << contacts[j].getPhoneNumber() << std::endl;
				std::cout << "Darkest secret: " << contacts[j].getDarkestSecret() << std::endl;
				return ;
			}
			isNotValid = false;
		}
	}
}

void	PhoneBook::addContact()
{
	Contact			contact;
	std::string		buf;

	while (1)
	{
		std::cout << "First name: ";
		if(!(std::getline(std::cin, buf)))
			return;
		contact.setFirstName(trimSpaces(buf));
		if (contact.getFirstName().empty())
			std::cout << "Don't leave it empty!" << std::endl;
		else
			break ;
	}
	while (1)
	{
		std::cout << "Last name: ";
		if(!(std::getline(std::cin, buf)))
			return;
		contact.setLastName(trimSpaces(buf));
		if (contact.getLastName().empty())
			std::cout << "Don't leave it empty!" << std::endl;
		else
			break;
	}
	while (1)
	{
		std::cout << "Nickname: ";
		if(!(std::getline(std::cin, buf)))
			return;
		contact.setNickname(trimSpaces(buf));
		if (contact.getNickname().empty())
			std::cout << "Don't leave it empty!" << std::endl;
		else
			break;
	}
	while (1)
	{
		std::cout << "Phone number: ";
		if(!(std::getline(std::cin, buf)))
			return;
		contact.setPhoneNumber(trimSpaces(buf));
		if (contact.getPhoneNumber().empty())
			std::cout << "Don't leave it empty!" << std::endl;
		else
			break;
	}
	while (1)
	{
		std::cout << "Darkest secret: ";
		if(!(std::getline(std::cin, buf)))
			return;
		contact.setDarkestSecret(trimSpaces(buf));
		if (contact.getDarkestSecret().empty())
			std::cout << "Don't leave it empty!" << std::endl;
		else
			break ;
	}
	if (index > 8)
		index = 8; 
	contacts[index] = contact;
}
