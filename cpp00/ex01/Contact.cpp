#include <iostream>
#include <string>
#include "Contact.h"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

//verifier les cas d'erreur apres
std::string	Contact::_getInfo(std::string type) const {
	std::string	info;
	
	std::cout << "Please enter the contact's " << type << ": ";
	std::getline(std::cin, info);

	return (info);
}

//verifier les cas d'erreur apres
std::string	Contact::_cutLen(std::string info) {
	std::string str;

	if (infos.length() > 10)
		str = info.substr(0, 9) + ".";
	else
	{
		str = info;
		for (int i = info.length(); i <= 10; i++)
			info = " " + info;
	}
	return (info);
}

void	Contact::initContact(void)
{
	this->_firstName = this->_getInfo("first name");
	this->_lastName = this->_getInfo("last name");
	this->_nickName = this->_getInfo("nick name");
	this->_phoneNumber = this->_getInfo("phone number");
	this->_secret = this->_getInfo("darkest secret");
	std::cout << std::endl;
}

void	Contact::setIndex(int index)
{
	this->_index = index;
}

void	Contact::previewContact(void)
{
	std::cout << "         " << this->_index << "|";
	std::cout << this->_cutLen(this->_firstName) << "|";
	std::cout << this->_cutLen(this->_lastName) << "|";
	std::cout << this->_cutLen(this->_nickName) << std::endl;
}

void	Contact::displayContact(void)
{
	std::cout << "INDEX :" << this->_index << std::endl;
	std::cout << "FIRST NAME :" << this->_firstName << std::endl;
	std::cout << "LAST NAME :" << this->_lastName << std::endl;
	std::cout << "NICKNAME :" << this->_nickName << std::endl;
	std::cout << "PHONE NUMBER :" << this->_phoneNumber << std::endl;
	std::cout << "DARKEST SECRET :" << this->_secret << std::endl;
}
