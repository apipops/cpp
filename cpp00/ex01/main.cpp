#include "PhoneBook.hpp"

int     main(void)
{
	PhoneBook       book;
	std::string     input = "";

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
    return (0);
}