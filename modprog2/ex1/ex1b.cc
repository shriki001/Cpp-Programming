/*ex1b: a program that get input form 2 files and merge them
 * ============================================================================
 * written by Michael Shriki, id:305599417 login:michaelshr
 *
 * the program get input form 2 files and merge the array
 *
 * Input: 2 files of numbers
 * ============================================================================
 * Output: the program print the sum of the values
 * ============================================================================
 */

#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<new>
#include<fstream>

// --------------- Using area ----------------------------------------------

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::setw;
using std::ifstream;

// --------------- Constant area ----------------------------------------------

const int SIZE = 20;

// --------------- Prototype area ---------------------------------------------

// function that create the program
void create(ifstream &inp, unsigned int **&arr, int &size);
// function that create the 2nd array
void create_array(unsigned int **&arr, int size);
// function that create the array
void create_array(unsigned int *&arr, int size);
// function that print the array
void print(unsigned int **&arr, unsigned int **&brr);
// function that free the allocated memory
void free_array(unsigned int **arr);
// function that print 2nd array
void print_a(unsigned int **&arr, int start);
// function that check the opening of files
void open_check(ifstream &inp1, ifstream &inp2);
// function that copy 2nd array to new one and delete the old
void copy_n_del(unsigned int **&arr, unsigned int **&temp, int &row,
		int &size_col, int &col);
// function that copy array to new one and delete the old
void copy_n_del(unsigned int **&arr, unsigned int *&temp_col, int &size_col,
		int &row, int &col, int num);

// ------------- The Main code ------------------------------------------------

int main() {

	char arr[SIZE];
	char brr[SIZE];
	int size1 = 1;
	int size2 = 1;

	ifstream inp1, inp2;

	cin >> setw(SIZE) >> arr;
	cin >> setw(SIZE) >> brr;

	unsigned int **mat1, **mat2;

	inp1.open(arr);
	inp2.open(brr);

	open_check(inp1, inp2);

	create(inp1, mat1, size1);
	create(inp2, mat2, size2);

	print(mat1, mat2);

	free_array(mat1);
	free_array(mat2);

	inp1.close();
	inp2.close();

	return EXIT_SUCCESS;
}

// ------- function that check the opening of files ---------------------------

void open_check(ifstream &inp1, ifstream &inp2) {

	if (!inp1.is_open() || !inp2.is_open()) {
		cerr << "Error opening file/s \n";
		exit(EXIT_FAILURE);
	}
}

// ------- function that create the 2nd array ---------------------------------

void create_array(unsigned int **&arr, int size) {

	arr = new (std::nothrow) unsigned int*[size + 1];
	if (arr == NULL) {
		cerr << "Cannot allocate memory \n";
		exit(EXIT_FAILURE);
	}
	arr[size] = NULL;
}

// ---- function that create the array ----------------------------------------

void create_array(unsigned int *&arr, int size) {

	arr = new (std::nothrow) unsigned int[size + 1];
	if (arr == NULL) {
		cerr << "Cannot allocate memory \n";
		exit(EXIT_FAILURE);
	}
}

// ------ function that create the program ------------------------------------

void create(ifstream &inp, unsigned int **&arr, int &size) {

	unsigned int **temp;
	unsigned int *temp_col;

	int value;
	int size_col = 1, row = 0, col = 0;

	create_array(arr, size);

	inp >> value;
	while (!inp.eof()) {

		create_array(arr[row], size_col);

		while (value != 0) {
			create_array(temp_col, size_col);
			copy_n_del(arr, temp_col, size_col, row, col, value);
			inp >> value;
		}

		arr[row][col] = 0;

		inp.ignore(256, '\n');

		size++;
		create_array(temp, size);
		copy_n_del(arr, temp, row, size_col, col);
		inp >> value;
	}
	arr[row] = NULL;

}

// ----------- function that copy 2nd array to new one and delete the old -----

void copy_n_del(unsigned int **&arr, unsigned int **&temp, int &row,
		int &size_col, int &col) {

	for (int i = 0; arr[i] != NULL; i++)
		temp[i] = arr[i];
	delete[] arr;
	arr = temp;
	row++;
	size_col = 1;
	col = 0;
}

// ---- function that copy array to new one and delete the old ----------------

void copy_n_del(unsigned int **&arr, unsigned int *&temp_col, int &size_col,
		int &row, int &col, int num) {
	for (int i = 0; i < size_col; i++)
		temp_col[i] = arr[row][i];
	delete[] arr[row];
	arr[row] = temp_col;
	arr[row][col] = num;
	size_col++;
	col++;
}

// -------- function that print the array --------------------------------------

void print(unsigned int **&arr, unsigned int **&brr) {

	int i = 0, j;
	for (i = 0; arr[i] != NULL && brr[i] != NULL; i++) {
		for (j = 0; arr[i][j] != 0 && brr[i][j] != 0; j++)
			cout << (arr[i][j] + brr[i][j]) << " ";

		if (arr[i][j] == 0) {
			for (; brr[i][j] != 0; j++)
				cout << brr[i][j] << " ";
			cout << endl;
			continue;
		}
		if (brr[i][j] == 0) {
			for (; arr[i][j] != 0; j++)
				cout << arr[i][j] << " ";
			cout << endl;
			continue;
		}
	}

	if (arr[i] == NULL && brr[i] == NULL)
		cout << endl;

	if (arr[i] == NULL)
		print_a(brr, i);
	else
		print_a(arr, i);
}

// ------- function that print the 2nd array ----------------------------------

void print_a(unsigned int **&arr, int start) {

	for (int i = start; arr[i] != NULL; i++) {
		for (int j = 0; arr[i][j] != 0; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

// ------ function that free the allocated memory -----------------------------

void free_array(unsigned int **arr) {

	for (int i = 0; arr[i] != NULL; i++)
		delete[] arr[i];
	delete[] arr;
}

