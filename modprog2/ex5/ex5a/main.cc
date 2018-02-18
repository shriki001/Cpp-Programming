/*ex4a: a program that find and  print the minimum value of the BST
 * and print the values of all the leaf of the tree via inorder print
 * ============================================================================
 * written by Michael Shriki, id:305599417 login:michaelshr
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
#include "rectangle.h"
#include "util.h"
#include "compare.h"

// --------------- Using area -------------------------------------------------

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::nothrow;

// --------------- Prototype area ---------------------------------------------

void sort_rect(void* arr, int size, char sort_key);
void sort_points(void* arr, int size, char sort_key);
void check_alloc(void *arr);
void read_arr(void* arr, int size, void*(*pnt2cell)(void *, int),
		void (*read2cell)(void*));

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

void check_alloc(void *arr){

	if (arr == NULL) {
		cerr << "Cannot allocated memory \n";
		exit(EXIT_FAILURE);
	}
}

//-----------------------------------------------------------------------------
