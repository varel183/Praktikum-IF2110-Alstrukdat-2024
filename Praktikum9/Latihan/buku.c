#include "list_circular.c"
#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  List l;
  CreateList(&l);

  for (int i = 0; i < N; i++) {
    insertLast(&l, i+1);
  }

  Address currPlayer = FIRST(l);
  while (NEXT(currPlayer) != FIRST(l)) {
    currPlayer = NEXT(currPlayer);
  }
  Address leftCurrPlayer = currPlayer;
  currPlayer = NEXT(leftCurrPlayer);

  int i = 0;
  int step;
  scanf("%d", &step);
  while (i < N-1) {
    while (step < 0) {
      step += N - i;
    }

    for (int j = 0; j < step; j++) {
      currPlayer = NEXT(currPlayer);
      leftCurrPlayer = NEXT(leftCurrPlayer);
    }

    NEXT(leftCurrPlayer) = NEXT(currPlayer);
    Address temp = currPlayer;
    currPlayer = NEXT(currPlayer);
    deallocate(temp);

    if (i < N-2) {
      scanf("%d", &step);
      if (step > 0) {
        step--;
      }
    }
    i++;
  }
  printf("%d\n", INFO(currPlayer));
  return 0;
}