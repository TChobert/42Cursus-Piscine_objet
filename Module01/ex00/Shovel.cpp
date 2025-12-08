#include "Shovel.hpp"

Shovel::Shovel(void) : _numberOfUses(0) {
	std::cout << "Shovel: default constructor called" << std::endl;
}

Shovel::~Shovel(void) {
	std::cout << "Shovel: destructor called" << std::endl;
}

const int Shovel::getNumberOfUses(void) const {
	return (_numberOfUses);
}

void Shovel::setNumerbOfUses(int nb) {
	_numberOfUses = nb;
}
