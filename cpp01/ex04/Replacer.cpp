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
	if (s1.empty())
	{
		std::cout << "Error: Cannot replace empty string" <<std::endl;
		return;
	}
	std::ifstream	infile(this->_infile.c_str());
	if (infile.fail())
		this->_printError(this->_infile);
	else
	{
		std::string	old_content;
		if (std::getline(infile, old_content, '\0'))
		{
			std::string new_content = old_content;
			std::ofstream	outfile(this->_outfile.c_str());
			if (outfile.fail())
				this->_printError(this->_outfile);
			else
			{
				size_t	pos = old_content.find(s1);
				while (pos != std::string::npos)
				{
					new_content.erase(pos, s1.length());
					new_content.insert(pos, s2);
					pos = old_content.find(s1, pos + s1.length());
				}
				outfile << new_content;
				outfile.close();
			}
		}
		else
			std::cout << "Error: Empty file: " << this->_infile << std::endl;
		infile.close();
	}
}