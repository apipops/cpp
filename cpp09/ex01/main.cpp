#include "RPN.hpp"

int main(int ac, char **av) 
{
	if (ac == 1)
		std::cout << "Error" << std::endl;
	else if (ac > 2)
		std::cout << "Error" << std::endl;
	else {
		RPN btc(av[1]);
		btc.calculate();
	}
	return (0);
}