#include <stdio.h>
#include "matrix.c"

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  createMatrix(N, M, &puzzle);
  readMatrix(&puzzle, N, M);

  int K;
  scanf("%d", &K);

  int i,j,k;
  for (k=0;i<K;k++) {
    int A, B;
    scanf("%d %d", &A, &B);
    createMatrix(A, B, &matriks);
    readMatrix(&matriks, A, B);

    
  }
  return 0;
}