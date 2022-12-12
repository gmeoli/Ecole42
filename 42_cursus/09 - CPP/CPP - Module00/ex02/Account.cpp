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

	return ;
}

Account::Account( int initial_deposit ){

	(void)initial_deposit;
	std::cout << "ciao" << std::endl;
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

	std::cout << "[" << now->tm_year + 1900 << now->tm_mon + 1 << now->tm_mday << "_" << now->tm_hour << now->tm_min << now->tm_sec << "] ";
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
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

	return ;
}

Account::Account(void){

	return ;
}
