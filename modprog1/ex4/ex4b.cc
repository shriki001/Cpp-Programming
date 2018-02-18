/*ex4b: a program that finding the most common values in an array
 * ============================================================================
 * written by Michael Shriki, login:michaelshr
 *
 * the program  finding the most common values in an array
 *
 * Input: 10 value to array
 * ============================================================================
 * Output: the program print the most common value(s) in the array
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
	// three array
	// 1) array of values. 2) array of common values. 3) counting array.

	int arr[MAX], brr[MAX], crr[MAX];
	int j, count = 0, sum, max = 0;

	// reading values to the array

	for (int i = 0; i < MAX; i++)
		cin >> arr[i];

	// building the common array

	for (int i = 0; i < MAX; i++) {
		for (j = 0; j < count; j++) {
			if (arr[i] == brr[j])
				break;
		}

		if (j == count) {
			brr[count] = arr[i];
			count++;
		}
	}

	// building the counting array

	for (int j = 0; j < count; j++) {
		sum = 0;
		for (int i = 0; i < MAX; i++) {
			if (arr[i] == brr[j])
				sum++;
		}
		crr[j] = sum;
	}

	// check what value is the most common

	for (int j = 0; j < count; j++)
		if (crr[j] > max)
			max = crr[j];
	// print the most common values(s)

	for (int j = 0; j < count; j++)
		if (crr[j] == max)
			cout << brr[j] << endl;

	return EXIT_SUCCESS;
}

