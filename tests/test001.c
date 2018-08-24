/**
 * test001.c
 * Purpose: Test program for applying rule 001.
 *
 * @author Tong Zhang <zhangt@frib.msu.edu>
 * @date 2018-08-22 22:49:47 EDT
 */

#include "evolve.h"

int main(int argc, char **argv) {
  int n = 9, ncol = 3, nrow = 3;
  int a[9] = {1,0,1,0,1,0,0,0,1};

//  int n = 250000, ncol = 500, nrow = 500;
//  int a[250000] = {0};
//  for (int i = 125000; i < 126000; i++)
//    a[i] = 1;

  int *new_a = update_pattern_rule001(a, n, nrow, ncol);

  printf("Original pattern:\n");
  print_pattern(a, n, ncol);
  printf("Updated pattern:\n");
  print_pattern(new_a, n, ncol);

  free(new_a);
  return 0;
}
