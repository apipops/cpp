#ifndef REPLACER_HPP
# define REPLACER_HPP

# include <iostream>
# include <fstream>
# include <cerrno>

class	Replacer
{
public:
	Replacer(std::string	filename);
	~Replacer(void);
	void	replace(std::string s1, std::string s2);

private:
	std::string		_infile;
	std::string		_outfile;
	void	_printError(std::string filename) const;
};

#endif