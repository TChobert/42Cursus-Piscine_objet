#pragma once

#include <iostream>

class Shovel {

	private :

	int _numberOfUses;

	public :

	Showel(void);
	~Showel(void);

	const int getNumberOfUses(void) const;
	void setNumerbOfUses(int nb);
};
