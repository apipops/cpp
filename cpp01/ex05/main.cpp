#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "Error: No level specified" << std::endl;
	else if (ac > 2)
		std::cout << "Error: Too many arguments" << std::endl;
	else
	{
		Harl	harl;
		harl.complain(av[1]);
	}
	return (0);
}