#pragma once

# include <iostream>

class Account {

	private:

		int _id;
		int _value;
		int _loan;

		Account(int id, int value);
		~Account(void);

		void setId(const int id);
		void makeDeposit(const int value);
		void makeWithdrawal(const int value);
		void makeLoan(const int value);

		int getId(void) const;
		int getValue(void) const;
		int getLoan(void) const ;

		friend std::ostream& operator << (std::ostream& p_os, const Account& p_account) {
			p_os << "[" << p_account.getId() << "] - [" << p_account.getValue() << "]";
			return (p_os);
		}

	public :

	friend class Bank;
};
