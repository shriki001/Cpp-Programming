#include <iostream>
#include "bst.h"

//-----------------------------------------------------------------------------

using std::nothrow;

//-----------------------------------------------------------------------------

struct Node *build_sorted_tree(
		bool (*read_item_func)(void *&, void *allocate_item_func()),
		void *allocate_item_func(), bool cmp_func(void*, void*)) {
	struct Node *root = NULL;
	bool ok = true;
	void *new_item = NULL;
	while (ok) {
		ok = read_item_func(new_item, allocate_item_func);
		if (ok)
			insert_into_tree(root, new_item, cmp_func);
	}
	return root;
}

//-----------------------------------------------------------------------------

void insert_into_tree(Node *&root, void *new_item,
		bool cmp_func(void*, void*)) {

	struct Node *new_node = new (nothrow) Node;
	check_alloc(new_node);

	new_node->_data = new_item;
	new_node->_left = new_node->_right = NULL;
	insert_node(root, new_node, new_item, cmp_func);
}

//-----------------------------------------------------------------------------

void insert_node(Node *&root, Node *new_node, void* new_item,
		bool cmp_func(void*, void*)) {

	if (root == NULL)
		root = new_node;

	else if (cmp_func(root->_data, new_node->_data))
		insert_node(root->_left, new_node, new_item, cmp_func);
	else
		insert_node(root->_right, new_node, new_item, cmp_func);
}
void free_bst(Node *root,void delete_func(void *)){// the function get the root of the tree

	if(root!=NULL){
		free_bst(root->_left,delete_func);
		delete_func(root->_data);
		free_bst(root->_right,delete_func);
		delete root;
	}

}



