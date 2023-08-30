#include "easyfind.hpp"

int main() 
{
	int target = 2;
	std::cout << "Target value: " << target << std::endl;

	// LIST
	std::list<int> lst;
	std::list<int>::iterator lst_it;

	for (int i = 0; i < 10; i++)
		lst.push_back(i);
	lst_it = easyfind(lst, target);
	if (lst_it != lst.end())
		std::cout << "- LIST: Value found: " << *lst_it << std::endl;
	else
		std::cout << "- LIST: No value found" << std::endl;

	// VECTOR
	std::vector<int> vec;
	std::vector<int>::iterator vec_it;

	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	vec_it = easyfind(vec, target);
	if (vec_it != vec.end())
		std::cout << "- VECTOR: Value found: " << *vec_it << std::endl;
	else
		std::cout << "- VECTOR: No value found" << std::endl;

	return 0;
}