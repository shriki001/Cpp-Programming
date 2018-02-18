#include <iostream>
#include <cmath>
#include "points.h"

// --------------- Using area -------------------------------------------------

using std::cin;

//-----------------------------------------------------------------------------

double get_x(Point point) {

	return point._x;
}

//-----------------------------------------------------------------------------

double get_y(Point point) {

	return point._y;
}

//-----------------------------------------------------------------------------

double radius(Point point) {

	return sqrt((get_x(point) * get_x(point)) + (get_y(point) * get_y(point)));
}

//-----------------------------------------------------------------------------

double alpha(Point point) {

	double ans;
	if (get_x(point) > 0 && get_y(point) > 0)
		ans = atan(get_y(point) / get_x(point));
	else if (get_x(point) < 0 && get_y(point) > 0)
		ans = M_PI - (atan(get_y(point) / get_x(point)));
	else if (get_x(point) < 0 && get_y(point) < 0)
		ans = M_PI + (atan(get_y(point) / get_x(point)));
	else
		ans = 2 * M_PI - (atan(get_y(point) / get_x(point)));
	return ans;
}

//-----------------------------------------------------------------------------

void * point2cell(void* p, int i) {

	return (void*) ((Point *) p + i);
}

//-----------------------------------------------------------------------------

void pnt2cell(void* p) {

	cin >> (*(struct Point *) p)._x >> (*(struct Point *) p)._y;
}

