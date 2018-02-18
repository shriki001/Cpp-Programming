/*ex3a: a program that calculate the average and counting how many numbers are
 * positive and negative
 * ============================================================================
 * written by Michael Shriki, login:michaelshr
 *
 * the program calculate the average and counting how many numbers are
 * positive and negative
 *
 * Input: any numbers from the user until the user put 0
 * ============================================================================
 * Output: the program print how much operand the user put , what is their
 * average , how many was positive and how many negative
 * ============================================================================
 */

#include<iostream>
#include<cstdlib>

using std::cout;
using std::endl;
using std::cin;

// the main code
//-----------------------------------------------------------------------------

int main()
{
	// number form the user, number of operands, sum of all the operands,
	// the average, how many negative, how many positive.

	int num, counter = 0, sum = 0, average, negative = 0, positive = 0;

	cin >> num;

	while (num != 0) {
		counter++;
		if (num > 0)
			positive++;
		else
			negative++;
		sum += num;
		cin >> num;
	}

	average = sum / counter; // calculate the average

	// print the number of the operand, their average,
	// how many negative and how many positive.

	cout << counter << " " << average << " " <<
			positive << " " << negative << endl;

	return EXIT_SUCCESS;
}
