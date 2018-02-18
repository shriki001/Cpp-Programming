/*ex2c: a program that build data base
 * ============================================================================
 * written by Michael Shriki, id:305599417 login:michaelshr
 *
 * the program build data base according to the following definition:
 * Node2 - get only prime numbers
 * Node - is the next node of Node2 the get the numbers the divided
 * by the Node2 prime
 *
 * Input: number for liked list
 * ============================================================================
 * Output: the program print data base according to the definition
 * ============================================================================
 */

#include <iostream>
#include <cmath>
#include <cstdlib>

// --------------- Using area -------------------------------------------------

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::nothrow;

// --------------- Struct area ------------------------------------------------

struct Node2 {
	int _data;
	struct Node * _left;
	struct Node2 * _down;
};

struct Node {
	int _data;
	struct Node * _next;
};

// --------------- Prototype area ---------------------------------------------

bool is_prime(int num); // the function check if the number is a prime
int first_prime(int num); // the function return the first prime of the number
// the function insert new prime node to the list
void insert2(int num, struct Node2 **p_2_head);
// the function insert new node to the list
void insert(int num, struct Node *&head);
void create(Node2 *&head); // function that build the list
void print_list(Node2 *head); // function that print the list
void free_list(Node2* head); // function that free the allocated memory
void free_next_node(Node *head); // function that free the next node

// ------------- The Main code ------------------------------------------------

int main() {

	struct Node2 *head = NULL;
	create(head); // build the list
	print_list(head); // print the list
	free_list(head); // free the list memory

	return EXIT_SUCCESS;
}

//------------- function that build the list ----------------------------------

void create(Node2 *&head) { // the function get the head of the list

	int num;
	Node2 *head_tmp;
	cin >> num;
	head_tmp = head;
	while (!cin.eof()) {
		int p = first_prime(num);
		while (head_tmp != NULL && p > head_tmp->_data)
			head_tmp = head_tmp->_down;

		if (head_tmp != NULL && p == head_tmp->_data) {
			insert(num, head_tmp->_left);
			head_tmp = head;
		} else {
			insert2(num, &head);
			head_tmp = head;
		}
		cin >> num;
	}
}

//-------- the function insert new node to the list ---------------------------

// the function get the head of the list and the number to put to the list

void insert(int num, struct Node *&head) {

	struct Node *temp = new (nothrow) struct Node;
	if (temp == NULL) {
		cerr << "Cannot allocate memory\n";
		exit(EXIT_FAILURE);
	}
	temp->_data = num;
	temp->_next = head;
	head = temp;
}

//--------- the function insert new node to the list --------------------------

// the function get pointer to the head of the list
// and the number to put to the list

void insert2(int num, struct Node2 **p_2_head) {

	struct Node2 *temp;

	if (*p_2_head == NULL) {
		*p_2_head = new (nothrow) struct Node2;

		if (*p_2_head == NULL) {
			cerr << "Cannot allocate memory\n";
			exit(EXIT_FAILURE);
		}
		(*p_2_head)->_data = first_prime(num);
		struct Node *temp_node = new (nothrow) struct Node;
		if (temp_node == NULL) {
			cerr << "Cannot allocate memory\n";
			exit(EXIT_FAILURE);
		}
		temp_node->_data = num;
		(*p_2_head)->_left = temp_node;
		temp_node->_next = NULL;
		(*p_2_head)->_down = NULL;
		return;
	}

	while ((*p_2_head) != NULL && (*p_2_head)->_data < first_prime(num))
		p_2_head = &((*p_2_head)->_down);

	temp = new (nothrow) struct Node2;

	if (temp == NULL) {
		cerr << "Cannot allocate memory\n";
		exit(EXIT_FAILURE);
	}

	struct Node *temp_node = new (nothrow) struct Node;

	if (temp_node == NULL) {
		cerr << "Cannot allocate memory\n";
		exit(EXIT_FAILURE);
	}

	temp->_data = first_prime(num);
	temp_node->_data = num;
	temp_node->_next = NULL;

	temp->_left = temp_node;
	temp->_down = (*p_2_head);
	(*p_2_head) = temp;
}

//--------- the function check if the number is a prime -----------------------

bool is_prime(int num) { // the function get number and return if it's a prime

	bool p = true;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			p = false;
			break;
		}
	}
	return p;
}

//------ the function return the first prime of the number --------------------

// the function get number and return the first prime that divide the number

int first_prime(int num) {

	for (int i = 2; i <= num / 2; i++)
		if (num % i == 0 && is_prime(i))
			return i;
	return num;
}

//---------------- function that print the list -------------------------------

void print_list(Node2 *head) { // the function get the head of the list

	if (head == NULL)
		return;

	struct Node2 *idex = head;
	while (idex != NULL) {
		struct Node *jdex = idex->_left;
		cout << idex->_data << " ";
		while (jdex != NULL) {
			cout << jdex->_data << " ";
			jdex = jdex->_next;
		}
		idex = idex->_down;
		cout << endl;
	}
}

//--------- function that free the allocated memory ---------------------------

void free_list(Node2* head) { // the function get the head of the list

	Node2 *temp;

	while (head != NULL) {
		free_next_node(head->_left);
		temp = head;
		head = head->_down;
		delete temp;
	}
}

//--------- function that free the next node ----------------------------------

void free_next_node(Node *head) { // the function get the head of the list

	struct Node *temp = head;

	while (head != NULL) {
		temp = head;
		head = head->_next;
		delete temp;
	}
}
