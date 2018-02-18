/*ex3b: a program that finding the Greatest Common Divisor (GCD) of tow numbers
 * ============================================================================
 * written by Michael Shriki, login:michaelshr
 *
 * the program finding the GCD of tow numbers via Euclid's algorithm
 *
 * Input: pairs of numbers from the user until the user put 0
 * ============================================================================
 * Output: the GCD of all the pair numbers
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
	// pair number from the user
	unsigned int num1, num2;

	// temporary variable, the biggest number of the pair, the other number
	int temp, gcd_num1, gcd_num2;

	cin >> num1 >> num2;

	// change the order of the number to (big,small) if the was (small,big)
	while (num1 != 0) {

		gcd_num1 = (num1 > num2) ? num1 : num2;
		gcd_num2 = (num1 < num2) ? num1 : num2;
		temp = gcd_num2;

		// finding the GCD via Euclid's algorithm
		while (gcd_num1 % gcd_num2 != 0) {

			temp = gcd_num1 % gcd_num2;
			gcd_num1 = gcd_num2;
			gcd_num2 = temp;
		}

		cout << temp << endl;

		cin >> num1;

		// check if the user put 0
		if (num1 == 0)
			break;
		else
			cin >> num2;
	}

	return EXIT_SUCCESS;
}
