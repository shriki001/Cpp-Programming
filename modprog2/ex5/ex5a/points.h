/*
 * points.h
 *
 *  Created on: Sep 10, 2017
 *      Author: michael
 */

#ifndef POINTS_H_
#define POINTS_H_

// --------------- Struct area ------------------------------------------------

struct Point {
	double _x, _y;
};
//-----------------------------------------------------------------------------

void *point2cell(void* p, int i);
void pnt2cell(void* p);
double get_x(Point point);
double get_y(Point point);
double radius(Point point);
double alpha(Point point);
bool compare_x(void *p1, void *p2);
bool compare_y(void *p1, void *p2);
bool compare_radius(void *p1, void *p2);
bool compare_alpha(void *p1, void *p2);
void print_point_op1(void *arr);
void print_point_op2(void *arr);

//-----------------------------------------------------------------------------

#endif /* POINTS_H_ */
