#include "RPN.hpp"

RPN::RPN():_expression("")
{
}

RPN::RPN(std::string math_expression):_expression(math_expression)
{
}

RPN::RPN(RPN const & src)
{
	*this = src;
}

RPN & RPN::operator=(RPN const & src)
{
	this->_expression = src._expression;
	this->_stack = src._stack;
	return *this;
}

RPN::~RPN()
{
}

void RPN::_exitError() const
{
	std::cout << "Error" << std::endl;
	exit(EXIT_FAILURE);
}

void RPN::calculate()
{
	std::stringstream	ss(this->_expression);
	std::string			token;

	while (std::getline(ss, token, ' '))
	{
		if (token.size() == 1 && std::isdigit(token[0]))
			this->_stack.push(std::atof(token.c_str()));
		else if (token == "+" || token == "-" || token == "*" || token == "/")
			RPN::_executeOperator(token);
		else if (!token.empty())
			RPN::_exitError();
	}
	if (this->_stack.size() != 1)
		RPN::_exitError();
	else
		std::cout << this->_stack.top() << std::endl;
}

void	RPN::_executeOperator(std::string & token)
{
	if (this->_stack.size() < 2)
		RPN::_exitError();
	
	float last = this->_stack.top(); // sauvegarder la dernière valeur
	this->_stack.pop(); // vider valeur
	float before_last = this->_stack.top(); // sauvegarder avant dernière valeur;
	this->_stack.pop(); // vider valeur
	
	if (token == "+")
		this->_stack.push(before_last + last);
	else if (token == "-")
		this->_stack.push(before_last - last);
	else if (token == "*")
		this->_stack.push(before_last * last);
	else if (token == "/" && last)
		this->_stack.push(before_last / last);
	else 
		RPN::_exitError();
}