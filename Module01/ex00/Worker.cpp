#include "Worker.hpp"

Worker::Worker(Position& coord, Statistic& stats) : _coordonnee(coord), _stat(stats) {
	std::cout << "Worker: parametrized constructor called" << std::endl;
}

Worker::~Worker(void) {
	std::cout << "Worker: destructor called" << std::endl;
}
