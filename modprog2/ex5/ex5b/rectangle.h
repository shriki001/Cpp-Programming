/*
 * rectangle.h
 *
 *  Created on: Sep 10, 2017
 *      Author: michael
 */
#include "circle.h"
#ifndef RECTANGLE_H_
#define RECTANGLE_H_

// --------------- Struct area ------------------------------------------------

struct Rectangle {
	struct Point _top_left, _bot_right;
};

//----------------------- Prototypes ------------------------------------------

void *allocate_rect();
bool read_rect(void *&p, void *allocate_item_func());
bool compare_rect_x(void *p1, void *p2);
double area_rect(void *p);
void print_rect(void* arr);
void delete_rect(void *p);




#endif /* RECTANGLE_H_ */
