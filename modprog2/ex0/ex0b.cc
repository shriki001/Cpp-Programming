/*ex0b: a program that remove documentation note from program code
 * ============================================================================
 * written by Michael Shriki, login:michaelshr
 *
 * the program get a program code and remove documentation note
 * from the program
 *
 * Input: program in C
 * ============================================================================
 * Output: the program print the program without the documentation note
 * ============================================================================
 */

#include<iostream>
#include<cstdlib>

using std::cerr;
using std::endl;
using std::cout;
using std::cin;

// ------------ constant area -------------------------------------------------

const int MAX_LINE_LEN = 200;

// ---------------- Prototype area --------------------------------------------

// function that read line by line from the program
void read(char line[], bool note, int count);
// function that remove the documentation note from the program
void remove(char line[], bool note, int count);

//------------------- the main code -------------------------------------------

int main() {

	bool note = false; // to know if we are in a documentation note
	int count = 0; // to count how many documentation note are open
	char line[MAX_LINE_LEN];
	read(line, note, count); // calling to reading function

	return EXIT_SUCCESS;
}

//------- function that remove the documentation note from the program --------

void remove(char line[], bool note, int count) {

	if (line[0] == '\0' && !note)
		cout << endl;
	for (int i = 0; line[i] != '\0'; i++) {
		// if its a "//" documentation note read new line automatically
		if (line[i] == '/' && line[i + 1] == '/') {
			read(line, note, count);
			// if documentation note was opened
		} else if (line[i] == '/' && line[i + 1] == '*') {
			count++;
			note = true;
			i++;
			// if documentation note was closed
		} else if (line[i] == '*' && line[i + 1] == '/') {
			count--;
			if (count == 0)
				note = false;
			i++;
			// if we are not in documentation note start printing
		} else if (!note)
			cout << line[i];

		if (!note && count < 0)
			exit(EXIT_FAILURE);

		if (line[i + 1] == '\0' && !note)
			cout << endl;
	}
	read(line, note, count); // read the next line
}

//-------- function that read line by line from the program -------------------

void read(char line[], bool note, int count) {

	cin.getline(line, MAX_LINE_LEN);
	while (!cin.eof())
		// calling to the function that remove documentation note
		remove(line, note, count);
	if (count > 0) //if the program end with documentation note open send error
		cerr << "Error in input. Program ended in a comment. depth = " << count
				<< endl;

	exit(EXIT_SUCCESS);
}

