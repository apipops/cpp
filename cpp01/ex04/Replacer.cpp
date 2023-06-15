#include "Replacer.hpp"

Replacer::Replacer(std::string filename)
{
	this->_infile = filename;
	this->_outfile = filename + ".replace";
}

Replacer::~Replacer(void)
{
}

void	Replacer::_printError(std::string filename) const {
	std::cout << "Error: " << std::strerror(errno) << ": " << filename << std::endl;
}

void	Replacer::replace(std::string s1, std::string s2)
{
	std::ifstream	infile(this->_infile.c_str());
	if (infile.fail())
		this->_printError(this->_infile);
	else
	{
		std::string	content;
		if (std::getline(infile, content, '\0'))
		{
			std::ofstream	outfile(this->_outfile.c_str());
			if (outfile.fail())
				this->_printError(this->_outfile);
			else
			{
				size_t	pos = content.find(s1);
				while (pos != std::string::npos)
				{
					content.erase(pos, s1.length());
					content.insert(pos, s2);
					pos = content.find(s1, pos);
				}
				outfile << content;
				outfile.close();
			}
		}
		else
			std::cout << "Error: Empty file: " << this->_infile << std::endl;
		infile.close();
	}
}