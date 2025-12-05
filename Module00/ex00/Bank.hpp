#pragma once

# include <iostream>
# include <vector>

# include "Account.hpp"

class Bank {

	private :

		int _liquidity;
		int _currentId;
		std::vector<Account *> _clientAccounts;

		void registerAccount(Account *account);
		Account *getAccount(const int id) const;
		void collectPercentage(const int value, const int percentage);

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
			p_os << "Liquidity : " << p_bank.getLiquidity() << std::endl;
			for (std::vector<Account *>::const_iterator it = p_bank._clientAccounts.begin(); it != p_bank._clientAccounts.end(); ++it) {
				p_os << **it << std::endl;
			}
			return (p_os);
	}
};
