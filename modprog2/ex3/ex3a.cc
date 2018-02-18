/*ex3a: a program that find and  print the minimum value of the BST
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

// --------------- Using area -------------------------------------------------

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

// --------------- Struct area ------------------------------------------------

struct Node {
	int _data;
	struct Node *_left, *_right;
};

// --------------- Prototype area ---------------------------------------------

void build_tree(Node *&root); // function that build the BST
// the function insert new leaf to the BST
void insret_into_bst(Node *new_node, Node *&root);
// function that find the minimal node data of BST
int minimal_node_data(const Node *root);
void print_inorder(const Node *root); // function that print the BST
void free_bst(Node *root); // function that free the allocated memory

// ------------- The Main code ------------------------------------------------

int main() {

	struct Node *root = NULL;

	build_tree(root); // build the list

	int min = minimal_node_data(root);
	cout << min << endl;

	print_inorder(root); // print in inorder
	cout << endl;

	free_bst(root); // free the list memory

	return EXIT_SUCCESS;
}

// ------- function that build the BST ---------------------------------------

void build_tree(Node *&root) { // get the root of BST

	int num;
	cin >> num;
	while (num != 0) {
		struct Node *new_node = new (std::nothrow) struct Node;
		if (new_node == NULL) {
			cerr << "Cannot allocate memory\n";
			exit(EXIT_FAILURE);
		}
		new_node->_data = num;
		new_node->_left = new_node->_right = NULL;
		insret_into_bst(new_node, root);

		cin >> num;
	}
}

// ---------------- the function insert new leaf to the BST -------------------

void insret_into_bst(Node *new_node,
		Node *&root) {// get the new node and the BST root

	if (root == NULL)
		root = new_node;

	else if (root->_data >= new_node->_data)
		insret_into_bst(new_node, root->_left);
	else
		insret_into_bst(new_node, root->_right);

}

//--------- function that find the minimal node data of BST -------------------

int minimal_node_data(const Node *root) { // get the root of the BST

	if (root == NULL){
		cout<<endl;
		exit(EXIT_FAILURE);
	}

	int min = root->_data;
	while (root != NULL) {
		min = root->_data;
		root = root->_left;
	}
	return min;

}

// ------------- function that print the BST ----------------------------------

void print_inorder(const Node *root) { // get the root of the BST

	if (root == NULL)
		return;

	if (root->_left == NULL && root->_right == NULL)
		cout << root->_data << " ";

	print_inorder(root->_left);
	print_inorder(root->_right);
}

// ------------------- function that free the allocated memory ----------------

void free_bst(Node *root){// the function get the root of the tree

	if(root!=NULL){
		free_bst(root->_left);
		free_bst(root->_right);
		delete root;
	}

}
