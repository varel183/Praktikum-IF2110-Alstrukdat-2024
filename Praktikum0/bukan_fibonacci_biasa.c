// Program Bukan Fibonacci Biasa
// Varel Tiara
// 13523008

#include <stdio.h>

int main() {
    int n, a, b, fib = 0;
    scanf("%d %d %d" , &n, &a, &b);
    int i = 3;
    fib = a + b;
    while (i<n) {
      a = b;
      b = fib;
      fib = a + b;
      i++;
    }

    printf("%d\n", fib);
    return 0;
}