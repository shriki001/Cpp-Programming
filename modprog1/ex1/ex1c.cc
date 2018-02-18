/*ecorx1c: a program that finding the radius, area and the perimeter of a block
 * circle triangle and the radius, area and the perimeter of a
 * circumscribed circle triangle
 * ============================================================================
 * written by Michael Shriki, id=305599417 login:michaelshr
 *
 * the program calculate the radius, area and the perimeter of a block circle
 * triangle and the radius area and the perimeter of a circumscribed
 * circle triangle
 *
 * Input: 4 numbers that represent two vectors of a rectangle
 * ============================================================================
 * Output: the program print the radius, area and the perimeter of a
 * block circle triangle and the radius, area and the perimeter of a
 * circumscribed circle triangle
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
	double corx1, cory1, corx2, cory2; // the 4 coordinate (corx1,cory1),
									  // (corx2,cory2).

	cin >> corx1 >> cory1 >> corx2 >> cory2;

	double r1 = (cory1 - cory2) / 2;// the radius of the block circle triangle
	// the radius of a circumscribed circle triangle
	double r2 = sqrt((cory2 - cory1) * (cory2 - cory1) +
			((corx2 - corx1) * (corx2 - corx1))) / 2;

	cout << r1 << " " << 3.1415 * (r1 * r1) << " " << 2 * 3.1415 * r1 << endl;
	cout << r2 << " " << 3.1415 * (r2 * r2) << " " << 2 * 3.1415 * r2 << endl;

	return 0;

}
