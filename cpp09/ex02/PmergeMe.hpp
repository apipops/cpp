#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <deque>
# include <algorithm>
# include <iterator>
# include <ctime>

# define K 10
# define EXIT_FAILURE 1

class PmergeMe
{
private:
	std::deque<unsigned int>		_deque;
	std::vector<unsigned int>		_vector;
	bool							_valid;

	PmergeMe(); // Cannot be instanciated with no parameter

	// Parsing & Utils
	void	_parseList(char **av);
	bool	_isDigitStr(std::string & str) const;
	void	_display() const;

	// Vector sorting
	void 	_sortVector(int begin, int end);
	void	_insertSortVector(int begin, int end);
	void 	_mergeSortVector(int begin, int mid, int end);

	// Deque sorting
	void 	_sortDeque(int begin, int end);
	void	_insertSortDeque(int begin, int end);
	void 	_mergeSortDeque(int begin, int mid, int end);

public:
	PmergeMe(char **av);
	PmergeMe(PmergeMe const & src);
	PmergeMe & operator=(PmergeMe const & src);
	~PmergeMe();

	void			execute();
	unsigned int	size() const;


};

#endif