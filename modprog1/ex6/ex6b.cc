/*ex6b: part one: a program that found the row that contain all of the rows
 *----- part two: a program that found the row that contain all of the rows
 *----- by the definition
 * ============================================================================
 * written by Michael Shriki, id:305599417 login:michaelshr
 *
 * part one: the program found the row that contain all of the rows
 * part two: the program found the row that contain all of the rows by the show
 * of the value in the other row
 *
 * Input: 2nd array
 * ============================================================================
 * Output: the program print the number of the rows that contain all the rows
 * ============================================================================
 */

#include<iostream>
#include<cstdlib>

using std::cout;
using std::endl;
using std::cin;

// ------------ constant area -------------------------------------------------

const int ROWS = 4, COLS = 5;

// ---------------- Prototype area --------------------------------------------

void read(int arr[ROWS][COLS]);// function that put values to 2nd array
// function that find the first row that contain all rows
int part1(int arr[ROWS][COLS]);
// function that check if row contain all rows
bool contain_all_rows(int arr[ROWS][COLS], int num);
// function that check if row contain another row
bool row_contain_another_row(int arr[ROWS][COLS], int a, int b);
// function that find the first row that contain all rows and ignore zeroes
int part2(int arr[ROWS][COLS]);
// function that check if row contain all rows
bool contain_all_rows2(int arr[ROWS][COLS], int num);
// function that check if row contain another row and ignore zeroes
bool row_contain_another_row2(int arr[ROWS][COLS], int a, int b);

//-----------------------------------------------------------------------------

// ------------ function that put values to 2nd array -------------------------

void read(int arr[ROWS][COLS])
{
	for (int row = 0; row < ROWS; row++)
		for (int col = 0; col < COLS; col++)
			cin >> arr[row][col];
}

//----------- function that find the first row that contain all rows ----------

int part1(int arr[ROWS][COLS])
{
	int first_row_contain_all_rows = -1; // found if the row contain all rows

	for (int row = 0; row < ROWS; row++) {
		if (contain_all_rows(arr, row)) { // calling to function that find the
												// row that contain all rows
			first_row_contain_all_rows = row;
			break;
		}
	}

	return first_row_contain_all_rows; //return the row number
									   // that contain all rows
}

//------- function that check if row contain all rows -------------------------

bool contain_all_rows(int arr[ROWS][COLS], int num) {

	bool is_contains_all_rows = true;

	for (int i = 0; i < ROWS; i++) {
		// calling to function that check if row contain another row
		if (!row_contain_another_row(arr, num, i)) {
			is_contains_all_rows = false;
			return is_contains_all_rows;// return false if their is row
										// that contain all rows
		}
	}
	return is_contains_all_rows; // return true if their is row
								// that contain all rows

}

//-------- function that check if row contain another row ---------------------

bool row_contain_another_row(int arr[ROWS][COLS], int a, int b)
{
	bool is_contains_num;
	bool is_contains_row = true;

	for (int col = 0; col < COLS; col++) {
		int curr_num = arr[b][col];
		is_contains_num = false;
		for (int j = 0; j < COLS; j++) {
			if (arr[a][j] == curr_num) {
				is_contains_num = true;
				break;
			}
		}
		if (!is_contains_num) {
			is_contains_row = false;
			return is_contains_row;
		}
	}
	return is_contains_row; // return if their is a row that contain another
}

//-----------------------------------------------------------------------------

// - function that find the first row that contain all rows and ignore zeroes -

int part2(int arr[ROWS][COLS])
{
	int first_row_contain_all_rows = -1; // found if the row contain all rows

	for (int row = 0; row < ROWS; row++) {
		if (contain_all_rows2(arr, row)) { // calling to function that find the
										   // row that contain all rows
			first_row_contain_all_rows = row;
			break;
		}
	}

	return first_row_contain_all_rows; // return the row number
									   // that contain all rows
}

//-------- function that check if row contain all rows ------------------------

bool contain_all_rows2(int arr[ROWS][COLS], int num)
{
	bool is_contains_all_rows = true;

	for (int i = 0; i < ROWS; i++) {
		// calling to function that check if row contain another row
		if (!row_contain_another_row2(arr, num, i)) {
			is_contains_all_rows = false;
			return is_contains_all_rows; // return false if their is row
										 // that contain all rows
		}
	}
	return is_contains_all_rows; // return true if their is row
								 // that contain all rows
}

//--- function that check if row contain another row and ignore zeroes --------

bool row_contain_another_row2(int arr[ROWS][COLS], int a, int b)
{
	bool is_contains_row = true;
	int num_of_occur = 0;
	int num_of_tested_row_occur = 0;

	for (int col = 0; col < COLS; col++) {
			int curr_num = arr[b][col];
			if (curr_num == 0)
				continue;
		for (int j = 0; j < COLS; j++) {
			for (int j = 0; j < COLS; j++) {
				if (arr[b][j] == curr_num)
					num_of_occur++;

				if (arr[a][j] == curr_num)
					num_of_tested_row_occur++;
			}
			if (num_of_occur > num_of_tested_row_occur) {
				is_contains_row = false;
				return is_contains_row;
			}
		}
	}
	return is_contains_row; // return if their is a row that contain another
}

// ----------------------------------------------------------------------------

// -------------- the main code -----------------------------------------------

int main()
{
	int arr[ROWS][COLS];
	read(arr);  //call to function that put values to the array
	cout << part1(arr) << endl; // print the result from the part 1 function
	cout << part2(arr) << endl; // print the result from the part 2 function

	return EXIT_SUCCESS;
}
