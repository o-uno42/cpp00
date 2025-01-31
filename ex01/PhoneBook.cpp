#include "PhoneBook.hpp"
#include <iostream>

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

	while (1)
	{
		if (index < 1)
		{
			std::cout << YELLOW << "The PhoneBook is empty. Type ADD to add contacts." << RESET << std::endl;
			return ;
		}
		else
		{
			std::cout << YELLOW << "------------ Saved contacts ------------" << RESET << std::endl;
			while(i < index)
			{
				std::cout<< std::setw(10) << std::right << i + 1 << " | "
						<< std::setw(10) << std::right << truncate(contacts[i].getFirstName()) << " | "
						<< std::setw(10) << std::right << truncate(contacts[i].getLastName()) << " | "
						<< std::setw(10) << std::right << truncate(contacts[i].getNickname()) << " | " << std::endl;
				i++;
			
			}
			std::cout << YELLOW << "Type contact's index to see more: " << RESET;
			if(!(std::getline(std::cin, selectedIndex)))
				return;
			j = atoi(selectedIndex.c_str());
			if (j > 7)
			{
				std::cout << "The index [" << YELLOW << selectedIndex << RESET << "] doesn't exist!" << std::endl;
				break ;
			}
			j--;
			if (j >= 0 && j <= index && !contacts[j].getFirstName().empty())
			{
				std::cout << YELLOW << "------------ [" << selectedIndex << "] -------------" << RESET << std::endl;
				std::cout << "First name:     " << contacts[j].getFirstName() << std::endl;
				std::cout << "Last name:      " << contacts[j].getLastName() << std::endl;
				std::cout << "Nickname:       " << contacts[j].getNickname() << std::endl;
				std::cout << "Phone number:   " << contacts[j].getPhoneNumber() << std::endl;
				std::cout << "Darkest secret: " << contacts[j].getDarkestSecret() << std::endl;
				break ;
			}
			else
			{
				std::cout << "The index [" << YELLOW << selectedIndex << RESET << "] doesn't exist!" << std::endl;
				break ;
			}
		}
	}
}

void	PhoneBook::addContact()
{
	Contact			contact;
	std::string		buf;

	while (1)
	{
		std::cout << CYAN << "First name: " << RESET;
		if(!(std::getline(std::cin, buf)))
			return;
		contact.setFirstName(trimSpaces(buf));
		if (contact.getFirstName().empty())
			std::cout << CYAN << "Don't leave it empty!" << std::endl;
		else
			break ;
	}
	while (1)
	{
		std::cout << CYAN << "Last name: " << RESET;
		if(!(std::getline(std::cin, buf)))
			return;
		contact.setLastName(trimSpaces(buf));
		if (contact.getLastName().empty())
			std::cout << CYAN << "Don't leave it empty!" << RESET << std::endl;
		else
			break;
	}
	while (1)
	{
		std::cout << CYAN << "Nickname: " << RESET;
		if(!(std::getline(std::cin, buf)))
			return;
		contact.setNickname(trimSpaces(buf));
		if (contact.getNickname().empty())
			std::cout << CYAN << "Don't leave it empty!" << RESET << std::endl;
		else
			break;
	}
	while (1)
	{
		std::cout << CYAN << "Phone number: " << RESET;
		if(!(std::getline(std::cin, buf)))
			return;
		contact.setPhoneNumber(trimSpaces(buf));
		if (contact.getPhoneNumber().empty())
			std::cout << CYAN << "Don't leave it empty!" << RESET << std::endl;
		else
			break;
	}
	while (1)
	{
		std::cout << CYAN << "Darkest secret: " << RESET;
		if(!(std::getline(std::cin, buf)))
			return;
		contact.setDarkestSecret(trimSpaces(buf));
		if (contact.getDarkestSecret().empty())
			std::cout << CYAN << "Don't leave it empty!" << RESET << std::endl;
		else
			break ;
	}
	if (index > 8)
		index = 8; 
	contacts[index] = contact;
}
