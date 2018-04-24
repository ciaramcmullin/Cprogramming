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

// Implement a C function called level_2_opt. It should perform the same
// task as the implemented level_2 function.
// In the comments for the function describe why your changes make the
// function more cache friendly.


void level_2(data * list, double * sum_d, int * sum_n)
{
    int i;

    for(i = 0; i < LARGER; i++){
        *sum_d += list[i].d;
    }

    for(i = 0; i < LARGER; i++){
        *sum_n += list[i].n1 ;
    }

    for(i = 0; i < LARGER; i++){
        *sum_n += list[i].n2;
    }

}

/** The level_2 function does not have good temporal or spatial locality.
* In each for-loop interation you loop through LARGER amount of times
* and also access sum_d, sum_n, and sum_n again and again. To improve
* temporal locality by completing the sums in only one for loop
* since each some is iterated the same amount of times. You can also
* improve spatial locality for sum_n by adding list[i].n1 and list[i].n2 to
* the sum at the same time, and hence accessing the data sequentially.
**/
void level_2_opt(data * list, double * sum_d, int * sum_n)
{   
    // declare variable
    int i;

    // loop only once through LARGER
    for(i=0; i < LARGER; i++){
        *sum_d += list[i].d; // improve temporal locality for sum_d
        *sum_n += (list[i].n1 + list[i].n2); // improve both temporal and spatial locality for sum_N
    }

}
