#pragma once

# include "Position.hpp"
# include "Statistic.hpp"

class Worker {

	private:

		Position _coordonnee;
		Statistic _stat;

	Public:

		Worker(Position coord, Statistic stat);
		~Worker(void);
};
