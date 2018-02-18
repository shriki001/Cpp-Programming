/*
 * util.h
 *
 *  Created on: Sep 10, 2017
 *      Author: michael
 */

#ifndef UTIL_H_
#define UTIL_H_

void quicksort(void* arr, int from, int to,
		void* (*ptr2cell)(void *, int), bool (*compare)(void *, void *),
		void (*swap)(void *, void *));
int partition(void* arr, int from, int to, void* (*pnt2cell)(void *, int),
		bool (*compare)(void *, void *), void (*swap)(void *, void *));
void print_arr(void* arr, int size, void*(*print_cell)(void *, int),
		void (*print_point)(void*)) ;
void swap_struct_points(void* p1, void *p2);
void swap_struct_rects(void* p1, void *p2);
void print_point_op1(void *arr);
void print_point_op2(void *arr);
void print_rectangle_op1(void *arr);
void print_rectangle_op2(void *arr);

#endif /* UTIL_H_ */
