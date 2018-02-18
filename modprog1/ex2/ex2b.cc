/*ex2b: a program that finds the maximum value
 * that can be achieved when a single multiplication operations and a single
 * connection on three numbers in any order
 * ============================================================================
 * written by Michael Shriki, id=305599417 login:michaelshr
 *
 * a Program reads from the user 3 numbers, and finds the maximum value
 * that can be achieved when a single multiplication operations and a single
 * connection on three numbers in any order
 *
 * Input: the program read 3 numbers from the user
 * ============================================================================
 * Output: the program print the maximum value
 * that can be achieved when a single multiplication operations and a single
 * connection on three numbers in any order
 * ============================================================================
*/

#include<iostream>

using std::cout;
using std::endl;
using std::cin;

// the main code
//-----------------------------------------------------------------------------

int main() {

	// the tree numbers from the user
	int num1, num2, num3;
	// 6 option for multiplication operations and a single connection
	int op1, op2, op3, op4, op5, op6;

	cin >> num1 >> num2 >> num3;

	op1 = (num1 + num2) * num3;
	op2 = (num1 + num3) * num2;
	op3 = (num2 + num3) * num1;
	op4 = (num2 * num3) + num1;
	op5 = (num1 * num3) + num2;
	op6 = (num1 * num2) + num3;

	if (op1 == op4 || op2 == op4 || op3 == op4)
		cout << num2 << "*" << num3 << "+" << num1 << "=" << op4 << endl;
	else if (op1 == op5 || op2 == op5 || op3 == op5)
		cout << num1 << "*" << num3 << "+" << num2 << "=" << op5 << endl;
	else if (op1 == op6 || op2 == op6 || op3 == op6)
		cout << num1 << "*" << num2 << "+" << num3 << "=" << op6 << endl;

	else if (op1 > op2 && op1 > op3 && op1 > op4 && op1 > op5 && op1 > op6)
		cout << "(" << num1 << "+" << num2 << ")" << "*" << num3 << "=" << op1
				<< endl;
	else if (op2 > op1 && op2 > op3 && op2 > op4 && op2 > op5 && op2 > op6)
		cout << "(" << num1 << "+" << num3 << ")" << "*" << num2 << "=" << op2
				<< endl;
	else if (op3 > op1 && op3 > op2 && op3 > op4 && op3 > op5 && op3 > op6)
		cout << "(" << num2 << "+" << num3 << ")" << "*" << num1 << "=" << op3
				<< endl;

	else if (op4 > op1 && op4 > op2 && op4 > op3 && op4 > op5 && op4 > op6)
		cout << num2 << "*" << num3 << "+" << num1 << "=" << op4 << endl;
	else if (op5 > op1 && op5 > op2 && op5 > op3 && op5 > op4 && op1 > op6)
		cout << num1 << "*" << num3 << "+" << num2 << "=" << op5 << endl;
	else
		cout << num1 << "*" << num2 << "+" << num3 << "=" << op6 << endl;

	return 0;

}
