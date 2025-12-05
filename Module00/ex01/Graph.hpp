#pragma once

# include <iostream>
# include <list>
# include <cstdlib>
# include <iterator>
# include <vector>

# include "Vector2.hpp"

class Graph {

	private:

		size_t _size;
		std::list<Vector2> _points;

		const Vector2 getPoint(int index) const;
		void getHighestCoord(float& maxY, float& maxX) const;
		std::vector<std::string> initializeMatrix(const int columns, const int lines) const;
		void putPoints(std::vector<std::string>& matrix, const int lines, const int columns) const;
		void displayMatrix(std::vector<std::string>& matrix, const int lines, const float MaxX) const;

	public:

		Graph(void);
		~Graph(void);

		size_t getSize(void) const;

		void addPoint(Vector2& point);
		void Render(void) const;
};
