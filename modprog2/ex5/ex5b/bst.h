/*
 * bst.h
 *
 *  Created on: Sep 10, 2017
 *      Author: michael
 */
#include "point.h"
#ifndef BST_H_
#define BST_H_

// --------------- Struct area ------------------------------------------------

struct Node {
	void *_data;
	struct Node *_left, *_right;
};

//----------------------- Prototypes ------------------------------------------

struct Node *build_sorted_tree(
		bool (*read_item_func)(void *&, void *allocate_item_func()),
		void *allocate_item_func(), bool cmp_func(void*, void*));
void insert_into_tree(Node *&root, void *new_item, bool cmp_func(void*, void*));
void insert_node(Node *&root, Node *new_node, void* new_item,
		bool cmp_func(void*, void*));
void free_bst(Node *root,void delete_func(void *));




#endif /* BST_H_ */
