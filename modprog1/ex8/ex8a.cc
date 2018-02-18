/*ex8a: a program that have 13 parts and the user need to choose between 13
 * option what he/she want to do
 * ============================================================================
 * written by Michael Shriki, id:305599417 login:michaelshr
 * the user need to:
 * part 1: put value to array
 * part 2: search value as he want
 * part 3: sorting the array in order small to big
 * part 4: search value as he want only if the array sorted in order small
 * to big via binary search algorithm
 * part 5: count how many times value show in the array
 * part 6: print the array from the beginning to the last
 * part 7: print the array from the last to the beginning
 * part 8: check if the array sort in up order
 * part 9: check if the array is palindrom
 * part 10: check how many values are the sum of the last tow
 * part 11: copy to another array the values are show one time in
 * the current array
 * part 12: check what value is prime number and print it
 * part 13: EXIT the program.
 *
 * Input: array and user choices
 * ============================================================================
 * Output: the program does the function according to user choice
 * ============================================================================
 */

#include<iostream>
#include<cstdlib>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;

// ---------------- constant area ---------------------------------------------

const int MAX = 10; // max size of array
const int START = 0; // start index of all the program
enum opt_t { // object for all options that show in the program
	READ_T,
	SEARCH_T,
	BUBBLE_SORT_T,
	BINARY_SEARCH_T,
	COUNNTER_T,
	PRINT_T,
	PRINT_REVERSE_T,
	IS_SORTED_T,
	PALINDROM_T,
	SUM_OF_TOW_T,
	COPY_T,
	PRIME_T,
	EXIT_T
};

// ---------------- Prototype area --------------------------------------------

void read(int arr[], int index); // putting value to the array
void search(int arr[], int index, int find); // search value in array
void bubble_sort(int arr[], int index, int num); // sorting the array
void bubble_sort_a(int arr[], int index); // help function to sorting function
// count how many times value show in the array
int counter(int arr[], int index, int num, int &count);
void print(int arr[], int index); // print the array from the beginning to last
// print the array from the last to beginning
void print_revese(int arr[], int index);
void palindrom(int arr[], int first, int last);//check if the array is palindrom
void prime(int arr[], int index);// print the prime number that in the array
// help function to check if number is prime number
int prime(int num, int first, int last);
// check if the array is sort up order
int is_sorted(int arr[], int index, bool &arr_is_sorted);
// find value in array only if the array sorted via binary search algorithm
int binary_search(int arr[], int max, int find, int first, int last, bool sort);
// check how many values are the sum of the last tow
int sum_of_tow(int arr[], int index, int count);
int sum(int arr[], int index); // help function to sum values
// copy to another array the values are show one time in the current array
void copy(int arr[], int brr[], int idex, int jdex, int count, int num);
void play(int arr[], bool &sort); // the main function that do all

//-----------------------------------------------------------------------------

// ---------------- the main code ---------------------------------------------

int main()
{
	int arr[MAX] = { START }; // the array for the program
	bool arr_is_sorted = true;

	play(arr, arr_is_sorted); // calling to the main function that do all

	return EXIT_SUCCESS;
}

//-----------------------------------------------------------------------------

//------- the main function ---------------------------------------------------

void play(int arr[], bool &arr_is_sorted)
{
	int count = START;
	int brr[MAX] = { START }; // help array for copy function

	enum opt_t options;
	int num;
	cin >> num;
	options = (enum opt_t) (num - 1);
	switch (options) {
	case READ_T: {
		arr_is_sorted = false;
		read(arr, START);
		break;
	}
	case SEARCH_T: {
		int num;
		cin >> num;
		search(arr, START, num);
		break;
	}
	case BUBBLE_SORT_T: {
		bubble_sort_a(arr, START);
		arr_is_sorted = true;
		break;
	}
	case BINARY_SEARCH_T: {
		int num;
		cin >> num;
		int check = binary_search(arr, MAX, num, START, MAX - 1, arr_is_sorted);
		if (check != -1)
			cout << check << endl;
		break;
	}
	case COUNNTER_T: {
		int num;
		cin >> num;
		cout << counter(arr, START, num, count) << endl;
		break;
	}
	case PRINT_T: {
		print(arr, MAX);
		cout << endl;
		break;
	}
	case PRINT_REVERSE_T: {
		print_revese(arr, MAX - 1);
		break;
	}
	case IS_SORTED_T: {
		cout << is_sorted(arr, START, arr_is_sorted) << endl;
		break;
	}
	case PALINDROM_T: {
		palindrom(arr, START, MAX - 1);
		break;
	}
	case SUM_OF_TOW_T: {
		cout << sum_of_tow(arr, START + 1, count) << endl;
		break;
	}
	case COPY_T: {
		copy(arr, brr, START, START, count, count);
		break;
	}
	case PRIME_T: {
		prime(arr, START);
		break;
	}
	case EXIT_T:
		return;
	}

	play(arr, arr_is_sorted);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void copy(int arr[], int brr[], int idex, int jdex, int count, int num)
{
	if (idex == MAX) {
		print(brr, count);
		cout << endl;
		return;
	}
	if (counter(arr, num, arr[idex], num) == 1) {
		brr[jdex++] = arr[idex];
		count++;
	}

	return copy(arr, brr, ++idex, jdex, count, START);

	// run time: n , when n is the max size of the array

}
//-----------------------------------------------------------------------------

int sum(int arr[], int index)
{
	if (index == 0)
		return 0;

	return arr[index - 1] + sum(arr, index - 1);

	// run time: 2
}

int sum_of_tow(int arr[], int index, int count)
{
	if (index == MAX)
		return count;
	if (arr[index] == sum(arr, index))
		count++;

	return sum_of_tow(arr, ++index, count);

	// run time: n , when n is the max size of the array
}

//-----------------------------------------------------------------------------

int binary_search(int arr[], int max, int find, int first, int last, bool sort)
{
	if (!sort) {
		cerr << "Error \n";
		return -1;
	}
	int count = 0, middle = 0;
	if (first <= last) {
		middle = (first + last) / 2;
		if (find == arr[middle])
			count = 1;
		else if (find < arr[middle])
			return (binary_search(arr, max, find, first, --middle, sort));
		else
			return (binary_search(arr, max, find, ++middle, last, sort));
	}

	return count;

	// run time: log n , when n is the max size of the array
}

//-----------------------------------------------------------------------------

int is_sorted(int arr[], int index, bool &arr_is_sorted)
{
	if (index == MAX - 1) {
		arr_is_sorted = true;
		return 1;
	}

	if (arr[index] <= arr[index + 1])
		return is_sorted(arr, ++index, arr_is_sorted);

	else {
		arr_is_sorted = false;
		return 0;
	}

	// run time: n , when n is the max size of the array
}

//-----------------------------------------------------------------------------

int prime(int num, int first, int last)
{
	if (num == 1)
		return 0;

	if (num == 2)
		return 1;

	else {

		if (num % first == 0)
			return 0;

		if (first == last)
			return 1;

		return prime(num, ++first, last);
	}

	// run time: m , when m is the number to check if he prime
}

void prime(int arr[], int index)
{
	if (index == MAX) {
		cout << endl;
		return;
	}

	int check = prime(arr[index], START + 2, arr[index] - 1);
	if (check == 1)
		cout << arr[index] << " ";

	return prime(arr, ++index);

	// run time: n*m , when n is the max size of the array
	// and m is the number to check if he prime
}

//-----------------------------------------------------------------------------

void palindrom(int arr[], int first, int last)
{
	if (first > last) {
		cout << "1 \n";
		return;
	}
	if (arr[first] != arr[last]) {
		cout << "0 \n";
		return;
	}
	return palindrom(arr, ++first, --last);

	// run time: 1

}

//-----------------------------------------------------------------------------

void print_revese(int arr[], int index)
{
	if (index == 0) {
		cout << arr[index] << " ";
		cout << endl;
		return;
	}
	cout << arr[index] << " ";
	return print_revese(arr, --index);

	// run time: 1
}

//-----------------------------------------------------------------------------

void print(int arr[], int index)
{
	if (index == 0) {
		return;
	}
	print(arr, --index);
	cout << arr[index] << " ";

	// run time: 1
}

//-----------------------------------------------------------------------------

int counter(int arr[], int index, int num, int &count)
{
	if (index == MAX)
		return count;
	if (arr[index] == num)
		count++;
	return counter(arr, ++index, num, count);

	// run time: n , when n is the max size of the array
}

//-----------------------------------------------------------------------------

void bubble_sort_a(int arr[], int idex)
{
	if (idex == MAX)
		return;
	bubble_sort(arr, idex, START);
	bubble_sort_a(arr, ++idex);

	// run time: n , when n is the max size of the array
}

void bubble_sort(int arr[], int idex, int jdex)
{
	if (jdex == (MAX - idex - 1))
		return;
	if (arr[jdex] > arr[jdex + 1]) {
		int temp = arr[jdex];
		arr[jdex] = arr[jdex + 1];
		arr[jdex + 1] = temp;
	}
	bubble_sort(arr, idex, ++jdex);

	// run time: n^2 , when n is the max size of the array
}

//-----------------------------------------------------------------------------

void search(int arr[], int index, int find)
{
	if (index == MAX) {
		cout << "0 \n";
		return;
	}
	if (arr[index] == find) {
		cout << "1 \n";
		return;
	}
	search(arr, ++index, find);

	// run time: n , when n is the max size of the array
}

//-----------------------------------------------------------------------------

void read(int arr[], int index)
{
	int num;
	if (index == MAX)
		return;
	cin >> num;
	arr[index] = num;
	read(arr, ++index);

	// run time: n , when n is the max size of the array

}


//-----------------------------------------------------------------------------

