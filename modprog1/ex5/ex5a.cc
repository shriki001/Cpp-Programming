/*ex5a: a program that found the max sum value rows and cols in an array
 * ============================================================================
 * written by Michael Shriki, id:305599417 login:michaelshr
 *
 * the program found the sum of max rows and max cols int an array and print
 * the location of the max rows and the max cols
 *
 * Input: 2nd array
 * ============================================================================
 * Output: the program print max rows and max cols of the array
 * ============================================================================
 */

#include<iostream>
#include<cstdlib>
#include<climits>

using std::cout;
using std::endl;
using std::cin;

// ------------ constant area -------------------------------------------------

const int ROWS = 4, COLS = 5;

// -------------- the main code -----------------------------------------------

int main()
{
	int a[ROWS][COLS]; // array
	int sum_rows = 0; // the sum of rows
	int sum_cols = 0; // the sum of columns
	int max_rows = INT_MIN; // max sum of rows is the min value of c++ know
	int max_cols = INT_MIN; // max sum of columns is the min value of c++ know
	int temp, location = 0; // max of the little array, location of the max
	int brr[ROWS], crr[COLS]; //array for max rows, array for max columns

	// reading values to the array
	for (int row = 0; row < ROWS; row++)
		for (int col = 0; col < COLS; col++)
			cin >> a[row][col];

//getting the sum of all row one by one and put the result in max rows array
	for (int row = 0; row < ROWS; row++) {
		sum_rows = 0;
		for (int col = 0; col < COLS; col++)
			sum_rows += a[row][col];
		brr[row] = sum_rows;
		if (sum_rows > max_rows)
			max_rows = sum_rows;
	}

	temp = brr[0]; // the first max
	// found the max in max rows array and get the location
	for (int i = 1; i < ROWS; i++) {
		if (brr[i] > temp) {
			temp = brr[i];
			location = i;
		}
	}
	cout << location << " "; // print the location of the max sum of rows

	location = 0; // reset the location

//getting the sum of all col one by one and put the result in max columns array
	for (int col = 0; col < COLS; col++) {
		sum_cols = 0;
		for (int row = 0; row < ROWS; row++)
			sum_cols += a[row][col];
		crr[col] = sum_cols;
		if (sum_cols > max_cols)
			max_cols = sum_cols;
	}

	temp = crr[0]; // the first max
	// found the max in max columns array and get the location
	for (int i = 1; i < COLS; i++) {
		if (crr[i] > temp) {
			temp = crr[i];
			location = i;
		}
	}

	 cout << location << endl; // print the location of the max sum of columns

	return EXIT_SUCCESS;
}
