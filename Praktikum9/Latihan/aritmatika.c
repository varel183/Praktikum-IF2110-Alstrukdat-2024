#include "list_circular.c"
#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  List l;
  CreateList(&l);

  for (int i = 0; i < N; i++) {
    int val;
    scanf("%d", &val);
    insertLast(&l, val);
  }

  Address P = FIRST(l);
  int b = INFO(P);
  P = NEXT(P);
  int a = INFO(P) - b;
  Address test = FIRST(l);
  boolean isAritmatika = true;
  for (int i= 1; i<=N;i++) {
    int deret = a*(i-1)+b;
    if (INFO(test) == deret) {
      test = NEXT(test);
    } else {
      isAritmatika = false;
      break;
    }
  }
  if (isAritmatika) {
    printf("%d %d\n", a ,b);
  } else {
    printf("0 0\n");
  }
  return 0;
}