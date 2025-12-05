#include "Graph.hpp"

Graph::Graph(void) : _size(0) {}

Graph::~Graph(void) {
	_points.clear();
}

size_t Graph::getSize(void) const {
	return (_size);
}

const Vector2 Graph::getPoint(int index) const {

	if (index < 0 || index >= _size)
		std::cerr << "Graph: invalid index" << std::endl;
	std::list<Vector2>::const_iterator it = _points.begin();
	std::advance(it, index);
	return (*it);
}

void Graph::addPoint(Vector2& point) {

	_points.push_back(point);
	_size = _points.size();
}

void Graph::getHighestCoord(float& maxY, float& maxX) const {

	for (int i = 0; i < _size; ++i) {
		Vector2 point = getPoint(i);

		if (point.getX() > maxX)
			maxX = point.getX();
		if (point.getY() > maxY)
			maxY = point.getY();
	}
}

std::vector<std::string> Graph::initializeMatrix(const int columns, const int lines) const {

	std::vector<std::string> matrix(lines, std::string(columns, '.'));

	for (int i = 0; i < lines; ++i) {

		int y = lines - 1 - i;
		if (y < 10)
			matrix[i][0] = '0' + y;
		else
			matrix[i][0] = '*';
	}
	return (matrix);
}

void Graph::putPoints(std::vector<std::string>& matrix, const int lines, const int columns) const {

	for (int i = 0; i < _size; ++i) {

		Vector2 point = getPoint(i);
		int x = static_cast<int>(point.getX()) + 1;
		int y = static_cast<int>(point.getY());
		if (x >= 1 && x < columns && y >= 0 && y < lines)
			matrix[lines - 1 - y][x] = 'X';
	}
}

void Graph::displayMatrix(std::vector<std::string>& matrix, const int lines, const float maxX) const {

	for (int i = 0; i < lines; ++i)
		std::cout << matrix[i] << std::endl;

	std::cout << " ";
	for (int x = 0; x <= static_cast<int>(maxX); ++x)
		std::cout << x % 10;
	std::cout << std::endl;
}

void Graph::Render() const {

	float maxX = 0, maxY = 0;
	getHighestCoord(maxY, maxX);

	int lines = static_cast<int>(maxY) + 1;
	int columns = static_cast<int>(maxX) + 2;

	std::vector<std::string> matrix = initializeMatrix(columns, lines);
	putPoints(matrix, lines, columns);
	displayMatrix(matrix, lines, maxX);
}
