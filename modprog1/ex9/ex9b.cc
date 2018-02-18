/*ex9b: a program that return the minimum steps to get from
 * one number to another
 * ============================================================================
 * written by Michael Shriki, id:305599417 login:michaelshr
 *
 * the program check the minimum steps to get from
 * one number to another
 *
 * Input: 2 numbers
 * ============================================================================
 * Output: the program print the minimum steps to get from
 * one number to another
 * ============================================================================
 */

#include<iostream>
#include<cstdlib>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

// ---------------- Prototype area --------------------------------------------

int num_of_ops(unsigned int n1, unsigned int n2);

//------------------- the main code -------------------------------------------

int main()
{
	int n1;
	int n2;

	cin >> n1 >> n2;
	cout << num_of_ops(n1, n2) << endl;

	return EXIT_SUCCESS;
}

int num_of_ops(unsigned int n1, unsigned int n2)
{
	int step_plus, step_mul;

	if (n1 > n2){
		cerr << "mission cannot accomplished \n";
		return -1;
	}

	if (n1 == n2)
		return 0;

	if (n1 == 0)
		return 1 + num_of_ops(1 + n1, n2);

	step_plus = 1 + num_of_ops(1 + n1, n2);
	step_mul = 1 + num_of_ops(2 * n1, n2);

	if (step_plus == 0)
		return step_mul;

	if (step_mul == 0)
		return step_plus;

	if (step_plus < step_mul)
		return step_plus;

	return step_mul;

}
