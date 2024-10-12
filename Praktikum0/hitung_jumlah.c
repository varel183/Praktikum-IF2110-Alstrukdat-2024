// Program Hitung Jumlah
// Varel Tiara
// 13523008

#include <stdio.h>

int main() {
  int n, k, a_i, i, sum=0;
  scanf("%d %d", &n, &k);
  if ( n >= 1 & k >= 1 & n<= 1000 & k<= 1000) {
    for (i=0; i<n; i++) {
      scanf("%d", &a_i);
      if (a_i >= 1 & a_i <= 10000) {
        if (a_i%k!=0) {
          sum += a_i;
        }
      } 
    }
    printf("%d\n", sum);
  }
  
  return 0;

}