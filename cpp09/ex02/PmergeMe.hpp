#ifndef PMERGEME_HPP
# define PMERGEME_HPP

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
	std::deque<unsigned int>		_deque;
	std::vector<unsigned int>		_vector;

	PmergeMe(); // Cannot be instanciated with no parameter

	// Parsing & Utils
	void	_parseList(std::string & list);
	bool	_isDigitStr(std::string & str) const;
	void	_display() const;
	void	_displayDeque() const;

	// Vector sorting
	void 	_sortVector(int begin, int end);
	void	_insertSortVector(int begin, int end);
	void 	_mergeSortVector(int begin, int mid, int end);

	// Deque sorting
	void 	_sortDeque(int begin, int end);
	void	_insertSortDeque(int begin, int end);
	void 	_mergeSortDeque(int begin, int mid, int end);

public:
	PmergeMe(std::string list);
	PmergeMe(PmergeMe const & src);
	PmergeMe & operator=(PmergeMe const & src);
	~PmergeMe();

	void 	execute();

};

#endif