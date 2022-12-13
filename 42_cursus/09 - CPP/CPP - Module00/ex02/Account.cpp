#include "Account.hpp"
#include <iostream>
#include <time.h>

///////////////////////////////////
//------------ PUBLIC -----------//
///////////////////////////////////

int Account::getNbAccounts( void ){

	return _nbAccounts;
}

int	Account::getTotalAmount( void ){

	return _totalAmount;
}

int	Account::getNbDeposits( void ){

	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ){

	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ){

	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
	return ;
}

Account::Account( int initial_deposit ){

	Account::_displayTimestamp();
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	std::cout << "index:" << _nbAccounts;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
	_nbAccounts++;
	return ;
}

void	Account::makeDeposit( int deposit ){

	Account::_displayTimestamp();
	_nbDeposits = 1;
	_totalNbDeposits += 1;
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount += deposit; 
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
	_totalAmount += deposit;
	return ;
}


bool	Account::makeWithdrawal( int withdrawal ){

	Account::_displayTimestamp();

	bool i;

	if (_amount - withdrawal <= 0){
		i = false;
		_nbWithdrawals = 0;
		std::cout << "index:" << _accountIndex;
		std::cout << ";p_amount:" << _amount;
		std::cout << ";withdrawal:refused" << std::endl;
		return i;
	}
	else {
		i = true;
		_nbWithdrawals = 1;
		_totalNbWithdrawals += 1;
		std::cout << "index:" << _accountIndex;
		std::cout << ";p_amount:" << _amount;
		std::cout << ";withdrawal:" << withdrawal;
		_amount -= withdrawal;
		std::cout << ";amount:" << _amount;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		_totalAmount -= withdrawal;
		return i;
	}
	return i;
}

int		Account::checkAmount( void ) const {
	
	return 0;
}

void	Account::displayStatus( void ) const {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}

Account::~Account(void){
	
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
	return ;
}

///////////////////////////////////
//------------ PRIVATE ----------//
///////////////////////////////////

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void ){

	time_t		t = time(0);
	struct tm	*now = localtime(&t);

	std::cout << "[" << now->tm_year + 1900 << now->tm_mon + 1 << now->tm_mday << "_" << now->tm_hour << now->tm_min << now->tm_sec << "] ";
	return ;
}

Account::Account(void){

	return ;
}
