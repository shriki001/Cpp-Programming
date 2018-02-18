/*ex1b: a program that calculate area and perimeter of a triangle
 * ============================================================================
 * written by Michael Shriki, login:michaelshr
 *
 * the program calculate area and perimeter of a triangle
 *
 * Input: The three sides of a triangle
 * ============================================================================
 * Output: the program calculate area and perimeter of a triangle
 * ============================================================================
 */

#include<iostream>
#include<cmath>

using std::cout;
using std::endl;
using std::cin;

// the main code
//-----------------------------------------------------------------------------

int main()
{
	double side1, side2, side3; // the tree size of triangle
	double area, perimeter; // the area and the perimeter of the triangle
	double s; // the half of triangle perimeter for the Heron formula

	cin >> side1 >> side2 >> side3;

	perimeter = side1 + side2 + side3;
	s = perimeter / 2.0;
	area = sqrt(s * (s - side1) * (s - side2) * (s - side3));

	cout << area << endl;
	cout << perimeter << endl;

	return 0;

}
