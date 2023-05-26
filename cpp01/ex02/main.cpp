#include <string>
#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << std::endl;
	std::cout << " **************** ADDRESSES *****************" << std::endl;
	std::cout << " - of the 'string' variable : " << &string << std::endl;
	std::cout << " - held by 'stringPTR' : " << stringPTR << std::endl;
	std::cout << " - held by 'stringREF' : " << &stringREF << std::endl << std::endl;

	std::cout << " ***************** VALUES *******************" << std::endl;
	std::cout << " - of the 'string' variable : " << string << std::endl;
	std::cout << " - pointed to by 'stringPTR' : " << *stringPTR << std::endl;
	std::cout << " - pointed by 'stringREF' : " << stringREF << std::endl << std::endl;

	return (0);
}