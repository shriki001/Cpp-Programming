#include <iostream>
#include <cmath>
#include "rectangle.h"

// --------------- Using area -------------------------------------------------

using std::cin;

//-----------------------------------------------------------------------------

double area(Rectangle rect) {

	double length = rect._top_left._x - rect._bottom_right._x;
	double width = rect._bottom_right._y - rect._top_left._y;
	return length * width;
}

//-----------------------------------------------------------------------------

double circumference(Rectangle rect) {

	double length = get_abs(rect._top_left._x - rect._bottom_right._x);
	double width = get_abs(rect._bottom_right._y - rect._top_left._y);
	return 2 * (length + width);
}

//-----------------------------------------------------------------------------

double diagonal_length(Rectangle rect) {

	return sqrt(
			((rect._top_left._x - rect._bottom_right._x)
					* (rect._top_left._x - rect._bottom_right._x))
					- ((rect._top_left._y - rect._bottom_right._y)
							* (rect._top_left._y - rect._bottom_right._y)));
}

//-----------------------------------------------------------------------------

double get_abs(double x) {
	if (x < 0)
		return -x;
	return x;
}


//-----------------------------------------------------------------------------

void * rec2cell(void* p, int i) {

	return (void*) ((Rectangle *) p + i);
}

//-----------------------------------------------------------------------------

void pnt2rec_cell(void* p) {

	cin >> (*(struct Rectangle *) p)._top_left._x
			>> (*(struct Rectangle *) p)._top_left._y
			>> (*(struct Rectangle *) p)._bottom_right._x
			>> (*(struct Rectangle *) p)._bottom_right._y;
}
