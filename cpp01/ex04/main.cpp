#include "Replacer.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cout << "Error: Invalid number of arguments" << std::endl, 0);
	Replacer	replacer(argv[1]);
	replacer.replace(argv[2], argv[3]);
	return (0);
}