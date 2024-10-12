// Program Segitiga Terbalik
// Varel Tiara
// 13523008

#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int i, j, k;
  for (i=0; i<n; i++) {
    for (k=1; k<=i; k++) {
      printf(" ");
    }
    for (j=0; j<2*n-i-k; j++) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}