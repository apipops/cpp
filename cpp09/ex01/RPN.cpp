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

void RPN::calculate()
{
	std::stringstream	ss(this->_expression);
	std::string			token;

	while (std::getline(ss, token, ' '))
	{
		if (token.size() == 1 && std::isdigit(token[0]))
			this->_stack.push(std::atof(token.c_str()));
		else if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (!RPN::_executeOperator(token))
				return ;
		}
		else if (!token.empty()) {
			std::cout << "Error" << std::endl;
			return;
		}
	}
	if (this->_stack.size() != 1) {
		std::cout << "Error" << std::endl;
		return;
	}
	else
		std::cout << this->_stack.top() << std::endl;
}

bool	RPN::_executeOperator(std::string & token)
{
	if (this->_stack.size() < 2)
		return (std::cout << "Error" << std::endl, false);
	
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
		return (std::cout << "Error" << std::endl, false);
	return true;
}