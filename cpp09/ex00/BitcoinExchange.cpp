#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string data_path):_data(data_path)
{
	BitcoinExchange::fillRateMap();
}

BitcoinExchange(BitcoinExchange const & src);
BitcoinExchange & operator=(BitcoinExchange const & src);
~BitcoinExchange();

void BitcoinExchange::fillRateMap()
{
	std::ifstream data_file(this->_data.c_str());

	if (data_file.fail())
		std::cout << "Error: could not open source file." << std::endl;
	else {
		std::string line;
		std::getline(data_file, line);
		while (std::getline(data_file, line)) {
			std::stringstream	lineStream(line);
			std::string			key;
			float				value;

			if (std::getline(lineStream, key, ',') && lineStream >> value)
				this->_rates[key] = value;
			else
				std::cout << "Error: Invalid source file format." << std::endl;
		}
		data_file.close();
	}
}