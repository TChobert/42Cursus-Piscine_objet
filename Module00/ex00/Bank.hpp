#pragma once

#include <iostream>
#include <vector>

class Bank {

	private :

		int _liquidity;
		std::vector<Account *> _clientAccounts;

		void registerAccount(Account *account);

	public:

		Bank();
		~Bank(void);

		void createAccount(const int value);
		void removeAccount(const int id);
		void makeWithdrawal(const int id, const int value);
		void makeDeposit(const int id, const int value);
		void grantLoan(const int id, const int value);
		int getLiquidity(void) const;

		friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank) {
			p_os << "Bank informations : " << std::endl;
			p_os << "Liquidity : " << p_bank.getliquidity() << std::endl;
			for (auto &clientAccount : p_bank.clientAccounts) {
				p_os << *clientAccount << std::endl;
			}
			return (p_os);
	}
};
