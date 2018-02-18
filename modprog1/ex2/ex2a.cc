/*ex2a: a program that printing how much numbers are even , odd, positive ,
 * negative or zero's.
 * ============================================================================
 * written by Michael Shriki, login:michaelshr
 *
 * the program getting 4 numbers and printing how much numbers are even , odd,
 * positive , negative or zero's
 *
 * Input: the program read 4 numbers from the user
 *
 * ============================================================================
 * Output: the program print how much numbers are even , odd,
 * positive , negative or zero's
 * ============================================================================
*/

#include<iostream>

using std::cout;
using std::endl;
using std::cin;

// the main code
//-----------------------------------------------------------------------------

int main() {

	int num1, num2, num3, num4; // the four number from user

	cin >> num1 >> num2 >> num3 >> num4;

	// counter for the even and odd number
	int sum_even = 0, sum_odd = 0;
	// counter for the negative zeros and positive numbers
	int sum_1 = 0, sum_0 = 0, sum = 0;

	if (num1 % 2 == 0)
		sum_even++;
	else
		sum_odd++;

	if (num1 == 0)
		sum_0++;
	else if (num1 > 0)
		sum++;
	else
		sum_1++;

	if (num2 % 2 == 0)
		sum_even++;
	else
		sum_odd++;

	if (num2 == 0)
		sum_0++;
	else if (num2 > 0)
		sum++;
	else
		sum_1++;

	if (num3 % 2 == 0)
		sum_even++;
	else
		sum_odd++;

	if (num3 == 0)
		sum_0++;
	else if (num3 > 0)
		sum++;
	else
		sum_1++;

	if (num4 % 2 == 0)
		sum_even++;
	else
		sum_odd++;

	if (num4 == 0)
		sum_0++;
	else if (num4 > 0)
		sum++;
	else
		sum_1++;

	cout << sum_even << " " << sum_odd << endl;
	cout << sum << " " << sum_0 << " " << sum_1 << endl;

	return 0;
}
