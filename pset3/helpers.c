/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
	if (n < 0) {
		return false;
	}
	else {
		return binary_search(value, values, n);
	}
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
	bubble_sort(values, n);
}

//Search functions

bool linear_search(int value, int values[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (values[i] == value) {
			return true;
		}
	}
	return false;
}

bool binary_search(int value, int values[], int n)
{
	int left = 0;
	int right = n - 1;	

	while (left <= right) {
		int middle = (left + right) / 2;
		
		if (values[middle] == value) {
			return true;
		}
		else if (value < values[middle]) {
			right = middle - 1;
		}
		else
			left = middle + 1;
		}
	return false;
}

//Sort functions

void selection_sort(int values[], int n)
{	
	//loop through the array until sorted
	for (int i = 0; i < n; i++) {
		
		//treats first value as current smallest value in array
		int min = i;

		//loop for comparing two values to find the smaller
		for (int j = i + 1; j < n; j++) {
			
			if (values[min] > values[j]) {
				min = j;
			}
		}
		//swap smaller value with first value of unsorted array
		int swap = values[i];
		values[i] = values[min];
		values[min] = swap;
	}
	return;
}

void bubble_sort(int values[], int n)
{
	int swap_count = 1;
	int swap;

	while (swap_count != 0) {
		swap_count = 0;
		
		for (int m = n; m > 0; --m) {

			for (int i = 0; (i + 1) < m; i++) {

				if (values[i] > values[i + 1]){
					swap = values[i];
					values[i] = values[i + 1];
					values[i + 1] = swap;
					swap_count++;
				}
			}
		}
	}
	return;
}

#define MAX 65536

void counting_sort(int values[], int n)
{
	int count[MAX] = {0};
	int sorted[n];
	int sort_pos = -1;
	
	//look at each value in array
	for (int i = 0; i < n; i++) {

		//for each value, add 1 to that position in counter array 
		count[values[i]]++;
	}
	//look at each value in counter array
	for (int i = 0; i < MAX; i++) {

		//if a value has been counted, i.e value is greater the zero 
		//add the value to the sorted array in the first empty position
		//repeat for the number of times counted
		while (count[i] > 0) {
			sort_pos++;
			sorted[sort_pos] = i;
			count[i]--;
		}
	}
	return;
}