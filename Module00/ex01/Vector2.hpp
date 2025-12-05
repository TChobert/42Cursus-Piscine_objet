#pragma once

# include <iostream>

class Vector2 {

	private:

		float X;
		float Y;

	public:

		Vector2(void);
		~Vector2(void);

		float getX(void) const;
		float getY(void) const;
		void setX(float X);
		void setY(float Y);
};
