#pragma once

# include <iostream>

class Statistic {

	private:

		int _level;
		int _exp;

	public:

		Statistic(void);
		Statistic(int level, int exp);
		~Statistic(void);
		const int getLevel(void) const;
		const int getExp(void) const;
};
