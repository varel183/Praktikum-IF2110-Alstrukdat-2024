#include <stdio.h>
#include "matrix.c"

int main() {
  Matrix catur;
  createMatrix(8,8,&catur);
  readMatrix(&catur,8,8);
  int i,j;
  int hitam = 0, putih = 0;
  for (i=0;i<getLastIdxRow(catur)+1;i++) {
    for (j=0;j<getLastIdxCol(catur)+1;j++) {
      if ((i+j)%2 == 0) {
        hitam += ELMT(catur,i,j);
      }
      else {
        putih += ELMT(catur,i,j);
      }
    }
  }
  printf("%d %d\n", hitam, putih);
  return 0;
}

