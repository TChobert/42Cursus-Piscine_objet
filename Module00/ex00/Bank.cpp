#include "Bank.hpp"

Bank::Bank(void) : _liquidity(0), _currentId(0) {}

Bank::~Bank(void) {

	for (std::vector<Account *>::iterator it = _clientAccounts.begin(); it != _clientAccounts.end(); ++it) {
		delete *it;
	}
	_clientAccounts.clear();
}

Account *Bank::getAccount(const int id) const {

	for (std::vector<Account *>::const_iterator it = _clientAccounts.begin(); it != _clientAccounts.end(); ++it) {

		if ((*it)->getId() == id) {
			return (*it);
		}
	}
	return (NULL);
}

void Bank::collectPercentage(const int value, const int percentage) {

	const int tax = (value * percentage) / 100;
	_liquidity += tax;
}

void Bank::createAccount(const int value) {

	if (value < 0) {
		std::cerr << "Bank: you can't create an account with a negative amount! Rejected!" << std::endl;
	} else {
		Account *newAccount = new Account(_currentId++, value);
		collectPercentage(value, 5);
		registerAccount(newAccount);
		std::cout << "Bank: account n* " << newAccount->getId() << " created with an amount of: " << newAccount->getValue() << std::endl;
	}
}

void Bank::registerAccount(Account *account) {
	_clientAccounts.push_back(account);
}

void Bank::removeAccount(const int id) {

	for (std::vector<Account*>::iterator it = _clientAccounts.begin(); it != _clientAccounts.end(); ++it) {

		if ((*it)->getId() == id) {
			std::cout << "Bank: deleting account n* " << (*it)->getId() << std::endl;
			delete *it;
			_clientAccounts.erase(it);
			return ;
		}
	}
	std::cerr << "Bank: unknown account id, can't be deleted" << std::endl;
}

void Bank::grantLoan(const int id, const int value) {

	if (value > _liquidity) {
		std::cerr << "Bank: insuffisant credits to grant a loan of " << value << std::endl;
		return ;
	}
	Account *account = getAccount(id);
	if (account != NULL) {
		account->makeLoan(value);
		_liquidity -= value;
		std::cout << "Bank: loan of " << value << " granted to account n* " << account->getId() << std::endl;
	} else {
		std::cerr << "Bank: unknown id: " << id << std::endl;
	}
}

void Bank::makeWithdrawal(const int id, const int value) {

	Account *account = getAccount(id);
	if (account != NULL) {

		if (value > account->getValue()) {
			std::cerr << "Bank: insuffisant amount to make a withdrawal of " << value << ". Rejected." << std::endl;
			return ;
		}
		account->makeWithdrawal(value);
		std::cout << "Bank: withdrawal of " << value << " made in account n* " << id << ". Account's value is now of " << account->getValue() << std::endl;
	} else {
		std::cerr << "Bank: unknown id: " << id << std::endl;
	}
}

void Bank::makeDeposit(const int id, const int value) {

	Account *account = getAccount(id);
	if (account != NULL) {

		account->makeDeposit(value);
		std::cout << "Bank: deposit made on account n* " << id << ". Now at " << account->getValue() << std::endl;
		collectPercentage(value, 5);
	} else {
		std::cerr << "Bank: unknown id: " << id << std::endl;
	}
}

int Bank::getLiquidity(void) const {

	return (_liquidity);
}
