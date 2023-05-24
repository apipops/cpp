#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"
 
class PhoneBook 
{
public : 
	PhoneBook(void);
	~PhoneBook(void);

	void	printHelp(void)
	void	addContact(void);
	void	showContacts(void);
	void	selectContact(void);
	void	exit(void);

private :
	Contact		_contacts[8];
};

#endif