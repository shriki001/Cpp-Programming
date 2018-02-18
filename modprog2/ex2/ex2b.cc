/*ex2b: a program that point to the next even/odd node in the linked list
 * ============================================================================
 * written by Michael Shriki, login:michaelshr
 *
 * the program point to the next even/odd node in the linked list
 *
 * Input: number for liked list
 * ============================================================================
 * Output: the program print the node value and the next even/odd of him
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
	struct Node *_next, *_next_oe;
};

// --------------- Prototype area ---------------------------------------------

struct Node *build_list(); // function that build the list
void set_next_oe(Node *head);  // function that set the next node of the list
// function that find the next node of the list
struct Node *find_next_oe(Node *head, bool is_even);
void print_list(const struct Node *head); // function that print the list
void free_list(struct Node *head); // function that free the allocated memory

// ------------- The Main code ------------------------------------------------

int main() {

	struct Node *head = NULL;

	head = build_list(); // build the list
	set_next_oe(head); // set the next even or odd node
	print_list(head); // print the list
	free_list(head); // free the list memory

	return EXIT_SUCCESS;
}

// ----------------------------------------------------------------------------

struct Node *build_list() { // the function return the head of the builded list

	struct Node *head = NULL;

	int num;
	cin >> num;
	while (!cin.eof()) {
		struct Node *temp = new (std::nothrow) struct Node;
		if (temp == NULL) {
			cerr << "Cannot allocate memory\n";
			exit(EXIT_FAILURE);
		}
		temp->_data = num;
		temp->_next = head;
		head = temp;

		cin >> num;
	}

	return head;
}

// --------- function that set the next node of the list ----------------------

void set_next_oe(Node *head) { // the function get the head of the list

	if (head == NULL)
		return;

	while (head != NULL) {
		if (head->_data % 2 == 0)
			head->_next_oe = find_next_oe(head->_next, true);
		else
			head->_next_oe = find_next_oe(head->_next, false);

		head = head->_next;
	}
}

// ------ function that find the next node of the list ------------------------

// the function get the head of the list and a boolean operator
// the function return the head of the list
struct Node *find_next_oe(Node *head, bool is_even) {

	if (is_even) {
		while (head != NULL && head->_data % 2 != 0)
			head = head->_next;
	} else
		while (head != NULL && head->_data % 2 == 0)
			head = head->_next;
	return head;
}

// ------- function that print the list ---------------------------------------

void print_list(const Node *head) { // the function get the head of the list

	while (head != NULL) {
		cout << head->_data << " ";
		if (head->_next_oe != NULL)
			cout << head->_next_oe->_data << " ";
		else
			cout << "- ";

		head = head->_next;
	}
	cout << endl;
}

// ------ function that free the allocated memory -----------------------------

void free_list(Node *head) { // the function get the head of the list

	struct Node* temp;
	while (head != NULL) {
		temp = head;
		head = head->_next;
		delete temp;
	}
}

