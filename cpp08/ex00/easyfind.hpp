#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <list>
# include <vector>
# include <algorithm>
# include <iterator>


template< typename T>
typename T::iterator	easyfind(T & container, int value) // 'typename' is mandatory to tell the compiler this is a type. 
{
	return (std::find(container.begin(), container.end(), value));
}

#endif