#include "PmergeMe.hpp"

int main(int ac, char **av) 
{
	if (ac == 1)
		std::cout << "Error" << std::endl;
	else if (ac > 2)
		std::cout << "Error" << std::endl;
	else {
		PmergeMe PmergeMe(av[1]);
		PmergeMe.display();
	}
	return (0);
}