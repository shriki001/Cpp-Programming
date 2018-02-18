/*ex3c: a program that build BST and visit the BST in inorder method
 * and build linked list from the current leaf of the BST
 * ============================================================================
 * written by Michael Shriki, id:305599417 login:michaelshr
 *
 * the program build BST and visit the BST in inorder method
 * and build linked list from the current leaf of the BST
 *
 * Input: number for BST
 * ============================================================================
 * Output: the program print the linked list
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

struct Tree_node {
	int _data;
	struct Tree_node * _left, *_right;
};

struct List_node {
	int _data;
	struct List_node * _next;
};

// --------------- Prototype area ---------------------------------------------

void build_tree(Tree_node *&root); // function that build the BST
// function the insert new node to the linked list
void insert_into_linkedlist(List_node* &head, int num);
// the function insert new leaf to the BST
void insret_into_bst(Tree_node *new_node, Tree_node *&root);
// function that build the list
void build_list(const Tree_node *root, List_node *&head);
// the function the print the list
void print_list(const List_node *head);
// function that free the allocated memory of the BST
void free_bst(Tree_node *root);
// function that free the allocated memory of the list
void free_list(List_node *head);

// ------------- The Main code ------------------------------------------------

int main() {

	struct Tree_node *root = NULL;
	struct List_node *head = NULL;

	build_tree(root); // build the BST
	build_list(root, head); // build the list
	print_list(head); // print the linked list
	free_bst(root); // free the BST memory
	free_list(head); // free the linked list memory

	return EXIT_SUCCESS;
}

// ------- function that build the BST ---------------------------------------

void build_tree(Tree_node *&root) { // get the root of BST

	int num;
	cin >> num;
	while (!cin.eof()) {

		struct Tree_node *new_node = new (std::nothrow) struct Tree_node;
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

//----------- the function insert new leaf to the BST -------------------------

void insret_into_bst(Tree_node *new_node, // get the new node and the BST root
		Tree_node *&root) {

	if (root == NULL)
		root = new_node;

	else if (root->_data >= new_node->_data)
		insret_into_bst(new_node, root->_left);
	else
		insret_into_bst(new_node, root->_right);

}

// ---------------- function that build the list ------------------------------

void build_list(const Tree_node *root,
		List_node *&head) { // get the BST root and the head of the list

	if (root == NULL)
		return;

	build_list(root->_right, head);
	insert_into_linkedlist(head, root->_data);
	build_list(root->_left, head);
}

// ----------- function the insert new node to the linked list ----------------

void insert_into_linkedlist(List_node* &head,
		int num) { //get the head of the list and the data for the node

	struct List_node *temp = new (std::nothrow) struct List_node;
	if (temp == NULL) {
		cerr << "Cannot allocate memory\n";
		exit(EXIT_FAILURE);
	}

	temp->_data = num;
	temp->_next = head;
	head = temp;
}

//---------- the function the print the list ----------------------------------

void print_list(const List_node *head) { // get the head of the list

	while (head != NULL) {
		cout << head->_data << " ";
		head = head->_next;
	}
	cout<<endl;
}

// ----- function that free the allocated memory of the tree ------------------

void free_bst(Tree_node *root) { // the function get the root of the tree

	if (root != NULL) {
		free_bst(root->_left);
		free_bst(root->_right);
		delete root;
	}
}

// ----- function that free the allocated memory of the list ------------------

void free_list(List_node *head) { // the function get the head of the list

	struct List_node* temp;
	while (head != NULL) {
		temp = head;
		head = head->_next;
		delete temp;
	}
}

