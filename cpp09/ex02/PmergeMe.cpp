#include "PmergeMe.hpp"

PmergeMe::PmergeMe():_list("")
{
}

PmergeMe::PmergeMe(std::string list):_list(list)
{
	PmergeMe::_parseList(list);
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
	*this = src;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & src)
{
	this->_list = src._list;
	this->_vector = src._vector;
	this->_deque = src._deque;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::_exitError() const
{
	std::cout << "Error" << std::endl;
	exit(EXIT_FAILURE);
}

void	PmergeMe::_parseList(std::string & list)
{
	std::stringstream	ss(list);
	std::string			token;

	while (std::getline(ss, token, ' '))
	{
		if (!token.empty() && PmergeMe::_isDigitStr(token)) {
			int value = std::atoi(token.c_str());
			this->_vector.push_back(value);
			this->_deque.push_back(value);
		}
		else if (!token.empty())
			PmergeMe::_exitError();
	}
}

bool PmergeMe::_isDigitStr(std::string & str) const
{
	for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        if (!std::isdigit(*it))
			return false;
	}
	return true;
}

void PmergeMe::display()
{
	std::vector<unsigned int>::iterator it;
	for (it = this->_vector.begin(); it != this->_vector.end(); it++) {
		std::cout << *it;
		if (it < this->_vector.end() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}