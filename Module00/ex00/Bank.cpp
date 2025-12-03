#include "Bank.hpp"

Bank::Bank(void) : _liquidity(0) {}

Bank::~Bank(void) {

	for (std::vector<Account>::iterator it = _clientAccounts.begin(); it != _clientAccounts.end(); ++it) {
		delete *it;
	}
	_clientAccounts.clear();
}

void Bank::createAccount(int value) {

	if (value < 0) {
		std::cerr << "Bank: you can't create an account with a negative amount! Rejected!" << std::endl;
	}
	Account *newAccount = new Account(_id++, _value);
	//Prelever taxe 5%
	registerAccount(newAccount);
	std::cout << "Bank: account n* " << newAccount->id << " created with an amount of: " << newAccount->_value << std::endl;
}

void Bank::registerAccount(Account *account) {

	bool unique = false;

	while (!unique) {

		unique = true;
		for (std::vector<Account*>::iterator it == _clientAccounts.begin(); it != _clientAccounts.end(); ++it) {

			if ((*it)->_id = account->_id) {
				++account->_id;
				unique = false;
				break ;
			}
		}
	}
	_clientAccounts.push_back(account);
}

void Bank::removeAccount(int id) {

	for (std::vector<Account*>::iterator it = _clientAccounts.begin(); it != _clientAccounts.end(); ++it) {

		if ((*it)->_id == id) {
			std::cout << "Bank: deleting account n* " << (*it)->_id << std::endl;
			// 5 % ??
			delete *it;
			_clientAccounts.erase(*it);
			return ;
		}
	}
	std::cerr << "Bank: unknown account id, can't be deleted" << std::endl;
}

void Bank::makeWithdrawal(int id, int value) {

	Account *account = NULL;
	for (std::iterator<Account*>::it = _clientAccounts.begin(); it != _clientAccounts.end(); ++it) {

		if ((*it)->_id == id) {
			account = it;
		}
	}
	if (account != NULL) {

		if (account->_value - value > 0) {
			std::cerr << "Bank: insuffisant amount to make a withdrawal of " << value << ". Rejected." << std::endl;
			return ;
		}
		// tax of 5% !
		account->_value =- value;
		std::cout << "Bank: withdrawal of " << value << " made in account n* " << id << ". Account's value is now of " << account->_value << std::endl;
	} else {
		std::cerr << "Bank: unknown id" << std::endl;
	}
}

void Bank::makeDeposit(int id, int value) {

	Account *account = NULL;
	for (std::iterator<Account*>::it = _clientAccounts.begin(); it != _clientAccounts.end(); ++it) {

		if ((*it)->_id == id) {
			account = it;
		}
	}
	if (account != NULL) {

		account->_value += value;
		std::count << "Bank: deposit made on account n* " << id << ". Now at " << account->_value << std::endl;
		//tax 5%
	} else {
		std::cerr << "Bank: unknown id" << std::endl;
	}
}
