#include "Bank.hpp"

Bank::Bank(void) : _liquidity(0) {}

Bank::~Bank(void) {

	for (std::vector<Account>::iterator it = _clientAccounts.begin(); it != _clientAccounts.end(); ++it) {
		delete *it;
	}
	_clientAccounts.clear();
}

void Bank::createAccount(int value) {

	Account *newAccount = new Account(_id++, _value);
	//Prelever taxe 5%
	registerAccount(newAccount);
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
