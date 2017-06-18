/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    //printe usage format and return 1 to end program if 1 or 2 additional command line arguments are not entered
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // get int ascii value from first additional command line argument for 'n'
    int n = atoi(argv[1]);

    //If given a second additional command line argument use its long ascii value in the srand48 function to seed drand48,
    //If no second additional command line argument is supplied use the current time in the srand48 function to seed drand48.

    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    else
    {
        srand48((long) time(NULL));
    }

    //print n times, the upper limit multipled by a nonnegative double-precision floating-point value between 0.0 and 1.0 determined by drand48. 
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
