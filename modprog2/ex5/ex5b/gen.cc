#include <iostream>
#include "gen.h"
#include "bst.h"

//-----------------------------------------------------------------------------

void over_tree(Node *root, double (*get_area)(void *), double &max,
		Gen_arr *&shape) {

	if (root != NULL) {
		over_tree(root->_left, get_area, max, shape);
		double curr = get_area(root->_data);
		if (curr > max) {
			max = curr;
			shape->arr[0] = root->_data;
			shape->used = 1;
		} else if (curr == max) {
			shape->arr[shape->used] = root->_data;
			shape->used++;
		}
		over_tree(root->_right, get_area, max, shape);
	}
}

//-----------------------------------------------------------------------------

void print_shape(Gen_arr *shape, void (*print)(void *)) {
	for (int i = 0; i < shape->used; i++) {
		print(shape->arr[i]);
	}
}

