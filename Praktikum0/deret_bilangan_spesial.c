// Program deret bilangan biasa
// Varel Tiara
// 13523008

#include <stdio.h>
#include <stdbool.h>

int main() {
  int a, b, curr;
  scanf("%d %d", &a, &b);

  curr = a;
  printf("%d", curr);

  while (true) {
    if (curr%2 == 0) {
      curr *= 2;
    } else {
      curr += 1;
    };
    
    if (curr > b) {
      break;
    };

    printf(" %d", curr);
  };
  printf("\n");
  return 0;
};