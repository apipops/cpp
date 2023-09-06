#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange():_path("")
{
	BitcoinExchange::_fillRateMap();
}

BitcoinExchange::BitcoinExchange(std::string data_path):_path(data_path)
{
	BitcoinExchange::_fillRateMap();
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

void BitcoinExchange::_fillRateMap()
{
	std::ifstream data_file(this->_path.c_str());

	if (data_file.fail())
		BitcoinExchange::_exitError("could not open source file.");
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
				BitcoinExchange::_exitError("invalid source file format.");
			}
		}
		data_file.close();
	}
}

void BitcoinExchange::_exitError(std::string const msg) const
{
	std::cout << "Error: " << msg << std::endl;
	exit(EXIT_FAILURE);
}

void BitcoinExchange::convert(std::string input_path) const
{
	std::ifstream	input(input_path);
	std::string 	line;

	if (input.fail())
		_exitError("could not open input file.");
	std::getline(input, line);
	if (line.compare("date | value")) {
		input.close();
		_exitError("invalid input file format."); // verifier s'il faut fermer le fichier
	}
	while (std::getline(input, line))
		BitcoinExchange::_convertLine(line);
	input.close();
}

void BitcoinExchange::_convertLine(std::string & line) const
{
	std::stringstream ss(line);
	std::string date, delim, value;

	ss >> date >> delim >> value;
	if (!date.empty() && BitcoinExchange::_checkLine(date, delim, value)) {
		std::map<std::string, float>::const_iterator it = this->_map.upper_bound(date); // first element stricly superior to the date
		if (it == this->_map.begin())
			std::cout << "Error: date is too early => " << date << std::endl;
		else {
			it--;
			float result = it->second * std::atof(value.c_str());
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
	}
}

bool BitcoinExchange::_checkLine(std::string & date, std::string & delim, std::string & value) const
{
	if (!_checkDate(date))
		return (std::cout << "Error: bad input => " << date << std::endl, false);
	if (delim.empty() || value.empty())
		return (std::cout << "Error: no value." << std::endl, false);
	if (delim.compare("|"))
		return (std::cout << "Error: bad input => " << delim << std::endl, false);
	if (!BitcoinExchange::_isFloatStr(value))
		return (std::cout << "Error: not a decimal value => " << value << std::endl, false);
	if (std::atof(value.c_str()) < 0)
		return (std::cout << "Error: not a positive number." << std::endl, false);
	if (std::atof(value.c_str()) > 1000)
		return (std::cout << "Error: too large number." << std::endl, false);
	return true;
} 

bool BitcoinExchange::_checkDate(std::string & date) const
{
	std::stringstream ss(date);
	std::string year, month, day;
	int			iyear, imonth, iday;

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	std::getline(ss, year, '-');
	std::getline(ss, month, '-');
	std::getline(ss, day);
	if (!BitcoinExchange::_isDigitStr(year) || !BitcoinExchange::_isDigitStr(month)
		|| !BitcoinExchange::_isDigitStr(day))
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

bool BitcoinExchange::_isDigitStr(std::string & str) const
{
	for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        if (!std::isdigit(*it))
			return false;
	}
	return true;
}

bool BitcoinExchange::_isFloatStr(std::string & str) const
{
    size_t i = 0;
    bool dotFlag = false;
    bool digitFlag = false;
	
	if (str.empty())
		return false; // Empty string is not valid
	if (str[i] == '+' || str[i] == '-') // Check for an optional sign (+ or -)
		++i;
    while (i < str.size()) {
        if (isdigit(str[i]))
    		digitFlag = true;
        else if (str[i] == '.') {
            if (dotFlag || !digitFlag)
                return false; // More than one dot or dot before any digits is not valid
            dotFlag = true;
        }
		else
            return false; // Invalid character found
        i++;
    }
    return digitFlag; // At least one digit is required
}
