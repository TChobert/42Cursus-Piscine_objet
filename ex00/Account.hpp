#pragma once

# include <vector>
# include <iostream>

#include "Bank.hpp"

class Account {

	private:

		int _id;
		int _value;

	public:

		Account(int id, int value);
		~Account(void);

		int getId(void);
		int getValue(void);

		void setId(int id);

		friend std::ostream& operator << (std::ostream& p_os, const Account& p_account) {
			p_os << "[" << p_account.getIdd << "] - [" << p_account.getValue << "]";
			return (p_os);
		}

	friend class Bank;
};
