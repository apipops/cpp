#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <algorithm>
# include <iterator>

# define EXIT_FAILURE 1

class BitcoinExchange
{
private:
	std::map<std::string, float>	_map;
	bool 							_valid;

	BitcoinExchange(); // Cannot be instanciated with no parameter

	void _fillRateMap(std::string & source_path);
	void _errorSourceFile(std::string const msg);
	void _convertLine(std::string & line) const;
	bool _checkLine(std::string & date, std::string & delim, std::string & value) const;
	bool _checkDate(std::string & date) const;
	bool _isDigitStr(std::string & str) const;
	bool _isFloatStr(std::string & str) const;


public:
	BitcoinExchange(std::string data_path);
	BitcoinExchange(BitcoinExchange const & src);
	BitcoinExchange & operator=(BitcoinExchange const & src);
	~BitcoinExchange();

	void convert(std::string const input_path);

};

#endif