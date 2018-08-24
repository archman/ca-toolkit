#ifndef EVOLVE_H_
#define EVOLVE_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Print out the pattern from input array.
 *
 * @param a
 * @param n
 * @param ncol
 * @return void
 */
void print_pattern(int *a, int n, int ncol);

/**
 * Update pattern by applying rule 001.
 *
 * @param a
 * @param n
 * @param nrow
 * @param ncol
 * @return 
 */
int *update_pattern_rule001(int a[], int n, int nrow, int ncol);


#endif // EVOLVE_H_
