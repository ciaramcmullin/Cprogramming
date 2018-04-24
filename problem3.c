/*
 * Problem 3:
 * This program calls each of the functions that you implement
 * for this problem. It runs the original function and your
 * optimized function.
 * The program performs very basic evaluation of correctness
 * (but you should make sure on your own that your function is
 * equivalent to the one that is given to you).
 *
 * author: Joanna Klukowska
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "problem3.h"

/////////////////////////////////////////////
//                                         //
// DO NOT MODIFY anything in this file.    //
//                                         //
/////////////////////////////////////////////

int list[LARGER];

void flood_cache () ;

/***********************************************/

int main(int argc, char *argv[])
{

    int i, j, level = -1 ;
    int b, n1, n2;
    int x,y;
    double d1, d2;
    long l1, l2;

    srand(time(0));
    srand48(time(0));

/* level 0 - this is a warmup exercise - it will not be graded*/
    int * B1 = (int * ) malloc ( N*N*sizeof(int) ) ;
    if (!B1) return -1;
    int * B2 = (int * ) malloc ( N*N*sizeof(int) ) ;
    if (!B2) return -1;
    for (i = 0; i < N*N; i++) {
        b = rand();
        B1[i] = b;
        B2[i] = b;
    }
    flood_cache();
    x =  rand()%N;
    y =  rand()%N;

    n1 = level_0(B1, x, y);

    printf("level_0 completed \n" ) ;

    n2 = level_0_opt(B2, x, y);

    printf("level_0_opt completed  \n" ) ;

    if (n1==n2)    printf("\tlevel_0_opt PASSED\n");
    else printf("\tlevel_0_opt FAILED\n");

    if ( B1!= 0 ) { free(B1); B1 = 0; }
    if ( B2!= 0 ) { free(B2); B2 = 0; }


/* level 1 */

    long * F1 = (long * ) malloc( N*N*sizeof(long) ) ;
    if (!F1) return 0;
    long * F2 = (long * ) malloc (N*N*sizeof(long) );
    if (!F2) return 0;

    for (i = 0; i < N*N; i++) {
        F1[i] =  rand();
        F2[i] =  rand();
    }
    x =  rand()%(N*N);

    flood_cache();
    l1 = level_1(F1, F2, x);

    printf("level_1 completed \n" ) ;

    //attempt to overwrite the memory locations that were used
    //by the original list
    long * stuff = (long*) calloc(LARGER,  sizeof(long) );
    if (stuff == 0 ) return 0;
    else free (stuff);

    flood_cache();
    l2 = level_1_opt(F1, F2, x);

    printf("level_1_opt completed  \n") ;

    if (l1==l2)    printf("\tlevel_1_opt PASSED\n");
    else printf("\tlevel_1_opt FAILED\n");

    if (F1 != 0 ){  free (F1); F1=0; }
    if (F2 != 0 ){  free (F2); F2=0; }

/* level 2 */
    data* list1 = (data*) malloc(sizeof(data) * LARGER);
    data* list2 = (data*) malloc(sizeof(data) * LARGER);
    for (i = 0; i < LARGER; i++)  {
        data s = { drand48(),rand(), rand() } ; 
        list1[i] = s;
        list2[i] = s;
    }
    flood_cache();
    double sum_d = 0;
    int sum_n = 0;
    level_2(list1, &sum_d, &sum_n );
    printf("level_2 completed \n" ) ;


    flood_cache();
    double sum_d_opt = 0;
    int sum_n_opt = 0;
    level_2_opt(list2, &sum_d_opt, &sum_n_opt );
    printf("level_2_opt completed \n" ) ;

    if (sum_d == sum_d_opt && sum_n == sum_n_opt)
        printf("\tlevel_2_opt PASSED\n");
    else printf("\tlevel_2_opt FAILED\n");

    if (list1 != 0 ) { free (list1); list1 = 0; }
    if (list2 != 0 ) { free (list2); list2 = 0; }

/* level 3 */

    x = N*N;
    int * F = (int * ) malloc( x*sizeof(int) ) ;
    if (!F) return 0;
    for (i = 0; i < x; i++){
        F[i] =   rand()%2;
    }

    int * F_opt = (int * ) malloc( x*sizeof(int) ) ;
    if (!F_opt) return 0;
    for (i = 0; i < x; i++){
        F_opt[i] =   F[i];
    }


    flood_cache();
    level_3(F, N);

    printf("level_3 completed \n" ) ;

    flood_cache();
    level_3_opt(F_opt, N);

    printf("level_3 completed  \n") ;

    int level3_passed = 1;
    for (i = 0; i < x; i++){
        if (F[i] != F_opt[i]) {
            level3_passed = 0;
            break;
        }
    }

    if (level3_passed)    printf("\tlevel_3_opt PASSED\n");
    else printf("\tlevel_3_opt FAILED\n");

    if (F != 0 ){  free (F); F=0; }
    if (F_opt != 0 ){  free (F_opt); F_opt=0; }


}

// Perform an operation that will replace the cache content
// forcing the function to start with an "empty" cache.
void flood_cache () {
    int i = 0;

    for ( i =0; i < LARGER; i++ ){
        list[i] = rand();
    }
}
