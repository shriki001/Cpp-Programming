/*ex1c: a program that do 9 little program
 * ============================================================================
 * written by Michael Shriki, login:michaelshr
 *
 * the program get input file and do 9 things:
 * 1) all line to array
 * 2) delete line from array
 * 3) join line to another
 * 4) split line to another
 * 5) add value to row in the array
 * 6) delete value from row in the array
 * 7) print the array
 * 8) pure the array
 * 9) Exit program
 *
 * Input: as the user wont to do
 * ============================================================================
 * Output: the program does operation according to the user input
 * ============================================================================
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include<cmath>

// --------------- Using area ----------------------------------------------

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::setw;
using std::nothrow;

// --------------- Constant area ----------------------------------------------

const int N = 3;

// --------------- enum area --------------------------------------------------

enum option_t {
	ADD_LINE_T,
	DELETE_LINE_T,
	JOIN_LINE_T,
	SPLIT_LINE_T,
	ADD_VALUE_T,
	DELETE_VALUE_T,
	PRINT_ARRAY_T,
	SHRINK_ARRAY_T,
	EXIT_PROGRAM_T
};

// --------------- Prototype area ---------------------------------------------

void func_menu();

void add_line(unsigned int **&matrix, int &total_rows, int &aloced_rows,
		unsigned int *&stack_empties, unsigned int **&sizes, int &max_alloc);

void delete_line(unsigned int **&matrix, unsigned int **&sizes,
		unsigned int *&stack, int &total, int &aloced, int del_row);

void join_line(unsigned int **&matrix, unsigned int **&sizes,
		unsigned int *&stack, int total, int &aloced, int row1, int row2);

void split_line(unsigned int **&matrix, unsigned int **&sizes,
		unsigned int *&stack, int total, int &aloced, int row_to_split,
		int index, int &max_alloce);

void add_value(unsigned int **&matrix, unsigned int **&sizes, int total,
		int value, int add_to_row);

void delete_value(unsigned int **&matrix, unsigned int **&sizes, int total,
		int from_row, unsigned int value);

void print_array(unsigned int **&matrix, unsigned int **&sizes, int total_rows,
		int aloced_rows, int max_alloc);

void shrink_array(unsigned int **&matrix, unsigned int **&sizes, int &total,
		int alloc, int &max_alloc);

void exit_program(unsigned int **&matrix, unsigned int **&sizes,
		unsigned int *&stack_empties, int total_rows);

void add_row_elements(unsigned int **&matrix_p, int row, int &total_elements);

void add_new_row(unsigned int **&matrix, unsigned int **&sizes,
		unsigned int *&stack, unsigned int *&temp2, int total, int &aloced,
		int &max_alloc, int &new_place);

void add_empty(unsigned int *&s, int row);

void resize_matrix(unsigned int **&arr, unsigned int **&sizes, int alloc_rows,
		int max_alloc);

void resize_arr(unsigned int *&arr, int aloc_cells);

void create_array(unsigned int **&arr, int size);

void create_array(unsigned int *&arr, int size);

void copy_n_del(unsigned int **&arr, unsigned int **&temp);

void free_memory(unsigned int **arr, int total_rows);


// ------------- The Main code ------------------------------------------------

int main() {

	func_menu();

	return EXIT_SUCCESS;
}

// ----------------------------------------------------------------------------

enum option_t get_option(char option_sign[]) {

	if (strcmp(option_sign, "e") == 0)		//case of end-of-input
		return EXIT_PROGRAM_T;

	if (strcmp(option_sign, "al") == 0)			//add new line
		return ADD_LINE_T;

	else if (strcmp(option_sign, "dl") == 0)	// delete and shrink lines
		return DELETE_LINE_T;

	else if (strcmp(option_sign, "jl") == 0)
		return JOIN_LINE_T;

	else if (strcmp(option_sign, "sl") == 0)
		return SPLIT_LINE_T;

	else if (strcmp(option_sign, "av") == 0)
		return ADD_VALUE_T;

	else if (strcmp(option_sign, "dv") == 0)
		return DELETE_VALUE_T;

	else if (strcmp(option_sign, "pr") == 0)
		return PRINT_ARRAY_T;

	else if (strcmp(option_sign, "pg") == 0)
		return SHRINK_ARRAY_T;

	return (enum option_t) -1;
}

// ----------------------------------------------------------------------------

void func_menu() {

	char option[N];

	int array_size = 1;
	unsigned int **matrix;
	unsigned int **sizes;
	unsigned int *stack_empties;
	create_array(matrix, array_size);
	create_array(sizes, array_size);
	create_array(stack_empties, array_size);
	bool first = true;

	int total_rows = 0;
	int aloced_rows = 0;
	int max_alloc = -1;

	cin >> setw(N) >> option;

	while (true) {
		enum option_t choise = get_option(option);   //cast to enum;
		switch (choise) {
		case ADD_LINE_T: {
			if (first) {
				total_rows = 1;
				stack_empties[0] = 0;
				first = false;
			}

			add_line(matrix, total_rows, aloced_rows, stack_empties, sizes,
					max_alloc);
			aloced_rows++;
			stack_empties[0]--;
		}
			break;

		case DELETE_LINE_T: {
			int del_row;
			cin >> del_row;
			delete_line(matrix, sizes, stack_empties, total_rows, aloced_rows,
					del_row);
		}
			break;

		case JOIN_LINE_T: {
			int row1, row2;
			cin >> row1 >> row2;
			join_line(matrix, sizes, stack_empties, total_rows, aloced_rows,
					row1, row2);
		}
			break;

		case SPLIT_LINE_T: {
			int row, index;
			cin >> row >> index;
			split_line(matrix, sizes, stack_empties, total_rows, aloced_rows,
					row, index, max_alloc);
		}
			break;

		case ADD_VALUE_T: {
			int value, add_to_row;
			cin >> add_to_row >> value;
			add_value(matrix, sizes, total_rows, value, add_to_row);
		}
			break;

		case DELETE_VALUE_T: {
			int value, from_row;
			cin >> value >> from_row;
			delete_value(matrix, sizes, total_rows, value, from_row);
		}
			break;

		case PRINT_ARRAY_T: {
			print_array(matrix, sizes, total_rows, aloced_rows, max_alloc);
		}
			break;

		case SHRINK_ARRAY_T: {
			shrink_array(matrix, sizes, total_rows, aloced_rows, max_alloc);
		}
			break;

		case EXIT_PROGRAM_T:
			exit_program(matrix, sizes, stack_empties, total_rows);
			break;

		default:
			cout << "Unknown request \n";
			break;

		}
		cin >> setw(N) >> option;
	}
}

// ----------------------------------------------------------------------------

void add_line(unsigned int **&matrix, int &total_rows, int &aloced_rows,
		unsigned int *&stack_empties, unsigned int **&sizes, int &max_alloc) {

	unsigned int **temp_matrix;
	unsigned int **temp_sizes;
	if (aloced_rows == total_rows) {
		total_rows *= 2;
		create_array(temp_matrix, total_rows);
		copy_n_del(matrix, temp_matrix);
		create_array(temp_sizes, total_rows);
		copy_n_del(sizes, temp_sizes);
	}
	if (stack_empties[0] == 0)
		add_empty(stack_empties, aloced_rows);

	int find_empty = stack_empties[1];
	if (find_empty > max_alloc)
		max_alloc = find_empty;

	int num;

	cin >> num;
	int curr_row_size = 1;
	create_array(matrix[find_empty], curr_row_size);

	if (sizes[find_empty] == NULL)
		create_array(sizes[find_empty], 2);

	sizes[find_empty][1] = 0;

	for (int curr_cell = 0; num != 0; curr_cell++) {
		if (curr_cell > curr_row_size - 1) {
			add_row_elements(matrix, find_empty, curr_row_size);
			sizes[find_empty][0] = curr_row_size;
		}
		matrix[find_empty][curr_cell] = num;
		sizes[find_empty][1]++;  //one more alloced now
		cin >> num;
	}
	sizes[find_empty][0] = curr_row_size;
}

// ----------------------------------------------------------------------------

void add_row_elements(unsigned int **&matrix_p, int row, int &total_elements) {

	unsigned int *temp_row;
	create_array(temp_row, total_elements * 2);

	for (int i = 0; i < total_elements; i++) // copy the old row data onto new
		temp_row[i] = matrix_p[row][i];

	delete[] matrix_p[row];			//delete old
	matrix_p[row] = temp_row;			// now we points to the new database
	total_elements *= 2;			// update number of elements in the row
}

// ----------------------------------------------------------------------------

void delete_line(unsigned int **&matrix, unsigned int **&sizes,
		unsigned int *&stack, int &total, int &aloced, int del_row) {

	if (del_row >= 0 && del_row < total) {

		delete[] matrix[del_row];
		matrix[del_row] = NULL;

		aloced--;
		sizes[del_row][0] = 0;
		sizes[del_row][1] = 0;
		add_empty(stack, del_row);
	}
}

// ----------------------------------------------------------------------------

void join_line(unsigned int **&matrix, unsigned int **&sizes,
		unsigned int *&stack, int total, int &aloced, int row1, int row2) {

	if ((row1 >= 0 && row1 < total - 1) && (row2 >= 0 && row2 < total - 1)) {

		int size_line = sizes[row2][1];

		for (int i = 0; i < size_line; i++)
			//add all the second row elements to the first one
			add_value(matrix, sizes, total, matrix[row2][i], row1);

		delete_line(matrix, sizes, stack, total, aloced, row2);	//clean line row2
	}
}

// ----------------------------------------------------------------------------

void split_line(unsigned int **&matrix, unsigned int **&sizes,
		unsigned int *&stack, int total, int &aloced, int row_to_split,
		int index, int &max_alloc) {

	if (row_to_split >= 0 && row_to_split < total) {
		int last_cell = sizes[row_to_split][1]; //last alocated cell index
		if (index < last_cell) {
			int row1_size = sizes[row_to_split][0];
			int row1_neto = sizes[row_to_split][1];

			int sum = (int) (log2(
					sizes[row_to_split][0] - sizes[row_to_split][1]) + 1);
			int row2_size = (int) pow(2, sum);

			unsigned int *temp1;
			unsigned int *temp2;
			int curr_col, new_col = 0;

			create_array(temp1, row1_size);
			create_array(temp2, row2_size);

			//remove all the selected row elements
			for (curr_col = 0; curr_col < index; curr_col++)
				temp1[curr_col] = matrix[row_to_split][curr_col];

			curr_col = index;
			while (curr_col < row1_neto) {
				temp2[new_col] = matrix[row_to_split][curr_col];
				curr_col++;
				new_col++;
			}

			if (index == 0)
				delete_line(matrix, sizes, stack, total, aloced, row_to_split);

			else
				delete[] matrix[row_to_split];
			matrix[row_to_split] = temp1;

			int new_place = 0;
			add_new_row(matrix, sizes, stack, temp2, total, aloced, max_alloc,
					new_place);
			sizes[row_to_split][1] = index;
			sizes[new_place][0] = row2_size;
			sizes[new_place][1] = row1_neto - index;
		}
	}
}

// ----------------------------------------------------------------------------

void add_new_row(unsigned int **&matrix, unsigned int **&sizes,
		unsigned int *&stack, unsigned int *&temp2, int total, int &aloced,
		int &max_alloc, int &new_place) {
	unsigned int **temp_matrix;
	unsigned int **temp_sizes;

	if (aloced == total) {
		total *= 2;
		create_array(temp_matrix, total);
		copy_n_del(matrix, temp_matrix);
		create_array(temp_sizes, total);
		copy_n_del(sizes, temp_sizes);
		new_place = max_alloc + 1;
		max_alloc++;

	} else if (stack[0] == 0)			//stack is empty
		add_empty(stack, ++max_alloc);

	new_place = stack[1];

	matrix[new_place] = temp2;
	if (sizes[new_place] == NULL)
		sizes[new_place] = new (nothrow) unsigned int[2];

	aloced++;

}

// ----------------------------------------------------------------------------

void add_value(unsigned int **&matrix, unsigned int **&sizes, int total,
		int value, int add_to_row) {
	if (add_to_row >= 0 && add_to_row < total) {
		int last_cell = sizes[add_to_row][1]; //last allocated cell index
		int row_size = sizes[add_to_row][0];

		if (last_cell == row_size) {
			add_row_elements(matrix, add_to_row, row_size);
			sizes[add_to_row][0] = row_size;
		}
		matrix[add_to_row][last_cell] = value;

		sizes[add_to_row][1]++;			//alloced 1 more

	}
}

// ----------------------------------------------------------------------------

void delete_value(unsigned int **&matrix, unsigned int **&sizes, int total,
		int from_row, unsigned int value) {
	if (from_row >= 0 && from_row < total) {
		int i;
		int aloced = sizes[from_row][1];

		for (i = 0; i < aloced; i++)
			if (matrix[from_row][i] == value)
				break;

		if (i == aloced)
			return;
		//skip until we found

		i++;
		while (i < aloced) {
			matrix[from_row][i - 1] = matrix[from_row][i];
			i++;
		}

		sizes[from_row][1]--;
		if (i == 0) {
			delete[] matrix[from_row];			//clean line
			matrix[from_row] = NULL;
			//add to the empty-line-stack
		}
	}
}

// ----------------------------------------------------------------------------

void print_array(unsigned int **&matrix, unsigned int **&sizes, int total_rows,
		int aloced_rows, int max_alloc) {
	cout << total_rows << " " << aloced_rows << endl;

	for (int i = 0; i <= max_alloc; i++) {
		int row_size = sizes[i][0];
		int aloced = sizes[i][1];

		cout << i << " " << row_size << " " << aloced << " ";
		for (int j = 0; j < aloced; j++)
			cout << matrix[i][j] << "  ";
		cout << endl;
	}
}

// ----------------------------------------------------------------------------

void shrink_array(unsigned int **&matrix, unsigned int **&sizes,
		int &total_rows, int alloc_rows, int &max_alloc) {

	resize_matrix(matrix, sizes, alloc_rows, max_alloc);

	for (int row = 0; row < alloc_rows; row++) {
		resize_arr(matrix[row], sizes[row][1]);
		sizes[row][0] = sizes[row][1];
	}

	total_rows = alloc_rows;
	max_alloc = alloc_rows - 1;
}

// ----------------------------------------------------------------------------

void resize_matrix(unsigned int **&matrix, unsigned int **&sizes,
		int alloc_rows, int max_alloc) {

	unsigned int **temp_matrix;
	unsigned int **temp_sizes;
	create_array(temp_matrix, alloc_rows);
	create_array(temp_sizes, alloc_rows);

	int idex = 0;
	int jdex = 0;
	for (idex = 0; idex <= max_alloc; idex++) {
		if (matrix[idex] != NULL) {
			temp_sizes[jdex] = sizes[idex];
			temp_matrix[jdex] = matrix[idex];
			jdex++;
		}
	}

	delete[] matrix;
	delete[] sizes;
	matrix = temp_matrix;
	sizes = temp_sizes;

}

// ----------------------------------------------------------------------------

void resize_arr(unsigned int *&arr, int aloc_cells) {

	unsigned int *temp;
	create_array(temp, aloc_cells);
	for (int j = 0; j < aloc_cells; j++)
		temp[j] = arr[j];

	delete[] arr;
	arr = temp;
}

// ----------------------------------------------------------------------------

void add_empty(unsigned int *&stack_empties, int row) {

	unsigned int *temp;
	int size = stack_empties[0];
	create_array(temp, size + 2);
	temp[0] = size + 1;
	for (int i = 2; i < size; i++)
		temp[i] = stack_empties[i - 1];

	temp[1] = row;
	delete[] stack_empties;
	stack_empties = temp;
}

// ----------------------------------------------------------------------------

void create_array(unsigned int **&arr, int size) {

	arr = new (std::nothrow) unsigned int*[size + 1];
	if (arr == NULL) {
		cerr << "Cannot allocate memory \n";
		exit(EXIT_FAILURE);
	}
	arr[size] = NULL;
}

// ----------------------------------------------------------------------------

void create_array(unsigned int *&arr, int size) {

	arr = new (std::nothrow) unsigned int[size];
	if (arr == NULL) {
		cerr << "Cannot allocate memory \n";
		exit(EXIT_FAILURE);
	}
}

// ----------------------------------------------------------------------------

void copy_n_del(unsigned int **&arr, unsigned int **&temp) {

	for (int i = 0; arr[i] != NULL; i++)
		temp[i] = arr[i];
	delete[] arr;
	arr = temp;
}

// ----------------------------------------------------------------------------

void exit_program(unsigned int **&matrix, unsigned int **&sizes,
		unsigned int *&stack_empties, int total_rows) {

	free_memory(matrix, total_rows);
	free_memory(sizes, total_rows);
	delete[] stack_empties;
	exit(EXIT_SUCCESS);
}

// ----------------------------------------------------------------------------

void free_memory(unsigned int **arr, int total_rows) {

	for (int i = 0; i < total_rows; i++) {
		if (arr[i] == NULL)
			continue;
		delete[] arr[i];
	}
	delete[] arr;
}
