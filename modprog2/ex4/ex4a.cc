/*ex4a: a program that find and  print the minimum value of the BST
 * and print the values of all the leaf of the tree via inorder print
 * ============================================================================
 * written by Michael Shriki, login:michaelshr
 *
 * the program find and  print the minimum value of the BST
 * and print the values of all the leaf of the tree via inorder print
 *
 * Input: number for BST
 * ============================================================================
 * Output: the program print the minimum value and the leafs via inorder print
 * ============================================================================
 */

#include <iostream>
#include <cstdlib>
#include <cmath>

// --------------- Using area -------------------------------------------------

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::nothrow;

// --------------- Struct area ------------------------------------------------

struct Point {
	double _x, _y;
};

struct Rectangle {
	struct Point _top_left, _bottom_right;
};

// --------------- Prototype area ---------------------------------------------

void read_arr(void* arr, int size, void*(*pnt2cell)(void *, int),
		void (*read2cell)(void*));
void *point2cell(void* p, int i);
void pnt2cell(void* p);
void *rec2cell(void* p, int i);
void pnt2rec_cell(void* p);

double get_x(Point point);
double get_y(Point point);
double radius(Point point);
double alpha(Point point);

double area(Rectangle rect);
double circumference(Rectangle rect);
double diagonal_length(Rectangle rect);

bool compare_x(void *p1, void *p2);
bool compare_y(void *p1, void *p2);
bool compare_radius(void *p1, void *p2);
bool compare_alpha(void *p1, void *p2);
bool compare_area(void *p1, void *p2);
bool compare_circum(void *p1, void *p2);
bool compare_diagonal_len(void *p1, void *p2);
double get_abs(double x);

void quicksort(void* arr, int from, int to,
		void* (*ptr2cell)(void *, int), bool (*compare)(void *, void *),
		void (*swap)(void *, void *));

int partition(void* arr, int from, int to, void* (*pnt2cell)(void *, int),
		bool (*compare)(void *, void *), void (*swap)(void *, void *));
void swap_struct_points(void* p1, void *p2);
void swap_struct_rects(void* p1, void *p2);

void sort_rect(void* arr, int size, char sort_key);
void sort_points(void* arr, int size, char sort_key);

void print_arr(void* arr, int size, void*(*print_cell)(void *, int),
		void (*print_point)(void*));
void print_point_op1(void *arr);
void print_point_op2(void *arr);
void print_rectangle_op1(void *arr);
void print_rectangle_op2(void *arr);
void check_alloc(void *arr);

// ------------- The Main code ------------------------------------------------

int main() {

	char print_value;
	int size_of_points_arr, size_of_rectangles_arr;

	cin >> print_value;
	cin >> size_of_points_arr;

	struct Point *points = new (nothrow) struct Point[size_of_points_arr];
	check_alloc(points);
	read_arr(points, size_of_points_arr, point2cell, pnt2cell);

	cin >> size_of_rectangles_arr;

	struct Rectangle *rectangles =
			new (nothrow) struct Rectangle[size_of_rectangles_arr];
	check_alloc(rectangles);
	read_arr(rectangles, size_of_rectangles_arr, rec2cell, pnt2rec_cell);

	char sort_key;
	cin >> sort_key;
	sort_points(points, size_of_points_arr, sort_key);

	cin >> sort_key;
	sort_rect(rectangles, size_of_rectangles_arr, sort_key);

	if (print_value == '-') {
		print_arr(points, size_of_points_arr, point2cell, print_point_op1);
		cout << endl;
		print_arr(rectangles, size_of_rectangles_arr, rec2cell,
				print_rectangle_op1);
	} else {
		print_arr(points, size_of_points_arr, point2cell, print_point_op2);
		cout << endl;
		print_arr(rectangles, size_of_rectangles_arr, rec2cell,
				print_rectangle_op2);
	}
	cout << endl;

	delete[] points;
	delete[] rectangles;

	return EXIT_SUCCESS;
}

//-----------------------------------------------------------------------------

void read_arr(void* arr, int size, void*(*pnt2cell)(void *, int),
		void (*read2cell)(void*)) {

	for (int i = 0; i < size; i++)
		read2cell(pnt2cell(arr, i));
}

//-----------------------------------------------------------------------------

void * point2cell(void* p, int i) {

	return (void*) ((Point *) p + i);
}

//-----------------------------------------------------------------------------

void pnt2cell(void* p) {

	cin >> (*(struct Point *) p)._x >> (*(struct Point *) p)._y;
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

void sort_points(void* arr, int size, char sort_key) {

	switch (sort_key) {
	case 'x':
		quicksort(arr, 0, size - 1, point2cell, compare_x, swap_struct_points);
		break;
	case 'y':
		quicksort(arr, 0, size - 1, point2cell, compare_y, swap_struct_points);
		break;
	case 'r':
		quicksort(arr, 0, size - 1, point2cell, compare_radius,
				swap_struct_points);
		break;
	case 'a':
		quicksort(arr, 0, size - 1, point2cell, compare_alpha,
				swap_struct_points);
		break;
	}
}

//-----------------------------------------------------------------------------

void sort_rect(void* arr, int size, char sort_key) {

	switch (sort_key) {
	case 'a':
		quicksort(arr, 0, size - 1, rec2cell, compare_area, swap_struct_rects);
		break;
	case 'c':
		quicksort(arr, 0, size - 1, rec2cell, compare_circum,
				swap_struct_rects);
		break;
	case 'd':
		quicksort(arr, 0, size - 1, rec2cell, compare_diagonal_len,
				swap_struct_rects);
		break;
	}
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

// ===================== quick sort functions ===============================//

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
// ========================================================================= //

//======================= compare function ================================= //

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

//-----------------------------------------------------------------------------

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

// ========================================================================= //

void check_alloc(void *arr){

	if (arr == NULL) {
		cerr << "Cannot allocated memory \n";
		exit(EXIT_FAILURE);
	}
}





