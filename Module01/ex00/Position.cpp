#include "Position.hpp"

Position::Position(void) : _x(0), _y(0), _z(0) {
	std::cout << "Position: default constructor called" << std::endl;
}

Position::Position(int x, int y, int z) : _x(x), _y(y), _z(z) {
	std::cout << "Position: parametrized constructor called" << std::endl;
}

Position::~Position(void) {
	std::cout << "Position: destructor called" << std::endl;
}

const int Position::getX(void) const {
	return _x;
}

const int Position::getY(void) const {
	return _y;
}

const int Position::getZ(void) const {
	return _z;
}

void Position::setX(int x) {
	_x = x;
}

void Position::setY(int y) {
	_y = y;
}

void Position::setZ(int z) {
	_z = z;
}
