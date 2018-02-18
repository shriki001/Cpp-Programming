/*ex1a: a program that find the average
 * ============================================================================
 * written by Michael Shriki, login:michaelshr
 *
 * the program find the average from a dynamic array
 *
 * Input: array size
 * ============================================================================
 * Output: the program print the average of the array
 * ============================================================================
 */

#include<iostream>
#include<cstdlib>
#include<climits>

// --------------- Using area ----------------------------------------------

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

// --------------- Constant area ----------------------------------------------

const int END = INT_MIN;

// --------------- Prototype area ---------------------------------------------

void create_array(int **&arr, int size); // function that create the array
void read(int **&arr, int size_row); // function that read data
double average(int **&arr); // function that calculate the average
void free_array(int **arr); // function that free the allocate memory

// ------------- The Main code ------------------------------------------------

int main() {

	int **arr;
	int size_row;
	cin >> size_row;

	create_array(arr, size_row);

	read(arr, size_row);
	cout << average(arr) << endl;

	free_array(arr);

	return EXIT_SUCCESS;
}

// ---------- function that create the array ----------------------------------

void create_array(int **&arr, int size) {

	arr = new (std::nothrow) int*[size + 1];
	if (arr == NULL) {
		cerr << "Cannot allocate memory \n";
		exit(EXIT_FAILURE);
	}
	arr[size] = NULL;
}

// --------- function that read data ------------------------------------------

void read(int **&arr, int size_row) {

	int value, col_size;

	for (int i = 0; i < size_row; i++) {
		cin >> col_size;

		arr[i] = new (std::nothrow) int[col_size + 1];

		if (arr[i] == NULL) {
			cerr << "Cannot allocate memory \n ";
			exit(EXIT_FAILURE);
		}

		for (int j = 0; j < col_size; j++) {
			cin >> value;
			arr[i][j] = value;
		}

		arr[i][col_size] = END;
	}

	arr[size_row] = NULL;
}

// -------- function that calculate the average -------------------------------

double average(int **&arr) {

	double average;
	int num = 0, sum = 0;
	for (int i = 0; arr[i] != NULL; i++) {
		for (int j = 0; arr[i][j] != END; j++) {
			num++;
			sum += arr[i][j];
		}
	}
	average = (double) sum / num;
	return average;
}

// -------- function that free the allocate memory ----------------------------

void free_array(int **arr) {

	for (int i = 0; arr[i] != NULL; i++)
		delete[] arr[i];
	delete[] arr;
}
