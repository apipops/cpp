#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <algorithm>
# include <iterator>

class BitcoinExchange
{
private:
	std::string 					_data;
	std::map<std::string, float>	_rates;

	BitcoinExchange();

public:
	BitcoinExchange(std::string data_path);
	BitcoinExchange(BitcoinExchange const & src);
	BitcoinExchange & operator=(BitcoinExchange const & src);
	~BitcoinExchange();

	void fillRateMap();
};

#endif