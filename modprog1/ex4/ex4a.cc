/*ex4a: a program that calculate the average and the
 * variance of values in an array
 * ============================================================================
 * written by Michael Shriki, login:michaelshr
 *
 * the program calculate the average and the variance of values in an array
 *
 * Input: 7 value to array
 * ============================================================================
 * Output: the program print the average and the variance of
 * values in the array
 * ============================================================================
 */

#include<iostream>
#include<cstdlib>

using std::cout;
using std::endl;
using std::cin;

// constant area
//-----------------------------------------------------------------------------

const int MAX = 7; // constant max value

// the main code
//-----------------------------------------------------------------------------

int main()
{
	double arr[MAX]; // the array of the program
	double average, variance; // the average and the variance

	// reading values to the array
	for (int i = 0; i < MAX; i++)
		cin >> arr[i];

	// calculate the average of the values

	for (int i = 0; i < MAX; i++)
		average += arr[i] / MAX;

	// calculate the variance of the values

	for (int i = 0; i < MAX; i++)
		variance += ((arr[i] - average) * (arr[i] - average) / MAX);

	// print the average and the variance
	cout << average << " " << variance << endl;

	return EXIT_SUCCESS;

}
