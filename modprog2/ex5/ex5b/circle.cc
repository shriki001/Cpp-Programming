#include <iostream>
#include <cmath>
#include "circle.h"

//-----------------------------------------------------------------------------

using std::cin;
using std::cout;
using std::nothrow;

//-----------------------------------------------------------------------------

void *allocate_circle() {

	struct Circle *circle = new (nothrow) struct Circle;
	check_alloc(circle);
	return circle;
}

//-----------------------------------------------------------------------------

bool read_circle(void *&p, void *allocate_item_func()) {

	double n1, n2;
	cin >> n1 >> n2;

	if (n1 == 0 && n2 == 0)
		return false;

	p = allocate_item_func();
	(*(struct Circle *) p)._center._x = n1;
	(*(struct Circle *) p)._center._y = n2;
	cin >> (*(struct Circle *) p)._r;
	return true;
}

//-----------------------------------------------------------------------------

bool compare_circle_x(void *p1, void *p2) {

	return (*(struct Circle *) p1)._center._x
			>= (*(struct Circle *) p2)._center._x;
}

//-----------------------------------------------------------------------------

double area_circle(void *p) {

	double radius_power = ((*(Circle *) p)._r * (*(Circle *) p)._r);
	return M_PI * radius_power;
}

//-----------------------------------------------------------------------------

void print_circle(void *arr) {

	cout << (*(struct Circle *) arr)._center._x << " "
			<< (*(struct Circle *) arr)._center._y << " "
			<< (*(struct Circle *) arr)._r << " ";
}

//-----------------------------------------------------------------------------

void delete_circle(void *p){

	delete (struct Circle *)p;
}




