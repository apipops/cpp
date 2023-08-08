#include "iter.hpp"

int main( void )
{
	int int_arr[5] = {0, 1, 2, 3, 4};	
 	float float_arr[5] = {0.0f, 0.1f, 0.2f, 0.3f, 0.4f};	
	char char_arr[5] = {'a', 'b', 'c', 'd', 'e'};	
	std::string str_arr[5] = {"hello", "my", "login", "is", "avast"};

	std::cout << "> #1 INT ARRAY" << std::endl;
	iter<int>(int_arr, 5, &print<int>);

	std::cout << std::endl << "> #2 FLOAT ARRAY" << std::endl;
	iter<float>(float_arr, 5, &print<float>);

	std::cout << std::endl << "> #3 CHAR ARRAY" << std::endl;
	iter<char>(char_arr, 5, &print<char>);

	std::cout << std::endl << "> #4 STRING ARRAY" << std::endl;
	iter<std::string>(str_arr, 5, &print<std::string>);

	return 0;
}