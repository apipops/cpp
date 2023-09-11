#ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <deque>
# include <algorithm>
# include <iterator>

# define EXIT_FAILURE 1

class PmergeMe
{
private:
	std::string 					_list;
	std::vector<unsigned int>		_vector;
	std::deque<unsigned int>		_deque;

	PmergeMe(); // Cannot be instanciated with no parameter

	void	_exitError() const;
	bool	_isDigitStr(std::string & str) const;
	void	_parseList(std::string & list);
	void 	_merge();
	void	_insertSort();

public:
	PmergeMe(std::string list);
	PmergeMe(PmergeMe const & src);
	PmergeMe & operator=(PmergeMe const & src);
	~PmergeMe();

	void sort();
	void	display();

};

#endif