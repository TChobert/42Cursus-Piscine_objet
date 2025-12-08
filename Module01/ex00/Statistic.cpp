#include "Statistic.hpp"

Statistic::Statistic(void) : _level(0), _exp(0) {
	std::cout << "Statistic: default constructor called" << std::endl;
}

Statistic::Statistic(int level, int exp) : _level(level), _exp(exp) {
	std::cout << "Statistic: parametrized constructor called" << std::endl;
}

Statistic::~Statistic(void) {
	std::cout << "Statistic: destructor called" << std::endl;
}
