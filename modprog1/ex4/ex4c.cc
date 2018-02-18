/*ex4c: a program that finding a loop in an array and print the loop
 * ============================================================================
 * written by Michael Shriki, login:michaelshr
 *
 * the program finding a loop in an array and print the loop
 *
 * Input: 10 values to array
 * ============================================================================
 * Output: the program print the first loop in the array and the first place
 * that the loop start from
 * ============================================================================
 */

#include<iostream>
#include<cstdlib>

using std::cout;
using std::endl;
using std::cin;

// constant area
//-----------------------------------------------------------------------------

const int MAX = 10;

// the main code
//-----------------------------------------------------------------------------

int main()
{
	int a[MAX], b[MAX]; //

	int first_place = 0; // the first place of the loop
	int current_place; // the current place of the loop
	int next_place; // the next place of the loop
	int count = 0;
	int index = 0;
	bool found = false;

	// reading values to the array

	for (int i = 0; i < MAX; i++)
		cin >> a[i];

	// finding the loop

	while (!found && first_place < MAX) {
		current_place = index;
		next_place = a[current_place];

		if (next_place == first_place) {
			found = true;
			b[count] = current_place;
			count++;
		} else {
			if (next_place > MAX || a[next_place] == a[first_place]) {
				first_place++;
				count = 0;
				index = first_place;
			} else {    //next is in array
				b[count] = current_place;
				count++;
				index = next_place;
			}
		}
	}

	// if the loop was found print the values

	if (found)
		for (int i = 0; i < count; i++)
			cout << b[i] << " ";

	cout << first_place << endl; // print the first place of the loop

	return EXIT_SUCCESS;
}
