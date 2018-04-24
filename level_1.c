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

// Implement a C function called level_1_opt. It should perform the same
// task as the implemented level_1 function.
// In the comments for the function describe why your changes make the
// function more cache friendly.
//
// Note: your function needs to compute the entire matrix C,
// not only its x entry.

long level_1(long * B, long * A, int x)
{
    long * C = (long * ) malloc (N*N*sizeof(long) );
    if (!C) return 0;

    int c, r;

    for(c = 0; c < N; c++)
        for(r = 0; r < N; r++)
            C[ r*N + c ] = B[ r*N + c ] + A[ c*N + r ] ;
          //  printf("%ld\n",C[ r*N + c]);

    long ret = C[x];
    free (C); C = 0;
    return ret;
}


/*
 * This function performs the same task as level_1, but it has fewer cache misses
 * because it reduces the stride and improve the spatial locality by
 * switching the inner and outter loops. Instead of looping through c first,
 * it loops though r first and therefore accesses the data that are closer to each
 * other.
*/

long level_1_opt(long * B, long * A, int x)
{
    // DO NOT modify the following declarations
    long * C = (long * ) malloc (N*N*sizeof(long) );
    if (!C) return 0;

    // declare variables
    int c, r;

    // switch from c to r to r to c in order to reduce stride
    for(r = 0; r < N; r++) {
        for(c = 0; c < N; c++) { 
            // add value to C[r*N+c]
            C[r*N+c] += (B[r*N + c] + A[c*N + r]);
    } 
  }


    //DO NOT modify the rest of this function
    long ret = C[x];
    free (C); C = 0;
    return ret;
}
