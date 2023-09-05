#include "BitcoinExchange.hpp"

int main() 
{
	BitcoinExchange btc("data.csv");
	std::map<std::string, float> map = btc.getMap();

	std::cout << map["2009-04-18"] << std::endl;
	std::cout << map["2010-10-16"] << std::endl;
	std::string key = "2010-10-1";
	if (map.find(key) != map.end())
		std::cout << map["201"] << std::endl;
	else
		std::cout << "doesn not exist" << std::endl;
	
	std::cout << (btc.checkDate("2009-04-31") ? "ok" : "not ok ") << std::endl; // not ok
	std::cout << (btc.checkDate("2009-05-31") ? "ok" : "not ok ") << std::endl; // ok
	std::cout << (btc.checkDate("2001-01-31") ? "ok" : "not ok ") << std::endl; // ok
	std::cout << (btc.checkDate("20013-04-31") ? "ok" : "not ok ") << std::endl; //not ok
	std::cout << (btc.checkDate("20fg-04-31") ? "ok" : "not ok ") << std::endl; // not ok
	std::cout << (btc.checkDate("2000-02-29") ? "ok" : "not ok ") << std::endl; // ok
	std::cout << (btc.checkDate("2001-02-29") ? "ok" : "not ok ") << std::endl; // not ok

	return (0);
}