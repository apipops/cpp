#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <algorithm>
# include <iterator>

# define EXIT_FAILURE 1
# define WRONG false
# define VALID true

class BitcoinExchange
{
private:
	std::string 					_path;
	std::map<std::string, float>	_map;

	BitcoinExchange();

public:
	BitcoinExchange(std::string data_path);
	BitcoinExchange(BitcoinExchange const & src);
	BitcoinExchange & operator=(BitcoinExchange const & src);
	~BitcoinExchange();

	// a supprimer apres 
	std::map<std::string, float> & getMap() { return _map; }

	void exitError(std::string const msg) const;
	void fillRateMap();
	void convert(std::string input_path) const;
	void convertLine(std::string & line) const;
	bool checkLine(std::string & line) const;
	bool checkDate(std::string date) const;
	bool isDigitString(std::string & str) const;

};

#endif