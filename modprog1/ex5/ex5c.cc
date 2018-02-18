/*ex5c: a program that check how many slants are bigger the the previous corner
 * ============================================================================
 * written by Michael Shriki, id:305599417 login:michaelshr
 *
 * the program check if the next slants bigger then the previous corner
 *
 * Input: 2nd array
 * ============================================================================
 * Output: the program print the number of slats that bigger then the corner
 * ============================================================================
 */

#include<iostream>
#include<cstdlib>

using std::cout;
using std::endl;
using std::cin;

// ------------ constant area -------------------------------------------------

const int ROWS = 5, COLS = 4;

// -------------- the main code -----------------------------------------------

int main()
{
	int a[ROWS][COLS];//array

	// reading values to the array
	for (int rows = 0; rows < ROWS; rows++)
		for (int cols = 0; cols < COLS; cols++)
			cin >> a[rows][cols];

	int max_prev = a[0][0]; // first corner
	int max_current; // max current
	// find the number of the slants
	int max_num_of_slants = ROWS > COLS ? COLS : ROWS;

	//found if the next slant bigger the the previous
	for (int i = 1; i < max_num_of_slants; i++) {
		max_current = a[i][0];
		for (int j = 0; j <= i; j++) {
			if (a[j][i - j] < max_prev) {
				cout << i << endl; // fount it and the end
				return EXIT_SUCCESS;
			}
			// find the current max
			max_current = a[j][i - j] > max_current ? a[j][i - j] : max_current;
		}
		max_prev = max_current;
	}
	cout << max_num_of_slants << endl; //print the number of slants

	return EXIT_SUCCESS;
}
