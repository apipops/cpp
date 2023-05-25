#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void):_nbContacts(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::printHelp(void) {
	std::cout << std::endl << "  ---------📞📒 PHONEBOOK USAGE 📞📒---------" << std::endl;
	std::cout << " | Enter one of the following commands :     |" << std::endl;
	std::cout << " | 1) 'ADD' to add a new contact             |" << std::endl;
	std::cout << " | 2) 'SEARCH' to search for a contact       |" << std::endl;
	std::cout << " | 3) 'EXIT' to quit the phonebook           |" << std::endl;
	std::cout << "  -------------------------------------------" << std::endl << std::endl;
}

void	PhoneBook::addContact(void) {
	static int	i;

	std::cout << " ------------🖊️  ADDING CONTACT 🖊️------------" << std::endl;
	this->_contacts[i % 8].initContact();
	this->_contacts[i % 8].setIndex(i % 8);
	i++;
	if (_nbContacts < 8)
		_nbContacts++;
}

void	PhoneBook::_selectContact(void) {
	int index;

	std::cout << "Please enter the contact's index : ";
	std::cin >> index;
	while (!std::cin.good() || index < 0 || index > 7 || index > this->_nbContacts - 1)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::cout << "Invalid index. Please try again : ";
		std::cin >> index;
	}
	_contacts[index].displayContact();

}

void	PhoneBook::searchContacts(void) {
	std::cout << " ------------📂 ALL CONTACTS 📂-------------" << std::endl;
	if (this->_nbContacts)
	{
		std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
		for (int i = 0; i < 8; i++)
			_contacts[i].previewContact();
		std::cout << std::endl;
		this->_selectContact();
	}
	else
		std::cout << "                  {EMPTY}" << std::endl << std::endl;
}