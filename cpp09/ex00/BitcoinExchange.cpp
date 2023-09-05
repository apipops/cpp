#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string data_path):_path(data_path)
{
	BitcoinExchange::fillRateMap();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	*this = src;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & src)
{
	this->_path = src._path;
	this->_map = src._map;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::exitError(std::string const msg) const
{
	std::cout << "Error: " << msg << std::endl;
	exit(EXIT_FAILURE);
}

void BitcoinExchange::fillRateMap()
{
	std::ifstream data_file(this->_path.c_str());

	if (data_file.fail())
		BitcoinExchange::exitError("could not open source file.");
	else {
		std::string line;
		std::getline(data_file, line);
		while (std::getline(data_file, line)) {
			std::stringstream	lineStream(line);
			std::string			key;
			float				value;

			if (std::getline(lineStream, key, ',') && lineStream >> value)
				this->_map[key] = value;
			else {
				data_file.close();
				BitcoinExchange::exitError("invalid source file format.");
			}
		}
		data_file.close();
	}
}

void BitcoinExchange::convert(std::string input_path) const
{
	std::ifstream	input(input_path);
	std::string 	line;

	if (input.fail())
		exitError(" coult not open input file.");
	std::getline(input, line);
	if (line.compare("data | value")) {
		input.close();
		exitError("invalid input file format."); // verifier s'il faut fermer le fichier
	}
	while (std::getline(input, line))
		BitcoinExchange::convertLine(line);
	input.close();
}

void BitcoinExchange::convertLine(std::string & line) const
{
	if (BitcoinExchange::checkLine(line)) {
		
	}

}

bool BitcoinExcahnge::checkLine(std::string & line) const
{
	std::stringstream ss(line);
	std::string date, delim, value;

	ss >> date >> delim >> value;
	if (!checkDat(date))
		return (std::cout << "Error: bad input =>" << date << std::endl, false);
	if (delim.compare("|"))
		return (std::cout << "Error: bad input =>" << delim << std::endl, false);
	if (std::atof(value) < 0)
		return (std::cout << "Error: not a positive number." << std::endl, false);
	if (!std::atof(value) > 1000)
		return (std::cout << "Error: too large number." << std::endl, false);
	return true;
} 

bool BitcoinExchange::checkDate(std::string date) const
{
	std::stringstream ss(date);
	std::string year, month, day;
	int			iyear, imonth, iday;

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	std::getline(ss, year, '-');
	std::getline(ss, month, '-');
	std::getline(ss, day);
	if (!BitcoinExchange::isDigitString(year) || !BitcoinExchange::isDigitString(month)
		|| !BitcoinExchange::isDigitString(day))
		return false;
	iyear = std::atoi(year.c_str());	
	imonth = std::atoi(month.c_str());	
	iday = std::atoi(day.c_str());	
	if (iyear < 1 || imonth < 1 || imonth > 12 || iday < 1) // checking basic params
		return false;
	if (iday > 31 && (imonth == 1 || imonth == 3 || imonth == 5 || imonth == 7 || imonth == 8 || imonth == 10 || imonth == 12)) // mois de 31 jours
		return false;
	if (iday > 30 && (imonth == 4 || imonth == 6 || imonth == 9 || imonth == 11)) // mois de 30 jours
		return false;
	if (iday > 29 && imonth == 2 && ((iyear % 4 == 0 && iyear % 100 != 0) || (iyear % 400 == 0))) // fevrier & années bissextiles
		return false;
	if (iday > 28 && imonth == 2 && !((iyear % 4 == 0 && iyear % 100 != 0) || (iyear % 400 == 0))) // fevrier & années non bissextiles
		return false;
	return true;
}


bool BitcoinExchange::isDigitString(std::string & str) const
{
	for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        if (!std::isdigit(*it))
			return false;
	}
	return true;
}