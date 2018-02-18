/*ex1a: a program that printing the difference between 3 numbers
 * ============================================================================
 * written by Michael Shriki, id=305599417 login:michaelshr
 *
 * the program getting 3 numbers and printing the difference between them
 *
 * Input: the program read 3 numbers, subtracting them and
 * printing the difference
 * ============================================================================
 * Output: the program print the difference between the numbers
 * ============================================================================
*/

#include<iostream>

using std::cout;
using std::endl;
using std::cin;

// the main code
//-----------------------------------------------------------------------------

int main()
{
	int num1, num2, num3; // the tree numbers from the user

	cin >> num1 >> num2 >> num3;

	cout << num1 - num1 << " " << num1 - num2 << " " << num1 - num3 << endl;
	cout << num2 - num1 << " " << num2 - num2 << " " << num2 - num3 << endl;
	cout << num3 - num1 << " " << num3 - num2 << " " << num3 - num3 << endl;

	return 0;

}
