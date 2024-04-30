#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount= 0;
int	Account::_totalNbDeposits= 0;
int	Account::_totalNbWithdrawals = 0;

//Display the timestamp at the beginning of each prompt.
//setfill('0') will add a zero before each month/day/etc instead of an empty space.
//Since localtime->tm_year counts the years since 1900, we add that to reflect current year
//Similarly, tm_mon gives the index (i.e. starting at 0)

void	Account::_displayTimestamp()
{
	std::time_t result = std::time(NULL);

	std::cout << std::setfill('0') <<"[" << 1900 + std::localtime(&result)->tm_year
				<< std::setw(2) << 1 + std::localtime(&result)->tm_mon
				<<  std::setw(2) << std::localtime(&result)->tm_mday
				<<  "_"
				<<  std::setw(2) << std::localtime(&result)->tm_hour
				<<  std::setw(2) << std::localtime(&result)->tm_min
				<<  std::setw(2) << std::localtime(&result)->tm_sec
				<< "] " << std::flush;
}

//Constructor with initial deposit, will display the creation message
Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = initial_deposit;
	_totalAmount += _amount;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created" << std::endl;
}

//Destructor that displays the closing message
Account::~Account()
{
	_nbAccounts--;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed" << std::endl;
}

int	Account::getNbAccounts()
{
	return _nbAccounts;
}

int	Account::getTotalAmount()
{
	return _totalAmount;
}

int	Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
				<< "total:" << getTotalAmount() << ";"
				<< "deposits:" << getNbDeposits() << ";"
				<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

//Displays index, amount at the beginning, amount deposited, new amount, and how many deposits this account has
void	Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";" << std::flush;
	_amount += deposit;
	std::cout << "deposit:" << deposit << ";"
				<< "amount:" << _amount << ";"
				<< "nb_deposit:" << _nbDeposits << std::endl;
}

//Displays index, amount at the beginning, amount withdrawn, new amount, and how many withdrawals this account has.
//If the withdrawal is larger than the amount, instead it displays "withdrawal:refused" after the amount
bool	Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";"
				<< "withdrawal:" << std::flush;
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawal << ";" << std::flush;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	std::cout << "amount:" << _amount << ";"
				<< "nb_deposit:" << _nbDeposits << std::endl;
	return true;
}

int	Account::checkAmount() const
{
	return _amount;
}

void	Account::displayStatus() const
{
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals << std::endl;
}
