#include <iostream>
#include "PhoneBook.h"

PhoneBook::PhoneBook(void)
{
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::printHelp(void)
{
	std::cout << "----- 📞📒 PHONEBOOK USAGE 📒📞 -----" << std::endl; 33
	std::cout << "Enter one of the following commands :" << std::endl;
	std::cout << "> 'ADD' to add a new contact" << std::endl;
	std::cout << "> 'SEARCH' to search for a contact" << std::endl;
	std::cout << "> 'EXIT' to quit the phonebook" << std::endl;
	std::cout << "---------------------------------" << std:endl;
}

void	PhoneBook::addContact(void)
{
	static int	index;

	this->_contacts[i % 8].initContact();
	this->_contacts[i % 8].setIndex(i % 8);

}

int	PhoneBook::_findIndex(void)
{

}