#pragma once

# include <iostream>

# include "Position.hpp"
# include "Statistic.hpp"

class Worker {

	private:

		Position _coordonnee;
		Statistic _stat;

	Public:

		Worker(Position& coord, Statistic& stats);
		~Worker(void);
};
