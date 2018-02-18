/*ex5b: a program that find and  print the minimum value of the BST
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
#include "point.h"
#include "rectangle.h"
#include "circle.h"
#include "gen.h"
#include "bst.h"

// --------------- Using area -------------------------------------------------

using std::cout;
using std::endl;
using std::nothrow;

// ------------- The Main code ------------------------------------------------

int main() {

	struct Node *circle_root = NULL, *rectangle_root = NULL;

	circle_root = build_sorted_tree(read_circle, allocate_circle,
			compare_circle_x);
	rectangle_root = build_sorted_tree(read_rect, allocate_rect,
			compare_rect_x);

	struct Gen_arr *circle_area = new (nothrow) Gen_arr;
	check_alloc(circle_area);
	struct Gen_arr *rectangle_area = new (nothrow) Gen_arr;
	check_alloc(rectangle_area);

	rectangle_area->used = 0;
	circle_area->used = 0;
	double max1 = -1, max2 = -1;
	over_tree(rectangle_root, area_rect, max1, rectangle_area);
	over_tree(circle_root, area_circle, max2, circle_area);

	print_shape(circle_area, print_circle);
	cout << endl;
	print_shape(rectangle_area, print_rect);
	cout << endl;

	free_bst(circle_root, delete_circle);
	free_bst(rectangle_root, delete_rect);
	delete circle_area;
	delete rectangle_area;

	return EXIT_SUCCESS;

}


