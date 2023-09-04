#ifndef MUTAN_STACK_HPP
# define MUTAN_STACK_HPP

#include <iostream>
#include <stack>
#include <list>
#include <iterator>
#include <cstdlib>
#include <limits>

template< typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack<T>() : std::stack<T>() {}
 	MutantStack<T>(const MutantStack & src) { *this = src; }
	MutantStack<T> & operator=(const MutantStack & src) { 
		std::stack<T>::operator=(src);
		return *this;
	}
	~MutantStack<T>() {};

	// The std::stack class is a container adaptor and acts as a wrapper to the underlying container.
	// The default underlying container is std::deque and 'container_type' refers to the underlying container.
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	
	iterator begin() { return std::stack<T>::c.begin(); }
	iterator end() { return std::stack<T>::c.end(); }
	const_iterator begin() const { return std::stack<T>::c.begin(); }
	const_iterator end() const { return std::stack<T>::c.begin(); }
	reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); }
	reverse_iterator rend() { return std::stack<T>::c.rend(); }
	const_reverse_iterator rbegin() const { return std::stack<T>::c.rbegin(); }
	const_reverse_iterator rend() const { return std::stack<T>::c.rend(); }
};

#endif