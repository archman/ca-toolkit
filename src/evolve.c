/*
 * evolve.c
 * Purpose: Apply cellular automata rule to the input array
 * return updated one.
 *
 * @author Tong Zhang <zhangt@frib.msu.edu>
 * @date 2018-08-19 21:30:24 EDT
 *
 */

#include "evolve.h"

void print_pattern(int *a, int n, int ncol) {
  for (int i = 0; i < n; i++) {
    if (i != 0 && !(i % ncol)) printf("\n");
    printf("%d ", a[i]);
  }
  printf("\n");
}

int *update_pattern_rule001(int a[], int n, int nrow, int ncol) {
  int *new_a = (int *)malloc(n * sizeof(int));
  int idx_row_low, idx_row_high, idx_col_low, idx_col_high;
  int k;
  int n_neighbors;
  for (int i = 0; i < nrow; i++) {
    for (int j = 0; j < ncol; j++) {
      k = i * ncol + j;
      n_neighbors = -a[k];
      idx_row_low = (i - 1 < 0) ? 0 : (i - 1);
      idx_row_high = (i + 2 > nrow) ? nrow : (i + 2);
      idx_col_low = (j - 1 < 0) ? 0 : (j - 1);
      idx_col_high = (j + 2 > ncol) ? ncol : (j + 2);
      for (int ii = idx_row_low; ii < idx_row_high; ii++)
        for (int jj = idx_col_low; jj < idx_col_high; jj++)
          n_neighbors += a[ii * ncol + jj];
      if (a[k]) {
        if ((n_neighbors < 2) || (n_neighbors > 3)) {
          new_a[k] = 0;
        } else {
          new_a[k] = a[k];
        }
      } else {
        if (n_neighbors == 3) {
          new_a[k] = 1;
        } else {
          new_a[k] = a[k];
        }
      }
    }
  }

  return new_a;
}
