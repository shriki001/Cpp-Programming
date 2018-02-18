/*ex5b: part one: a program that found the row that contain all of the rows
 * 		part two: a program that found the row that contain all of the rows
 * 		by the definition
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

// -------------- the main code -----------------------------------------------

int main()
{
	int a[ROWS][COLS]; // array
	bool is_contains_all_rows = true; // if row contain all rows
	bool is_contains_row = true; // if row contain another row
	bool is_contains_num = false; // if row contain value
	int first_row_contain_all_rows = -1; // found if the row contain all rows

	// reading values to the array
	for (int row = 0; row < ROWS; row++)
		for (int col = 0; col < COLS; col++)
			cin >> a[row][col];

//----------------------- part 1 ----------------------------------------------

	// found the row that contain all the rows
	for (int row = 0; row < ROWS; row++) {
		is_contains_all_rows = true;
		for (int i = 0; i < ROWS; i++) {
			is_contains_row = true;
			for (int col = 0; col < COLS; col++) {
				int curr_num = a[i][col];
				is_contains_num = false;
				for (int j = 0; j < COLS; j++) {
					if (a[row][j] == curr_num) {
						is_contains_num = true;
						break;
					}
				}
				if (!is_contains_num) {
					is_contains_row = false;
					break;
				}
			}
			if (!is_contains_row) {
				is_contains_all_rows = false;
				break;
			}
		}
		if (is_contains_all_rows) {
			first_row_contain_all_rows = row;
			break;
		}
	}

	// print the row if their is one
	cout << first_row_contain_all_rows << endl;

//----------------------- part 2 ----------------------------------------------

	first_row_contain_all_rows = -1; // reset if the row contain all rows to -1

	// found the row that contain all the rows by elements
	for (int row = 0; row < ROWS; row++) {
		is_contains_all_rows = true;
		for (int i = 0; i < ROWS; i++) {
			is_contains_row = true;
			for (int col = 0; col < COLS; col++) {
				int curr_num = a[i][col];
				if (curr_num == 0)
					continue;

				int num_of_occur = 0;
				int num_of_tested_row_occur = 0;
				for (int j = 0; j < COLS; j++) {
					if (a[i][j] == curr_num) {
						num_of_occur++;
					}
					if (a[row][j] == curr_num) {
						num_of_tested_row_occur++;
					}
				}
				if (num_of_occur > num_of_tested_row_occur) {
					is_contains_row = false;
					break;
				}
			}
			if (!is_contains_row) {
				is_contains_all_rows = false;
				break;
			}
		}
		if (is_contains_all_rows) {
			first_row_contain_all_rows = row;
			break;
		}
	}

	// found the row that contain all the rows
	cout << first_row_contain_all_rows << endl;

	return EXIT_SUCCESS;
}
