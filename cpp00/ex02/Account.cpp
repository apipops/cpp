#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit):_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) 
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	this->_accountIndex = _nbAccounts - 1;
	_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "closed" << std::endl;
}

void	Account::_displayTimestamp(void)
{
    std::time_t time;
	std::time(&time);

    std::cout 	<< std::setfill('0')
				<< "["
				<< 1900 + std::localtime(&time)->tm_year
                << std::setw(2) << std::localtime(&time)->tm_mon + 1
                <<  std::setw(2) << std::localtime(&time)->tm_mday
                <<  "_"
                <<  std::setw(2) << std::localtime(&time)->tm_hour
                <<  std::setw(2) << std::localtime(&time)->tm_min
                <<  std::setw(2) << std::localtime(&time)->tm_sec 
                << "] ";
}

int	Account::getNbAccounts(void) 
{
	return (_nbAccounts); 
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout 	<< "accounts:" << _nbAccounts << ";"
				<< "total:" << _totalAmount << ";"
				<< "deposits:" << _totalNbDeposits << ";"
				<< "withdrawals:" << _totalNbWithdrawals << std::endl;	
}

void	Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->_amount << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << this->_amount + deposit << ";"
				<< "nb_deposits:" << this->_nbDeposits + 1 << std::endl;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->_amount << ";";
	if (withdrawal > this->_amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << "withdrawal:" << withdrawal << ";"
				<< "amount:" << this->_amount - withdrawal << ";"
				<< "nb_withdrawals:" << this->_nbWithdrawals + 1 << std::endl;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "deposits:" << this->_nbDeposits << ";"
				<< "withdrawals:" << this->_nbWithdrawals << std::endl;	
}