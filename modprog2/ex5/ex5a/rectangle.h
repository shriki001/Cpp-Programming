/*
 * rectangle.h
 *
 *  Created on: Sep 10, 2017
 *      Author: michael
 */
#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include "points.h"
// --------------- Struct area ------------------------------------------------

struct Rectangle {
	struct Point _top_left, _bottom_right;
};

// ----------------------------------------------------------------------------

void *rec2cell(void* p, int i);
void pnt2rec_cell(void* p);
double area(Rectangle rect);
double circumference(Rectangle rect);
double diagonal_length(Rectangle rect);
double get_abs(double x);

#endif /* RECTANGLE_H_ */
