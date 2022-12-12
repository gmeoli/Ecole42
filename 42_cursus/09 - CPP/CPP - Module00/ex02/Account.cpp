#include "Account.hpp"
#include <iostream>
#include <time.h>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

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
	return ;
}

Account::Account( int initial_deposit ){
	(void)initial_deposit;
	this->_accountIndex = 0;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	return ;
}

Account::~Account(void){
	return ;
}

void	Account::makeDeposit( int deposit ){
	(void)deposit;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal ){
	(void)withdrawal;
	return true;
}

int		Account::checkAmount( void ) const {
	return 0;
}

void	Account::displayStatus( void ) const {
	time_t		t = time(0);
	struct tm	*now = localtime(&t);

	std::cout << "[" << now->tm_year + 1900 << now->tm_mon + 1 << now->tm_mday << "_" << now->tm_hour << now->tm_min << now->tm_sec << "] \n";
	return ;
}


///////////////////////////////////
//------------ PRIVATE ----------//
///////////////////////////////////

void	Account::_displayTimestamp( void ){
	std:: cout << "Timestamp" << std::endl;
}

Account::Account(void){
	return ;
}
