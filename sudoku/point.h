#ifndef POINT_H
#define POINT_H

class point 
{
private:
	int x;
	int y;

public:
	point();

	point(int x, int y);

	void set_x(const int _x);

	void set_y(const int _y);

	int get_x() const;

	int get_y() const;
};

#endif