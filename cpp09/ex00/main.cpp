#include "BitcoinExchange.hpp"

int main(int ac, char **av) 
{
	if (ac == 1)
		std::cout << "Error: coult not open input file." << std::endl;
	else if (ac > 2)
		std::cout << "Error: too many arguments." << std::endl;
	else {
		BitcoinExchange btc("data.csv");
		btc.convert(av[1]);
	}
	return (0);
}