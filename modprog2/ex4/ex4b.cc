/*ex4b: a program that find and  print the minimum value of the BST
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
#include <cmath>

// --------------- Using area -------------------------------------------------

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::nothrow;

// --------------- Struct area ------------------------------------------------

const int N = 5;

struct Point {
	double _x, _y;
};

struct Circle {
	struct Point _center;
	double _r;
};

struct Rectangle {
	struct Point _top_left, _bot_right;
};

struct Node {
	void *_data;
	struct Node *_left, *_right;
};

struct Gen_arr {
	void *arr[N];
	int used;
};

//----------------------- Prototypes ------------------------------------------

struct Node *build_sorted_tree(
		bool (*read_item_func)(void *&, void *allocate_item_func()),
		void *allocate_item_func(), bool cmp_func(void*, void*));
void insert_into_tree(Node *&root, void *new_item, bool cmp_func(void*, void*));
void insert_node(Node *&root, Node *new_node, void* new_item,
		bool cmp_func(void*, void*));

void *allocate_circle();
void *allocate_rect();

bool read_circle(void *&p, void *allocate_item_func());
bool read_rect(void *&p, void *allocate_item_func());
bool compare_circle_x(void *p1, void *p2);
bool compare_rect_x(void *p1, void *p2);

double area_circle(void *p);
double area_rect(void *p);

void over_tree(Node *root, double (*get_area)(void *), double &max,
		Gen_arr *&shape);

void print_shape(Gen_arr *shape, void (*print)(void *));
void print_rect(void* arr);
void print_circle(void *arr);

void check_alloc(void *arr);
void free_bst(Node *root,void delete_func(void *));
void delete_circle(void *p);
void delete_rect(void *p);

// ------------- The Main code ------------------------------------------------

int main() {

	struct Node *circle_root = NULL, *rectangle_root = NULL;

	circle_root = build_sorted_tree(read_circle, allocate_circle,
			compare_circle_x);
	rectangle_root = build_sorted_tree(read_rect, allocate_rect,
			compare_rect_x);

	struct Gen_arr *circle_area = new (nothrow) Gen_arr;
	check_alloc(circle_area);
	struct Gen_arr *rectangle_area = new (nothrow) Gen_arr;
	check_alloc(rectangle_area);

	rectangle_area->used = 0;
	circle_area->used = 0;
	double max1 = -1, max2 = -1;
	over_tree(rectangle_root, area_rect, max1, rectangle_area);
	over_tree(circle_root, area_circle, max2, circle_area);

	print_shape(circle_area, print_circle);
	cout << endl;
	print_shape(rectangle_area, print_rect);
	cout << endl;

	free_bst(circle_root, delete_circle);
	free_bst(rectangle_root, delete_rect);
	delete circle_area;
	delete rectangle_area;

	return EXIT_SUCCESS;

}

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

//-----------------------------------------------------------------------------

void *allocate_circle() {

	struct Circle *circle = new (nothrow) struct Circle;
	check_alloc(circle);
	return circle;
}

//-----------------------------------------------------------------------------

void *allocate_rect() {

	struct Rectangle *rect = new (nothrow) struct Rectangle;
	check_alloc(rect);
	return rect;
}

//-----------------------------------------------------------------------------

bool read_circle(void *&p, void *allocate_item_func()) {

	double n1, n2;
	cin >> n1 >> n2;

	if (n1 == 0 && n2 == 0)
		return false;

	p = allocate_item_func();
	(*(struct Circle *) p)._center._x = n1;
	(*(struct Circle *) p)._center._y = n2;
	cin >> (*(struct Circle *) p)._r;
	return true;
}

bool read_rect(void *&p, void *allocate_item_func()) {

	double n1, n2, n3, n4;
	cin >> n1 >> n2 >> n3 >> n4;

	if (n1 == 0 && n2 == 0 && n3 == 0 && n4 == 0)
		return false;

	p = allocate_item_func();
	(*(struct Rectangle *) p)._top_left._x = n1;
	(*(struct Rectangle *) p)._top_left._y = n2;
	(*(struct Rectangle *) p)._bot_right._x = n3;
	(*(struct Rectangle *) p)._bot_right._y = n4;
	return true;
}

//------------------------------------------------

bool compare_circle_x(void *p1, void *p2) {

	return (*(struct Circle *) p1)._center._x
			>= (*(struct Circle *) p2)._center._x;
}

bool compare_rect_x(void *p1, void *p2) {

	return (*(struct Rectangle *) p1)._top_left._x
			>= (*(struct Rectangle *) p2)._top_left._x;
}

double area_rect(void *p) {

	double length = (*(Rectangle *) p)._top_left._x
			- (*(Rectangle *) p)._bot_right._x;
	double width = (*(Rectangle *) p)._bot_right._y
			- (*(Rectangle *) p)._top_left._y;
	return length * width;
}

double area_circle(void *p) {

	double radius_power = ((*(Circle *) p)._r * (*(Circle *) p)._r);
	return M_PI * radius_power;
}

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

void print_shape(Gen_arr *shape, void (*print)(void *)) {
	for (int i = 0; i < shape->used; i++) {
		print(shape->arr[i]);
	}
}

void print_rect(void* arr) {

	cout << (*(struct Rectangle *) arr)._top_left._x << " "
			<< (*(struct Rectangle *) arr)._top_left._y << " "
			<< (*(struct Rectangle *) arr)._bot_right._x << " "
			<< (*(struct Rectangle *) arr)._bot_right._y << " ";
}

void print_circle(void *arr) {

	cout << (*(struct Circle *) arr)._center._x << " "
			<< (*(struct Circle *) arr)._center._y << " "
			<< (*(struct Circle *) arr)._r << " ";
}

//-----------------------------------------------------------------------------

void check_alloc(void *arr) {

	if (arr == NULL) {
		cerr << "Cannot allocated memory \n";
		exit(EXIT_FAILURE);
	}
}

void delete_rect(void *p){

	delete (struct Rectangle *)p;
}

void delete_circle(void *p){

	delete (struct Circle *)p;
}

void free_bst(Node *root,void delete_func(void *)){// the function get the root of the tree

	if(root!=NULL){
		free_bst(root->_left,delete_func);
		delete_func(root->_data);
		free_bst(root->_right,delete_func);
		delete root;
	}

}
