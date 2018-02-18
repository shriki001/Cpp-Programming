/*
 * circle.h
 *
 *  Created on: Sep 10, 2017
 *      Author: michael
 */
#include "point.h"
#ifndef CIRCLE_H_
#define CIRCLE_H_

// --------------- Struct area ------------------------------------------------

struct Circle {
	struct Point _center;
	double _r;
};

//----------------------- Prototypes ------------------------------------------

void *allocate_circle();
bool read_circle(void *&p, void *allocate_item_func());
bool compare_circle_x(void *p1, void *p2);
double area_circle(void *p);
void print_circle(void *arr);
void delete_circle(void *p);




#endif /* CIRCLE_H_ */
