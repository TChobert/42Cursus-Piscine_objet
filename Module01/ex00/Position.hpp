#pragma once

class Position {

	private:

		int _x;
		int _y;
		int _z;

	public:

		Position(void);
		~Position(void);

		const int getX(void) const;
		const int getY(void) const;
		const int getZ(void) const;

		//setters ?
};
