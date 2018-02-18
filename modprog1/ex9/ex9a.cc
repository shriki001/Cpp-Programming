/*ex9a: a program that fill and check sudoku board
 * ============================================================================
 * written by Michael Shriki, id:305599417 login:michaelshr
 *
 * the program ask the user to fill any numbers to sudoku board and according
 * to that fill the next number correctly until the board full
 *
 * Input: 2nd array 4*4 size
 * ============================================================================
 * Output: the program print the correct sudoku board
 * ============================================================================
 */

#include<iostream>
#include<cstdlib>

using std::cin;
using std::cout;
using std::endl;

// ------------ constant area -------------------------------------------------

const int N = 2;
const int START = 0;

// ---------------- Prototype area --------------------------------------------

// function that read values from the user to 2nd array in a range of 1 to 4
void read(int arr[][N * N]);
// function that check if all the values in all the rows are individuals
bool row_ok(int arr[]);
// function that check if all the values in all the columns are individuals
bool col_ok(int arr[N * N][N * N], int num);
// function that check if the square of 2 index have a individuals values
bool square_ok(int arr[N * N][N * N], int x, int y);
// function that fill the rest of the values correctly with sudoku rules
bool sudoku(int arr[][N * N], int rows, int cols);
// function that print the fully board
void print(int arr[][N*N]);

//------------------- the main code -------------------------------------------

int main()
{
	int arr[N * N][N * N] = { START };

	read(arr);
	sudoku(arr, START, START);
	print(arr);

	return EXIT_SUCCESS;
}

// function that read values from the user to 2nd array in a range of 1 to 4 --

void read(int arr[][N * N])
{
	int row, col, value;
	cin >> row;
	while (row != -1) {
		cin >> col >> value;
		arr[row][col] = value;
		cin >> row;
	}
}

// -- function that fill the rest of the values correctly with sudoku rules ---

bool sudoku(int arr[][N * N], int rows, int cols)
{
	if (rows == N * N)
		return true;

	if (cols == N * N)
		return sudoku(arr, rows + 1, START);

	if (arr[rows][cols] != START)
		return sudoku(arr, rows, cols + 1);

	for (int value = 1; value <= N * N; value++) {
		arr[rows][cols] = value;
		if (row_ok(arr[rows]) && col_ok(arr, cols)
				&& square_ok(arr, rows, cols))
			if (sudoku(arr, rows, cols + 1))
				return true;

		arr[rows][cols] = START;
	}

	return false;
}

// -- function that check if all the values in all the rows are individuals ---

bool row_ok(int arr[])
{
	for (int i = START; i < N * N; i++)
		for (int j = START; j < N * N; j++) {
			if (arr[i] == START)
				continue;
			if (i != j && arr[i] == arr[j])
				return false;
		}

	return true;
}

//-- function that check if all the values in all the columns are individuals--

bool col_ok(int arr[N * N][N * N], int num) {
	for (int i = START; i < N * N; i++)
		for (int j = START; j < N * N; j++) {
			if (arr[i][num] == START)
				continue;
			if (i != j && arr[i][num] == arr[j][num])
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
			for (int s = num1; s < N + num1; s++)
				for (int t = num2; t < N + num2; t++) {
					if ((i == s && j == t) || arr[i][j] == START)
						continue;
					if (arr[i][j] == arr[s][t])
						return false;
				}
	return true;
}

// ---------- function that print the fully board -----------------------------

void print(int arr[][N*N])
{
	for (int i = START; i < N * N; i++) {
		for (int j = START; j < N * N; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}
