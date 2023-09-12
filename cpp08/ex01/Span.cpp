#include "Span.hpp"

Span::Span(): _N(0)
{
}

Span::Span(unsigned int N): _N(N)
{
}

Span::Span(const Span & src)
{
	*this = src;
}

Span & Span::operator=(const Span & src)
{
	this->_N = src._N;
	this->_vec.assign(src._vec.begin(), src._vec.end());
	return *this;
}

Span::~Span()
{
}

unsigned int Span::getSize() const
{
	return (unsigned int)this->_vec.size();
}

std::vector<int> Span::getVector() const
{
	return this->_vec;
}

void Span::addNumber(int n)
{
	if (this->_vec.size() == this->_N)
		throw Span::FullVectorException();
	else
		this->_vec.push_back(n);
}

void Span::addVector(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_vec.size() + std::distance(begin, end) > this->_N)
		throw Span::FullVectorException();
	else
		this->_vec.insert(this->_vec.end(), begin, end);
}

unsigned int Span::shortestSpan() const
{
	if (this->_vec.size() <= 1)
		throw Span::NoSpanException();
	else
	{
		unsigned int shortestSpan =  std::numeric_limits<unsigned int>::max();
		for (int i = 0; i < (int)this->_vec.size(); i++)
			for (int j = i + 1; j < (int)this->_vec.size(); j++) {
				unsigned int span = std::abs(this->_vec[i] - this->_vec[j]);
				if (span < shortestSpan)
					shortestSpan = span;
			}
		return shortestSpan;
	}
}

unsigned int Span::longestSpan() const
{
	if (this->_vec.size() <= 1)
		throw Span::NoSpanException();
	else
	{
		unsigned int longestSpan =  0;
		for (int i = 0; i < (int)this->_vec.size(); i++)
			for (int j = i + 1; j < (int)this->_vec.size(); j++) {
				unsigned int span = std::abs(this->_vec[i] - this->_vec[j]);
				if (span > longestSpan)
					longestSpan = span;
			}
		return longestSpan;
	}
}

const char* Span::FullVectorException::what() const throw()
{
	return ("Impossible to add number: Vector is full");
}

const char* Span::NoSpanException::what() const throw()
{
	return ("Impossible to calculate span: Too few values");
}

std::ostream & operator<<(std::ostream & out, Span const & element)
{
	unsigned int size = element.getSize();
	for (unsigned int i = 0; i < size; i++) {
		out << element.getVector()[i];
		if (i < size - 1)
			out << ", ";
	}
	return out;
}
