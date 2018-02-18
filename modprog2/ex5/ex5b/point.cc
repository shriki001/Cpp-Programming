#include <iostream>
#include <cstdlib>

//-----------------------------------------------------------------------------

using std::cerr;

//-----------------------------------------------------------------------------

void check_alloc(void *arr) {

	if (arr == NULL) {
		cerr << "Cannot allocated memory \n";
		exit(EXIT_FAILURE);
	}
}


