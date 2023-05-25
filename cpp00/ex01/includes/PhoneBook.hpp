#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <string>
# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include "Contact.hpp"
 
class PhoneBook 
{
public : 
	PhoneBook(void);
	~PhoneBook(void);

	void	printHelp(void);
	void	addContact(void);
	void	searchContacts(void);

private :
	Contact		_contacts[8];
	int			_nbContacts;
	void		_selectContact(void);
};

#endif