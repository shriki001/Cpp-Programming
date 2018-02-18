/*ex2c: a program that printing correct date
 * ============================================================================
 * written by Michael Shriki, login:michaelshr
 *
 * the program getting 3 numbers as day , month and year
 * check if the numbers are veiled for a correct date and printing the date
 *
 * Input: the program read 3 numbers from the user
 * ============================================================================
 * Output: the program print correct date if its possible
 * ============================================================================
 */

#include<iostream>

using std::cout;
using std::endl;
using std::cin;

// the main code
//-----------------------------------------------------------------------------

int main() {

	int day, month, year; // the day month and year from the user

	cin >> day >> month >> year;

	if ((year >= 1 && year <= 3000) && (day >= 1 && day <= 31)
			&& (month >= 1 && month <= 12)) {

		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8
				|| month == 10 || month == 12)) {
			if (day == 1 || day == 21 || day == 31)
				cout << day << "st ";
			else if (day == 2 || day == 22)
				cout << day << "nd ";
			else if (day == 3 || day == 23)
				cout << day << "rd ";
			else
				cout << day << "th ";

			switch (month) {

			case 1:
				cout << "January ";
				break;
			case 3:
				cout << "March ";
				break;
			case 5:
				cout << "May ";
				break;
			case 7:
				cout << "July ";
				break;
			case 8:
				cout << "August";
				break;
			case 10:
				cout << "October ";
				break;
			case 12:
				cout << "December ";
				break;
			}
			cout << year << endl;
		}

		if ((month == 4 || month == 6 || month == 9 || month == 11)
				&& day != 31) {

			if (day == 1 || day == 21 || day == 31)
				cout << day << "st ";
			else if (day == 2 || day == 22)
				cout << day << "nd ";
			else if (day == 3 || day == 23)
				cout << day << "rd ";
			else
				cout << day << "th ";

			switch (month) {

			case 4:
				cout << "April ";
				break;
			case 6:
				cout << "June ";
				break;
			case 9:
				cout << "September ";
				break;
			case 11:
				cout << "November ";
				break;
			}
			cout << year << endl;
		}

		if ((month == 2) && (day >= 1 && day <= 28)) {
			if (day == 1 || day == 11 || day == 21)
				cout << day << "st ";
			else if (day == 2 || day == 22)
				cout << day << "nd ";
			else if (day == 3 || day == 23)
				cout << day << "rd ";
			else
				cout << day << "th ";

			cout << "February " << year << endl;

		} else if ((day == 29)
				&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
			cout << day << "th" << " " << "February " << year << endl;
	}

	return 0;
}
