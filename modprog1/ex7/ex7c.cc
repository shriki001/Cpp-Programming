/*ex7c: a program that find the max sequence in array
 * ============================================================================
 * written by Michael Shriki, id:305599417 login:michaelshr
 *
 * the program find the max sequence of one array in another
 *
 * Input: 2 arrays
 * ============================================================================
 * Output: the program print the max sequence between tow arrays
 * ============================================================================
 */

#include<iostream>
#include<cstdlib>
#include<cctype>
#include<iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::setw;

// ---------------- constant area ---------------------------------------------

const int N = 100;

// ---------------- Prototype area --------------------------------------------

int check(char arr[], char brr[]);//function that compare to elements in arrays
//function that count the size of the right element
int ans(char arr[], char brr[], int &a, int b);

//----------------------------------------------------------------------------

int ans(char arr[], char brr[], int &a, int b)
{
	int count = 0;

	for (; arr[a] != '\0' && brr[b] != '\0'; a++, b++) {
		if (arr[a] == brr[b])
			count++;
		else
			return count;
	}

	return count;
}

int check(char arr[], char brr[])
{
	int max = -1, sum;
	int j, i = 0;
	while (arr[i] != '\0') {
		j = 0;
		while (arr[i] != brr[j] && brr[j] != '\0')
			j++;
		if (brr[j] == '\0')
			i++;
		else {
			sum = ans(arr, brr, i, j);
			if (sum > max)
				max = sum;
		}
	}

	return max;

}

int main() {

	char arr[N];
	char brr[N];

	cin >> setw(N) >> arr >> setw(N) >> brr;// read value to the arrays

	cout << check(arr, brr) << endl; // print the max sequence

	return EXIT_SUCCESS;

}
