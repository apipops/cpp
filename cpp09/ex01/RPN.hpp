#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <stack>
# include <algorithm>
# include <iterator>

class RPN
{
private:
	std::string 			_expression;
	std::stack<float>		_stack;

	RPN(); // Cannot be instanciated with no parameter

	bool	_executeOperator(std::string & token);

public:
	RPN(std::string math_expression);
	RPN(RPN const & src);
	RPN & operator=(RPN const & src);
	~RPN();

	void calculate();

};

#endif