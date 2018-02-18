/*ex6c: a program that get a 9*9 board from the user and check
 * if this is a sudoku
 * ============================================================================
 * written by Michael Shriki, login:michaelshr
 *
 * the program get 9*9 board from the user and check if the
 * board is a sudoku board
 *
 * Input: 2nd array 9*9 size
 * ============================================================================
 * Output: the program print 1 if the board is sudoku and 0 if not
 * ============================================================================
 */

#include<iostream>
#include<cstdlib>

using std::cout;
using std::endl;
using std::cin;

// ------------ constant area -------------------------------------------------

const int N = 3;

// ---------------- Prototype area --------------------------------------------

// function that put values to 2nd array in a range of 0 to 9
void read(int arr[N * N][N * N]);
// function that check if all the values in all the rows are individuals
bool row_ok(int arr[]);
// function that check if all the values in all the columns are individuals
bool col_ok(int arr[N * N][N * N], int num);
// function that check if the square of 2 index have a individuals values
bool square_ok(int arr[N * N][N * N], int x, int y);

//-----------------------------------------------------------------------------

// ------------ function that put values to 2nd array -------------------------

void read(int arr[N * N][N * N])
{
	int num;
	for (int rows = 0; rows < N * N; rows++) {
		for (int cols = 0; cols < N * N;) {
			cin >> num;
			if (num >= 0 && num <= N * N) {
				arr[rows][cols] = num;
				cols++;
			}
		}
	}
}

//--- function that check if all the values in all the rows are individuals ---

bool row_ok(int arr[])
{
	for (int i = 0; i < N * N; i++)
		for (int j = i + 1; j < N * N - 1; j++) {
			if (arr[i] == 0)
				continue;
			if (arr[i] == arr[j])
				return false;
		}

	return true;
}

//-- function that check if all the values in all the columns are individuals--

bool col_ok(int arr[N * N][N * N], int num)
{
	for (int i = 0; i < N * N; i++)
		for (int j = i + 1; j < N * N - 1; j++) {
			if (arr[i] == 0)
				continue;
			if (arr[i][num] == arr[j][num])
				return false;
		}

	return true;
}

//--- function that check if the square of 2 index have a individuals values --

bool square_ok(int arr[N * N][N * N], int x, int y)
{
	int num1 = (x / N) * N; // Kick index x to his corner in the sudoku board
	int num2 = (y / N) * N; // Kick index y to his corner in the sudoku board
	for (int i = num1; i < N + num1; i++)
		for (int j = num2; j < N + num2; j++)
			for (int s = num1 + 1; i < N + num1; i++)
				for (int t = num2 + 1; j < N + num2; j++)
					if (arr[i][j] == arr[s][t])
						return false;
	return true;
}

//------------------- the main code -------------------------------------------

int main()
{
	int arr[N * N][N * N];

	bool check_rows;
	bool check_cols;
	bool check_square=true;

	read(arr);  //call to function that put values to the array

	// check if in all the rows the values are individual
	for (int i = 0; i < N * N; i++) {
		check_rows = row_ok(arr[i]);
		if (!check_rows)
			break;
	}
	// check if in all the columns the values are individual
	for (int i = 0; i < N * N; i++) {
		check_cols = col_ok(arr, i);
		if (!check_cols)
			break;
	}
	// check if in an square the values are individual
	for (int i = 0; i < N * N && check_square; i += N) {
		for (int j = 0; j < N * N && check_square; j += N) {
			check_square = square_ok(arr, i, j);
		}
	}

	if (check_rows && check_cols && check_square)
		cout << "1" << endl;
	else
		cout << "0" << endl;

	return EXIT_SUCCESS;
}
