/*
 * author: Ciara McMullin
 * 04/17/18
 * a program that contains two functions: one that is optimized, in terms of cache performace, and one that is not
 *
 */

#include <stdlib.h>
#include <stdio.h>

#include "problem3.h"


// Implement a C function called level_0_opt. It should perform the same
// task as the implemented level_0 function.
// In the comments for the function describe why your changes make the
// function more cache friendly.

// Note: this is a warmup level. It will not be graded.

int level_0( int * B, int x, int y )
{
    if (!B) return -1;

    int c, r;

    for(c = 0; c < N; c++)
        for(r = 0; r < N; r++)
            B[ r*N + c ] = 2*(B[ r*N + c ] + 2);


    return  B[ x*N + y ];
}

/*
 * The orginal function does not take advantage of the
 * fact that the arrays are stored in memory using the row-major
 * order. Changing the order of the two loops, ensures that
 * the array elements are accessed using stride-1, instead of
 * strige-N patern in the original function.
 */
int level_0_opt( int * B, int x, int y )
{
	if (!B) return -1;

    int c, r;

	for(r = 0; r < N; r++)
		for(c = 0; c < N; c++)
            B[ r*N + c ] = 2*(B[ r*N + c ] + 2);


    return  B[ x*N + y ];
}
