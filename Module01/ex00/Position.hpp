#pragma once

class Position {

	private:

		int _x;
		int _y;
		int _z;

	public:

		Position(void);
		Position(int x, int y, int z);
		~Position(void);

		const int getX(void) const;
		const int getY(void) const;
		const int getZ(void) const;

		void setX(int x);
		void setY(int y);
		void setZ(int z);
};
