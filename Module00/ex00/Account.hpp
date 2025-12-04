#pragma once

# include <iostream>

class Account {

	private:

		int _id;
		int _value;
		int _loan;

		Account(int id, int value);
		~Account(void);

		void setId(int id);

		friend std::ostream& operator << (std::ostream& p_os, const Account& p_account) {
			p_os << "[" << p_account._id << "] - [" << p_account._value << "]";
			return (p_os);
		}

	public :

	friend class Bank;
};
