
#ifndef _PROBLEM3_H_
#define _PROBLEM3_H_

/* If you wish to use different definitions
 * of the following structures, provide new
 * definitions (do not remove  or modify
 * the existing ones). Make sure that any alternative
 * structure definitions are equivalent to the
 * ones below.
 */

typedef struct data_ {
    double d;
    int n1;
    int n2;
} data;



/* DO NOT modify anything below this line */

#define SMALL   64
#define N       1024
#define DIM     512
#define DIM2    1024
#define LARGE   10000
#define LARGER  50000

int level_0( int * B, int x, int y );

int level_0_opt( int * B, int x, int y );

long level_1(long * B, long * A, int x);

long level_1_opt(long * B, long * A, int x);

void level_2();

void level_2_opt();

void level_3 (int *A, int n);

void level_3_opt (int *A, int n);



#endif
