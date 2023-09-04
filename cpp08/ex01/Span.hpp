#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <limits>

class Span 
{
private:
	unsigned int	_N;
	std::vector<int> _vec;

public:
	Span(); // _N = 0
	Span(unsigned int N);
	Span(const Span & src);
	Span & operator=(const Span & src);
	~Span();

	unsigned int getSize() const;
	std::vector<int> getVector() const;

	void addNumber(int n);
	void addVector(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	class FullVectorException : public std::exception {
		public :
			virtual const char* what() const throw();
	};

	class NoSpanException : public std::exception {
		public :
			virtual const char* what() const throw();
	};

};

std::ostream & operator<<(std::ostream & out, Span const & element);

#endif