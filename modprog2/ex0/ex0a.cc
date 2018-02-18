/*ex0a: a program that get input file and do 3 things:
 * 1) if there are strings with alphabet only its print 'a'
 * 2) if there are strings with digit only its print '0'
 * 3) if there are strings with anything else its print 'x'
 * ============================================================================
 * written by Michael Shriki, login:michaelshr
 *
 * the program get input file and do 3 things:
 * 1) if there are strings with alphabet only its print 'a'
 * 2) if there are strings with digit only its print '0'
 * 3) if there are strings with anything else its print 'x'
 *
 * Input: file with characters
 * ============================================================================
 * Output: the program print according to the file characters 'a' or '0' or 'x'
 * and how many strings are alphabet ,digits or others
 * ============================================================================
 */

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<cstring>

using std::ifstream;
using std::ofstream;
using std::cerr;
using std::endl;
using std::setw;
using std::cout;

// ------------ constant area -------------------------------------------------

const int MAX_STR_LEN = 20;

// ---------------- Prototype area --------------------------------------------

// function that read line by line from file and do all
void read_line(ifstream &inp, ofstream &out);
bool is_alpha(char str[]); // function that check if string is alphabet
bool is_number(char str[]); // function that check if string is digit
// function that print to output file
void print_line(ofstream &out, char str[], int num, char charcter);

//------------------- the main code -------------------------------------------

int main(int argc, char *argv[]) {
	ifstream inp;
	ofstream out;

	if (argc != 3) {
		cerr << "Usage: " << argv[0] << " <input file> <output file> \n";
		exit(EXIT_FAILURE);
	}

	inp.open(argv[1]);
	out.open(argv[2]);
	if (!inp.is_open() || !out.is_open()) {
		cerr << "Error opening file/s \n";
		exit(EXIT_FAILURE);
	}

	read_line(inp, out); // calling to function for reading new line

	// closing files
	inp.close();
	out.close();

	return EXIT_SUCCESS;

}

//------------------ function that check if string is alphabet ----------------

bool is_alpha(char str[]) {
	for (int i = 0; str[i] != '\0'; i++)
		if (!isalpha(str[i]))
			return false;
	return true;
}

//----------------- function that check if string is digit --------------------

bool is_number(char str[]) {
	for (int i = 0; str[i] != '\0'; i++)
		if (!isdigit(str[i]))
			return false;
	return true;

}

//---------------- function that print to output file -------------------------

void print_line(ofstream &out, char str[], int num, char charcter) {

	for (int i = 0; i < num; i++)
		out << " ";

	for (int i = 0; str[i] != '\0'; i++)
		out << charcter;
}

//--------- function that read line by line from file and do all --------------

void read_line(ifstream &inp, ofstream &out) {
	char last[MAX_STR_LEN] = { ' ' }, curr[MAX_STR_LEN];

	int space = 0, // count for spaces
	count_numbers = 0, // count for digit string
	count_alpha = 0, // count for alphabet strings
	count_others = 0; // count for others strings

	while (!inp.eof()) {

		while (inp.peek() == ' ' || inp.peek() == '\n') {
			if (inp.peek() == ' ') {
				inp.get();
				space++;
			} else if (inp.peek() == '\n') {
				inp.get();
				out << endl;
				cout << count_alpha << " " << count_numbers << " "
						<< count_others << endl;
				space = 0;
				count_numbers = 0;
				count_alpha = 0;
				count_others = 0;
			}
		}

		inp >> setw(MAX_STR_LEN) >> curr;

		if (strcmp(curr, last) != 0) {
			if (is_alpha(curr)) {
				print_line(out, curr, space, 'a');
				count_alpha++;
			} else if (is_number(curr)) {
				print_line(out, curr, space, '0');
				count_numbers++;
			} else {
				print_line(out, curr, space, 'x');
				count_others++;
			}
		}
		strcpy(last, curr);
		space = 0;
	}
}
