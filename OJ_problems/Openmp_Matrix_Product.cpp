#include <omp.h>
#include <cstdio>

void process(double **a, double **b, double **c, int i) {
  for(int j=0;j<1024;j++)
    for(int k=0;k<1024;k++)
      c[i][j] += a[i][k]*b[k][j];
}

void matrix_mult(double **a, double **b, double **c) {

  omp_set_num_threads(4);

  /* do I need to modify some storage attributes here? shared, private etc? */
  #pragma omp parallel
  {  
    for(int i=0;i<1024;i++) {

      #pragma omp task
      {
        process(a,b,c,i);
      }
    }
  }
}