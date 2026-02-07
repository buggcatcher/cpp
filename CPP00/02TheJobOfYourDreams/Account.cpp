/*

conti vengono aperti e chiusi.
nel mentre le transazioni vengono tracciate.

in test.cpp int w[]={} mostra i prelievi chiesti da ciascun account.
se traccio index 5 con awk vedo che l'account 5, con saldo 23, tenta di prelevare 275 e viene rifiutato.
deduco che p_amount stia per previous_amount.

vedo che tutti gli account fanno un deposito e per ognuno appare nb_deposits:1
deduco che nb_ stia per "number of" deposits/withdrawals.

*/

#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    this->_accountIndex = Account::_nbAccounts++; 
    Account::_totalAmount += initial_deposit;
    
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

int Account::_nbAccounts = 0; // static int nel private
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void) {
    std::time_t t = std::time(NULL);
    std::tm* tm = std::localtime(&t);
    char buff[20];
    std::strftime(buff, sizeof(buff), "[%Y%m%d_%H%M%S] ", tm);
    std::cout << buff;
}

/*in cpp11 puoi fare a meno del buffer
void Account::_displayTimestamp(void) {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::cout << "[" << std::put_time(&tm, "%Y%m%d_%H%M%S") << "] ";
}*/

int Account::getNbAccounts(void) {
    return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {
    return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
    this->_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << (this->_amount - deposit) << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	
	if (withdrawal > this->_amount) {
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	} else {
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals += 1;

		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
}

int Account::checkAmount(void) const {
    return this->_amount;
}