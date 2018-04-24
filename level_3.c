/*
 * author: Ciara McMullin
 * 04/17/18
 * a program that contains two functions: one that is optimized, in terms of cache performace, and one that is not
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "problem3.h"

// Implement a C function called level_3_opt. It should perform the same
// task as the implemented level_3 function.
// In the comments for the function describe why your changes make the
// function more cache friendly.
// Note that this function does not return any value. It modifies the array
// that is passed to it, instead.

void level_3 (int *A, int n)
{
    int  i, j;
    for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
        A[j*n + i] = A[j*n + i] || A[i*n + j];

}
/**

* This function performs the same task as level_3, but it has fewer cache misses
 * because it reduces the stride and improve the spatial locality by
 * switching the inner and outter loops. Instead of looping through i first,
 * it loops though j first and therefore accesses the data that are closer to each
 * other. Thus, it takes advantage of spatial locality.
 **/
void level_3_opt (int *A, int n)
{
	// declare variables
	int i, j, k;


	// loop through the row first to make function more cache-friendly
	for (j=0; j < n; j++){
		for(i=0; i< n; i++){
			// assign values
			 A[j*n + i] = A[j*n + i] || A[i*n + j];
		}
}


}
