#include "Account.hpp"

Account::Account(int id, int value) : _id(id), _value(value), _loan(0) {}

Account::~Account(void) {};

void Account::setId(const int id) {
	_id = id;
}

void Account::makeDeposit(const int value) {
	_value += value;
}
// Logique metier ici ou dans bank ??

void Account::makeWithdrawal(const int value) {
	_value -= value;
}

void Account::makeLoan(const int value) {
	_loan += value;
}

int Account::getId(void) const {
	return (_id);
}

int Account::getValue(void) const {
	return (_value);
}

int Account::getLoan(void) const {
	return (_loan);
}
