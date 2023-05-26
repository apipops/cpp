#include "PhoneBook.hpp"

int     main(int ac, char **av)
{
        (void)av;
        if (ac > 1)
                std::cout << "No argument needed." << std::endl;
        else
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
        }
        return (0);
}