#include "Array.hpp"

int main( void )
{
	std::cout << "> #1 EMPTY ARRAY" << std::endl;
	Array<int> empty_array;
	std::cout << "- size: " << empty_array.size() << std::endl;
	std::cout << "- content: " << empty_array << std::endl;

	std::cout << std::endl << "> #2 STRING ARRAY" << std::endl;
	Array<std::string> str_array(3);
	str_array[0] = "hello";
	str_array[1] = "hola";
	str_array[2] = "hallo";
	std::cout << "- size: " << str_array.size() << std::endl;
	std::cout << "- content: " << str_array << std::endl;

	std::cout << std::endl << "> #3 INT ARRAY, COPY CONSTRUCTOR & ASSIGNMENT OPERATOR" << std::endl;
	Array<int> int_array1(10);
	for (int i = 0; i < 10; i++)
		int_array1[i] = i;
	std::cout << "- size (int_array1): " << int_array1.size() << std::endl;
	std::cout << "- content(int_array1): " << int_array1 << std::endl;
	std::cout << "Copy constructor..." << std::endl;
	Array<int> int_array2(int_array1);
	std::cout << "- size (int_array2): " << int_array2.size() << std::endl;
	std::cout << "- content(int_array2): " << int_array2 << std::endl;
	std::cout << "Assignment operator..." << std::endl;
	Array<int> int_array3;
	int_array3 = int_array1;
	std::cout << "- size (int_array3): " << int_array3.size() << std::endl;
	std::cout << "- content(int_array3): " << int_array3 << std::endl;
	

	std::cout << std::endl << "> #4 FLOAT ARRAY & OUT OF RANGE INDEX" << std::endl;
	Array<float> float_array(5);
	for (int i = 0; i < 5; i++)
		float_array[i] = i + 0.5f;
	std::cout << "- size: " << float_array.size() << std::endl;
	std::cout << "- content: " << float_array << std::endl;
	std::cout << "- float_array[1]: ";
	try { 
		std::cout << float_array[1] << std::endl; 
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "- float_array[5]: ";
	try { 
		std::cout << float_array[5] << std::endl; 
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}


	return 0;
}