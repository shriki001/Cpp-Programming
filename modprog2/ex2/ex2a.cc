/*ex2a: a program that remove even node from linked list
 * ============================================================================
 * written by Michael Shriki, id:305599417 login:michaelshr
 *
 * the program remove even node from linked list
 *
 * Input: number for liked list
 * ============================================================================
 * Output: the program print the list without the even numbers
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
	struct Node *_next;
};

// --------------- Prototype area ---------------------------------------------

struct Node *build_list(); // function that build the list
void print_list(const Node *head); // function that print the list
// function that remove the even number from the list
void remove_even(Node *&head);
void free_list(Node *head); // function that free the allocated memory

// ------------- The Main code ------------------------------------------------

int main() {

	struct Node *head = NULL;

	head = build_list(); // build the list

	print_list(head); // print the list
	remove_even(head); // remove even value from the list
	print_list(head); // print the list again
	free_list(head); // free the list memory

	return EXIT_SUCCESS;
}

// ------- function that build the list ---------------------------------------

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

// ---------- function that remove the even number from the list --------------

void remove_even(Node *&head) { // the function get the head of the list

	while (head != NULL && head->_data % 2 == 0) {
		if (head->_data % 2 == 0) {
			struct Node *temp = head;
			head = head->_next;
			delete temp;
		}
	}

	if (head == NULL)
		return;

	struct Node *rear = head;
	struct Node *front = head->_next;

	while (front != NULL) {
		while (front != NULL && front->_data % 2 == 0) {

			struct Node *temp = front;
			front = front->_next;
			delete temp;
			rear->_next = front;
		}
		if (front == NULL)
			return;

		rear = front;
		front = front->_next;
	}
}

// -------------- function that print the list --------------------------------

void print_list(const Node *head) { // the function get the head of the list

	int sum = 0;
	while (head != NULL) {
		sum += head->_data;
		head = head->_next;
	}
	cout << sum << endl;
}

// ----- function that free the allocated memory ------------------------------

void free_list(Node *head) { // the function get the head of the list

	struct Node* temp;
	while (head != NULL) {
		temp = head;
		head = head->_next;
		delete temp;
	}
}
