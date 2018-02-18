#include "rectangle.h"
#include "compare.h"

bool compare_x(void *p1, void *p2) {

	return get_x(*(Point *) p1) < get_x(*(Point *) p2);
}

//-----------------------------------------------------------------------------

bool compare_y(void *p1, void *p2) {

	return get_y(*(Point *) p1) < get_y(*(Point *) p2);
}

//-----------------------------------------------------------------------------

bool compare_radius(void *p1, void *p2) {

	return radius(*(Point *) p1) < radius(*(Point *) p2);
}

//-----------------------------------------------------------------------------

bool compare_alpha(void *p1, void *p2) {

	return alpha(*(Point *) p1) < alpha(*(Point *) p2);
}

bool compare_area(void *p1, void *p2) {

	return area(*(Rectangle *) p1) < area(*(Rectangle *) p2);
}

//-----------------------------------------------------------------------------

bool compare_circum(void *p1, void *p2) {

	return circumference(*(Rectangle *) p1) < circumference(*(Rectangle *) p2);
}

//-----------------------------------------------------------------------------

bool compare_diagonal_len(void *p1, void *p2) {

	return diagonal_length(*(Rectangle *) p1)
			< diagonal_length(*(Rectangle *) p2);
}
