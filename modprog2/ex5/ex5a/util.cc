#include <iostream>
#include "rectangle.h"
#include "util.h"
#include "compare.h"

// --------------- Using area -------------------------------------------------

using std::cout;

//-----------------------------------------------------------------------------

void quicksort(void* arr, int from, int to,
		void* (*ptr2cell)(void *, int), bool (*compare)(void *, void *),
		void (*swap)(void *, void *)) {

	int pivot_place = partition(arr, from, to, ptr2cell, compare, swap);

	if (from < pivot_place - 1)
		quicksort(arr, from, pivot_place - 1, ptr2cell, compare, swap);

	if (to > pivot_place + 1)
		quicksort(arr, pivot_place + 1, to, ptr2cell, compare, swap);
}

//-----------------------------------------------------------------------------

int partition(void* arr, int from, int to, void* (*pnt2cell)(void *, int),
		bool (*compare)(void *, void *), void (*swap)(void *, void *)) {

	int pivot_place = from;

	for (int i = from + 1; i <= to; i++) {
		void *place1 = pnt2cell(arr, i);
		void *place2 = pnt2cell(arr, pivot_place);

		if (compare(place1, place2)) {
			swap(place1, pnt2cell(arr, pivot_place + 1));
			swap(pnt2cell(arr, pivot_place + 1), place2);
			pivot_place++;
		}
	}
	return pivot_place;
}

//-----------------------------------------------------------------------------

void swap_struct_points(void* p1, void *p2) {

	Point temp = *(Point*) p1;
	*(Point *) p1 = *(Point *) p2;
	*(Point *) p2 = temp;
}

//-----------------------------------------------------------------------------

void swap_struct_rects(void* p1, void *p2) {

	Rectangle temp = *(Rectangle*) p1;
	*(Rectangle *) p1 = *(Rectangle *) p2;
	*(Rectangle *) p2 = temp;
}

//-----------------------------------------------------------------------------

void print_arr(void* arr, int size, void*(*print_cell)(void *, int),
		void (*print_point)(void*)) {

	for (int i = 0; i < size; i++) {
		void * cell = print_cell(arr, i);
		print_point(cell);
	}
}

//-----------------------------------------------------------------------------

void print_point_op1(void *arr) {

	cout << get_x(*(struct Point *) arr) << " " << get_y(*(struct Point *) arr)
			<< " ";
}

//-----------------------------------------------------------------------------

void print_point_op2(void *arr) {

	cout << "(" << get_x(*(struct Point *) arr) << ", "
			<< get_y(*(struct Point *) arr) << ") ";
}

//-----------------------------------------------------------------------------

void print_rectangle_op1(void *arr) {

	cout << (*(struct Rectangle *) arr)._top_left._x << " "
			<< (*(struct Rectangle *) arr)._top_left._y << " "
			<< (*(struct Rectangle *) arr)._bottom_right._x << " "
			<< (*(struct Rectangle *) arr)._bottom_right._y<<" ";
}

//-----------------------------------------------------------------------------

void print_rectangle_op2(void *arr) {

	cout << "[(" << (*(struct Rectangle *) arr)._top_left._x << ", "
			<< (*(struct Rectangle *) arr)._top_left._y << "), " << "("
			<< (*(struct Rectangle *) arr)._bottom_right._x << ", "
			<< (*(struct Rectangle *) arr)._bottom_right._y << ")] ";
}

