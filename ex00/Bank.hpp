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

		void createAccount(int amount);
		void removeAccount(int id);

		friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank) {
			p_os << "Bank informations : " << std::endl;
			p_os << "Liquidity : " << p_bank.liquidity << std::endl;
			for (auto &clientAccount : p_bank.clientAccounts) {
				p_os << *clientAccount << std::endl;
			}
			return (p_os);
	}
};
