#include <iostream>
#include "rectangle.h"

//-----------------------------------------------------------------------------

using std::cin;
using std::cout;
using std::nothrow;

//-----------------------------------------------------------------------------

void *allocate_rect() {

	struct Rectangle *rect = new (nothrow) struct Rectangle;
	check_alloc(rect);
	return rect;
}

//-----------------------------------------------------------------------------


bool read_rect(void *&p, void *allocate_item_func()) {

	double n1, n2, n3, n4;
	cin >> n1 >> n2 >> n3 >> n4;

	if (n1 == 0 && n2 == 0 && n3 == 0 && n4 == 0)
		return false;

	p = allocate_item_func();
	(*(struct Rectangle *) p)._top_left._x = n1;
	(*(struct Rectangle *) p)._top_left._y = n2;
	(*(struct Rectangle *) p)._bot_right._x = n3;
	(*(struct Rectangle *) p)._bot_right._y = n4;
	return true;
}

//-----------------------------------------------------------------------------

bool compare_rect_x(void *p1, void *p2) {

	return (*(struct Rectangle *) p1)._top_left._x
			>= (*(struct Rectangle *) p2)._top_left._x;
}

//-----------------------------------------------------------------------------

double area_rect(void *p) {

	double length = (*(Rectangle *) p)._top_left._x
			- (*(Rectangle *) p)._bot_right._x;
	double width = (*(Rectangle *) p)._bot_right._y
			- (*(Rectangle *) p)._top_left._y;
	return length * width;
}

//-----------------------------------------------------------------------------

void print_rect(void* arr) {

	cout << (*(struct Rectangle *) arr)._top_left._x << " "
			<< (*(struct Rectangle *) arr)._top_left._y << " "
			<< (*(struct Rectangle *) arr)._bot_right._x << " "
			<< (*(struct Rectangle *) arr)._bot_right._y << " ";
}

//-----------------------------------------------------------------------------

void delete_rect(void *p){

	delete (struct Rectangle *)p;
}


