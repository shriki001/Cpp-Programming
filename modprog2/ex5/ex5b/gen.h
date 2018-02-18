/*
 * gen.h
 *
 *  Created on: Sep 10, 2017
 *      Author: michael
 */
#include "bst.h"

const int N=5;

#ifndef GEN_H_
#define GEN_H_

// --------------- Struct area ------------------------------------------------

struct Gen_arr {
	void *arr[N];
	int used;
};

//----------------------- Prototypes ------------------------------------------

void over_tree(Node *root, double (*get_area)(void *), double &max,
		Gen_arr *&shape);
void print_shape(Gen_arr *shape, void (*print)(void *));




#endif /* GEN_H_ */
