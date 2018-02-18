/*ex3b: a program that find the shallow leaf in BST
 * ============================================================================
 * written by Michael Shriki, id:305599417 login:michaelshr
 *
 * the program find the shallow leaf in BST
 *
 * Input: number for BST
 * ============================================================================
 * Output: the program print the most shallow leaf in the BST
 * ============================================================================
 */

#include <iostream>
#include <climits>
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
// function that find the minimum depth leaf
const Node *min_depth_leaf(const Node *root);
// function that find the shallow leaf
void find_shallow(const Node *root, const Node *temp_root,const  Node *&min_node, int &min);
// function that find the length from root to leaf
int pathlength(const Node* root, int num);
void free_bst(Node *root); // function that free the allocated memory

// ------------- The Main code ------------------------------------------------

int main() {

	struct Node *root = NULL;

	build_tree(root); // build the list

	const struct Node *min_node = min_depth_leaf(root);
	cout << min_node->_data;

	free_bst(root); // free the list memory

	return EXIT_SUCCESS;
}

// ------- function that build the BST ---------------------------------------

void build_tree(Node *&root) { // get the root of BST

	int num;
	cin >> num;
	while (!cin.eof()) {
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

// ---------- the function insert new leaf to the BST -------------------------

void insret_into_bst(Node *new_node,
		Node *&root) {// get the new node and the BST root

	if (root == NULL)
		root = new_node;

	else if (root->_data >= new_node->_data)
		insret_into_bst(new_node, root->_left);
	else
		insret_into_bst(new_node, root->_right);

}

// ------------ function that find the minimum depth leaf ---------------------

const Node *min_depth_leaf(const Node *root) {// get the root of BST

	if (root == NULL)
		exit(EXIT_FAILURE);

	int min = INT_MAX;
	const Node *min_node = NULL, *temp_root = root;
	find_shallow(root, temp_root, min_node, min);

	return min_node;

}

// -------------- function that find the shallow leaf -------------------------

void find_shallow(const Node *root, // get the root of BST ,
		const Node *temp_root, // copy of the root ,
		const Node *&min_node, // pointer for the needed leaf ,
		int &min) { // minimum value

	if (root == NULL)
		return;

	if (root->_left == NULL && root->_right == NULL) {

		int path_from_root = pathlength(temp_root, root->_data);
		if (path_from_root < min) {
			min = path_from_root;
			min_node = root;
		}
	}

	find_shallow(root->_left, temp_root, min_node, min);
	find_shallow(root->_right, temp_root, min_node, min);
}

// --------------- function that find the length from root to leaf ------------

int pathlength(const Node* root, int num) { // get the root of BST and data of a leaf

	if (root != NULL) {
		int depth = 0;

		if ((root->_data == num) ||
				(depth = pathlength(root->_left, num)) > 0 ||
				(depth = pathlength(root->_right, num)) > 0)
			return depth + 1;

		return 0;
	}
	return 0;
}

// ------------------- function that free the allocated memory ----------------

void free_bst(Node *root) {// get the root of BST

	if (root != NULL) {
		free_bst(root->_left);
		free_bst(root->_right);
		delete root;
	}

}
