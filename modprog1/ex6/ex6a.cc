/*ex6a: a program that found the max sum value rows and cols in an array
 * ============================================================================
 * written by Michael Shriki, id:305599417 login:michaelshr
 *
 * the program found the sum of max rows and max cols in an array and print
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

// ---------------- Prototype area --------------------------------------------

void read(int arr[ROWS][COLS]); // function that putting value to 2nd array
// function that return the max sum of all rows
int sum_of_rows(int arr[ROWS][COLS]);
int sum1(int arr[]); // function that return the sum of lonely row
// function that return the max sum of all columns
int sum_of_cols(int arr[ROWS][COLS]);
// function that return the sum of column
int sum2(int arr[ROWS][COLS],int num);

//-----------------------------------------------------------------------------

// ----- the function that reading value to the array -------------------------

void read(int arr[ROWS][COLS])
{
	for (int row = 0; row < ROWS; row++)
		for (int col = 0; col < COLS; col++)
			cin >> arr[row][col];
}

//-----------------------------------------------------------------------------

//----- function that return the max sum of all rows --------------------------

int sum_of_rows(int arr[ROWS][COLS])
{
	int location = 0; // location of the max
	int max = INT_MIN; // the max of the row

	for (int row = 0; row < ROWS; row++) {

		//calling to sum1 function
		if(sum1(arr[row]) > max){
			max = sum1(arr[row]);
			location = row;
		}
	}

	return location; // return the location of the max sum of rows
}

//-----------------------------------------------------------------------------

//--------- function that return the sum of lonely row ------------------------

int sum1(int arr[])
{
	int sum_rows = 0;
	for (int i = 0; i < COLS; i++)
		sum_rows += arr[i];
	return sum_rows;
}

//-----------------------------------------------------------------------------

//----- function that return the max sum of all columns -----------------------

int sum_of_cols(int arr[ROWS][COLS])
{
	int location = 0; // max of the little array, location of the max
	int max = INT_MIN; // array for max columns

	// send to function sum1 the number of the column
	// and the result put in max columns array

	for (int col = 0; col < COLS; col++){
		if(sum2(arr,col) > max){
			max = sum2(arr,col);
			location = col;
		}
	}

	return location; // return the location of the max sum of columns

}

//---------- function that return the sum of column ---------------------------

int sum2(int arr[ROWS][COLS],int num)
{
	int sum_cols = 0;
	for (int row = 0; row < ROWS; row++)
		sum_cols += arr[row][num];

	return sum_cols;
}

//-----------------------------------------------------------------------------

// -------------- the main code -----------------------------------------------

int main()
{
	int arr[ROWS][COLS]; // the array that every function can use

	read(arr); // calling the function that reading value to the array

	// calling to function that finding the max sum of the rows
	cout << sum_of_rows(arr) << " ";

	// calling to function that finding the max sum of the columns
	cout << sum_of_cols(arr) << endl;

	return EXIT_SUCCESS;
}

//-----------------------------------------------------------------------------
