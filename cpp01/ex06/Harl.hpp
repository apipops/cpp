#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

# define DEBUG 0
# define INFO 1
# define WARNING 0
# define ERROR 0

class	Harl
{
public:
	Harl(void);
	~Harl();
	void	complain(std::string level);

private:
	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);
} ;

#endif