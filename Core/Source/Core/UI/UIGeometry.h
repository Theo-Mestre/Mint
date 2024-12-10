#ifndef UI_GEOMETRY_H
#define UI_GEOMETRY_H

namespace Core
{
	namespace UI
	{
		struct Point
		{
			Point() : x(0.0f), y(0.0f) {}
			Point(float _x, float _y) : x(_x), y(_y) {}

			float x;
			float y;

			Point operator+(const Point& _other) const { return { x + _other.x, y + _other.y }; }

			Point operator-(const Point& _other) const { return { x - _other.x, y - _other.y }; }

			Point operator*(const Point& _other) const { return { x * _other.x, y * _other.y }; }

			Point operator/(const Point& _other) const { return { x / _other.x, y / _other.y }; }

			Point operator+(float _value) const { return { x + _value, y + _value }; }

			Point operator-(float _value) const { return { x - _value, y - _value }; }

			Point operator*(float _value) const { return { x * _value, y * _value }; }

			Point operator/(float _value) const { return { x / _value, y / _value }; }

		};

		struct Size
		{
			float width;
			float height;
		};

		struct Rect
		{
			Point position;
			Size size;
		};
	}
}

#endif