#pragma once
class Rectangle {
	double x, y;
	double width, height;

	double right() const { return x + width / 2; }
	double left() const { return x - width / 2; }
	double top() const { return y + height / 2; }
	double bottom() const { return y - height / 2; }

public:
	Rectangle(double x, double y, double width, double height):
		x(x), y(y), width(width), height(height) {}


	bool collidesWith(const Rectangle& other) {
		if (right() < other.left() || left() > other.right())
			return false;

		if (top() < other.bottom() || bottom() > other.top())
			return false;

		return true;
	}
};
