#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <stack>
# include <algorithm>
# include <iterator>

# define EXIT_FAILURE 1

class RPN
{
private:
	std::string 			_expression;
	std::stack<float>		_stack;

	RPN(); // Cannot be instanciated with no parameter

	void	_exitError() const;
	void	_executeOperator(std::string & token);

public:
	RPN(std::string math_expression);
	RPN(RPN const & src);
	RPN & operator=(RPN const & src);
	~RPN();

	void calculate();

};

#endif