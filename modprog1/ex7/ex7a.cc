/*ex7a: a program that have tow parts:
 * part 1: print copy of the first array with only alphabet and upper case
 * part 2: print the first array after we remove the value that common
 * with the second array
 * ============================================================================
 * written by Michael Shriki, id:305599417 login:michaelshr
 *
 * part 1: print copy of the first array with only alphabet and upper case
 * part 2: print the first array after we remove the value that common
 * with the second array
 *
 * Input: 2 arrays
 * ============================================================================
 * Output: the program print (1) copy of the first array
 * (2) the first array after we remove the value that common
 * with the second array
 * ============================================================================
 */

#include<iostream>
#include<cstdlib>
#include<cctype>
#include<iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::setw;

// ---------------- constant area ---------------------------------------------

const int MAX_STR_LEN = 100;

// ---------------- Prototype area --------------------------------------------

void part1(char arr[]); // function that do part one
void part2(char arr[], char brr[]); // function that do part tow

//-----------------------------------------------------------------------------

void part1(char arr[])
{
	for (int i = 0; arr[i] != '\0'; i++) {
		if (isalpha(arr[i])) { // check if the string is alphabet
			if (arr[i] >= 97 && arr[i] <= 122) // change from low case to upper
				cout << (char) (arr[i] - 32);
			else
				cout << arr[i];
		}
	}
	cout << endl;
}

//-----------------------------------------------------------------------------

void part2(char arr[], char brr[])
{
	bool is_common[MAX_STR_LEN];

	for (int i = 0; arr[i] != '\0'; i++) // array of false
		is_common[i] = false;

	for (int i = 0; brr[i] != '\0'; i++) {
		for (int j = 0; arr[j] != '\0'; j++) {
			if (arr[j] == brr[i])
				is_common[j] = true;
		}
	}
	for (int i = 0; arr[i] != '\0'; i++) {
		if (!is_common[i])
			cout << arr[i];
	}

	cout << endl;
}

// ---------------- the main code ---------------------------------------------

int main()
{
	char arr[MAX_STR_LEN];
	char brr[MAX_STR_LEN];

	// reading values to the arrays
	cin >> setw(MAX_STR_LEN) >> arr >> setw(MAX_STR_LEN) >> brr;

	part1(arr); // calling to part one
	part2(arr, brr); // calling to part tow

	return EXIT_SUCCESS;
}
