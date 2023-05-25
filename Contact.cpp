#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

//verifier les cas d'erreur apres
std::string	Contact::_getInfo(std::string type) const {
	std::string	info = "";
	
	std::cout << " - " << type << " : ";
	std::getline(std::cin, info);
	while (info.empty() || !std::cin.good())
	{
		std::cin.clear();
		std::cout << "   Invalid info. Please try again : ";
		std::getline(std::cin, info);
	}
	return (info);
}

//verifier les cas d'erreur apres
std::string	Contact::_cutLen(std::string info) {
	std::string str;

	if (info.length() > 10)
		str = info.substr(0, 9) + ".";
	else
	{
		str = info;
		for (int i = info.length(); i < 10; i++)
			str = " " + str;
	}
	return (str);
}

void	Contact::initContact(void)
{
	std::cin.ignore(); // pour ignorer le derniner '/n' rentre apres 'ADD'
	std::cout << "Please enter the contact's... " << std::endl;
	this->_firstName = this->_getInfo("First name");
	this->_lastName = this->_getInfo("Last name");
	this->_nickName = this->_getInfo("Nick name");
	this->_phoneNumber = this->_getInfo("Phone number");
	this->_secret = this->_getInfo("Darkest secret");
	std::cout << " ✅ Contact added! ✅" << std::endl;
	std::cout << std::endl;
}

void	Contact::setIndex(int index)
{
	this->_index = index;
}

void	Contact::previewContact(void)
{
	if (this->_firstName.empty())
		return ;
	std::cout << "|         " << this->_index << "|";
	std::cout << this->_cutLen(this->_firstName) << "|";
	std::cout << this->_cutLen(this->_lastName) << "|";
	std::cout << this->_cutLen(this->_nickName) << "|" << std::endl;
}

void	Contact::displayContact(void)
{
	if (this->_firstName.empty())
		return ;
	std::cout << std::endl << " -----------👤 CONTACT'S INFO 👤-------------" << std::endl;
	std::cout << "INDEX : " << this->_index << std::endl;
	std::cout << "FIRST NAME : " << this->_firstName << std::endl;
	std::cout << "LAST NAME : " << this->_lastName << std::endl;
	std::cout << "NICKNAME : " << this->_nickName << std::endl;
	std::cout << "PHONE NUMBER : " << this->_phoneNumber << std::endl;
	std::cout << "DARKEST SECRET : " << this->_secret << std::endl << std::endl;
}






#include "PhoneBook.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac > 1)
		std::cout << "No argument needed." << std::endl;
	else
	{
		PhoneBook	book;
		std::string	input = "";
		
		book.printHelp();
		while (input != "EXIT")
		{
			if (input == "ADD")
				book.addContact();
			else if (input == "SEARCH")
				book.searchContacts();
			std::cout << "> ";
			std::cin >> input;
		}
	}
	return (0);
}
