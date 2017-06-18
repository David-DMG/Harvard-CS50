/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 *
 * Note: Multiple Search and Sort functions have been provided		 
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

/**
 * Search Functions
 */


/**
 * Linear Search
 *
 * O(n), Ω(1)
 *
 * Linear Search looks at each element of an array until it finds its target element
 * or until it reaches the end of the array
 */

bool linear_search(int value, int values[], int n)
{
	// Loop through array checking each element until target element is found
	for (int i = 0; i < n; i++)
	{
		if (values[i] == value) {
			return true;
		}
	}
	return false;
}

/**
 * Binary Search
 *
 * O(logn), Ω(1)
 *
 * Binaary Search looks through a sorted array by repeatedly dividing the search interval in half.
 * If the target element is less than the item in the middle of the interval,
 * narrow the interval to the lower half. Otherwise narrow it to the upper half.
 * Repeatedly check until the element is found or the interval is empty.
 */

bool binary_search(int value, int values[], int n)
{
	int left = 0;
	int right = n - 1;	

	// Repeatedly check until the element is found or the interval is empty
	while (left <= right) {
		int middle = (left + right) / 2;
		
		// If the target element is present at the middle itself
		if (values[middle] == value) {
			return true;
		}
		// If element is smaller than mid, it must be present in left half of array
		else if (value < values[middle]) {
			right = middle - 1;
		}
		 // Else the element must be present in right half of array
		else
			left = middle + 1;
		}
	return false;
}

/**
 * Sort Functions
 */


/**
 * Selection Sort
 *
 * O(n^2), Ω(n^2)
 *
 * Selection sort works by repeatedly finding the minimum element of an array
 * of unsorted parts and putting that element at the beginning.
 */

void selection_sort(int values[], int n)
{	
	// Loop through the array until sorted
	for (int i = 0; i < n; i++) {
		
		// Treating first value as current smallest value in array
		int min = i;

		// Loop for comparing two values to find the smaller,
		// if smaller, treating that value as smallest in array
		for (int j = i + 1; j < n; j++) {
			
			if (values[min] > values[j]) {
				min = j;
			}
		}
		// Swap smaller value with first value of unsorted array
		int swap = values[i];
		values[i] = values[min];
		values[min] = swap;
	}
	return;
}

/**
 * Bubble Sort
 *
 * O(n^2), Ω(n)
 *
 * Bubble Sort works by repeatedly swapping the adjacent elements if they are in wrong order. 
 * Which allows for the largest numbers to be 'bubbled' to the last position of the array.
 */

void bubble_sort(int values[], int n)
{
	int swap_count = 1;
	int swap;

	// Loop if the swap count isn't zero
	while (swap_count != 0) {
		
		// Set swap count to zero
		swap_count = 0;
		
		// Repeat the swap loop until it has sorted all values in array and
		// Ignoring the values already 'bubbled' to the top
		for (int m = n; m > 0; --m) {

			// Loop to swap adjacent values
			for (int i = 0; (i + 1) < m; i++) {

				// If i value is greater then i + 1 value
				// swap them and + 1 to swap counter
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


/**
 * Counting Sort
 *
 * O(n), *Ω(n)
 *
 * Counting Sort works by using a second array to count the number of objects having distinct values,
 * then uses that second array to populate and output a final sorted array.
 *
 * Note: With this code, the final array will contain duplicate values,
 * if duplicate values were present in the input array.
 */

#define MAX 65536

void counting_sort(int values[], int n)
{
	int count[MAX] = {0};
	int sorted[n];
	int sort_pos = -1;
	
	// Look at each value in array
	for (int i = 0; i < n; i++) {

		// For each value, add 1 to that position in counter array 
		count[values[i]]++;
	}
	// Look at each value in counter array
	for (int i = 0; i < MAX; i++) {

		// If a value has been counted, i.e value is greater the zero 
		// add the value to the sorted array in the first empty position
		// repeat for the number of times counted
		while (count[i] > 0) {
			sort_pos++;
			sorted[sort_pos] = i;
			count[i]--;
		}
	}
	return;
}