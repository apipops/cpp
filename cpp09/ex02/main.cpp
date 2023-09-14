#include "PmergeMe.hpp"

int main(int ac, char **av) 
{
	if (ac < 2)
		std::cout << "Error" << std::endl;
	else {
		PmergeMe PmergeMe(av);
		PmergeMe.execute();
	}
	return (0);
}