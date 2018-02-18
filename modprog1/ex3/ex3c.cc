/*ex3c: a program that ask from the user to guess a number from the random
 * numbers that the computer come up with
 * ============================================================================
 * written by Michael Shriki, id=305599417 login:michaelshr
 *
 * the program get form the user the max range of the random numbers from 0,
 * the program ask the user to guess the random number that the computer
 * come up with and for every step the program tell the user if his/her guess was
 * too big or too small, also the program give to the user info about how many
 * steps rational unlucky user would need to get the job down,
 * finally the program give to the user his grade.
 * after all this the program ask the user if he/she want to start all over
 *
 * Input: the max range of the random numbers and the user guess
 * and finally 1 to start over or any number to exit
 * ============================================================================
 * Output: the program tell the user every step if the guess id too big or too
 * small from the number that the computer come up with, the program print:
 * 1) user's steps. 2) rational unlucky user steps. 3) the grade
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
	// max number to the range, user guess
	int max_range, user_guess;
	// random numbers that the computer come up with from the range,
	// user steps, rational unlucky user steps, the grade,
	// variable to star over
	int random_num, count = 1, razional_num=1, grade, again = 1;
	// variable for Micha's algorithm
	int rational_guess, change;

	srand(1);// set the random numbers to be constants

	// calculate the user steps an inform if he/she too big or too small
	while (again == 1) {
		cin >> max_range;
		random_num = rand() % (max_range + 1);
		cin >> user_guess;
		while (user_guess != random_num) {
			if (user_guess < random_num)
				cout << "too small" << endl;
			else
				cout << "too big" << endl;

			count++;
			cin >> user_guess;
		}

		// find the rational user guess by Micha's algorithm

		rational_guess = (max_range % 2 == 0) ?
				(max_range / 2) : (max_range / 2 + 1);
		change =(rational_guess % 2 == 0) ?
				(rational_guess / 2) : (rational_guess / 2 + 1);

		while (rational_guess != random_num) {
			if (rational_guess < random_num)
				rational_guess = rational_guess + change;

			else if (rational_guess > random_num)
				rational_guess = rational_guess - change;

			change = (change % 2 == 0) ? (change / 2) : (change / 2 + 1);
			razional_num++;
		}

		grade = ((double) razional_num / count) * 100; // calculate the grade

		if (grade > 100)
			grade = 100;

		cout << count << " " << razional_num << endl;
		cout << grade << endl;
		cout << "again? 1:YES \n"; // ask the user if he/she want to start over

		count = 1; // zero the user steps for the next round
		// zero the rational unlucky user steps for the next round
		razional_num=1;

		cin >>again;
		if (again != 1)
			break;
	}

	return EXIT_SUCCESS;
}
