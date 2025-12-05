#pragma once

class Statistic {

	private:

		int _level;
		int _exp;

	public:

		Statistic(void);
		~Statistic(void);
		const int getLevel(void) const;
		const int getExp(void) const;
};
