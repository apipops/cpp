#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <limits>

class Contact 
{
public : 
	Contact(void);
	~Contact(void);
	void initContact(void);
	void setIndex(int index);
	void previewContact(void);
	void displayContact(void);

private :
	int	_index;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_secret;
	std::string	_getInfo(std::string type) const;
	std::string _cutLen(std::string str);
};

#endif