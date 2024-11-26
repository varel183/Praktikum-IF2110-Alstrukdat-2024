#include "listlinier.c"
#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  List L;
  CreateList(&L);
  float hit = 0;

  int q;
  scanf("%d", &q);

  if (q <= 0) {
    printf("hit ratio: 0.00\n");
    return 0;
  }

  int i,x;
  for (i = 0; i < q; i++) {
    scanf("%d", &x);
    if (isEmpty(L)) {
      insertFirst(&L, x);
      printf("miss "); displayList(L); printf("\n");
    }
    else {
      int val;
      if (indexOf(L, x) == IDX_UNDEF) {
        if (length(L) < N) {
          insertFirst(&L, x);
          printf("miss "); displayList(L); printf("\n");
        }
        else {
          deleteLast(&L, &val);
          insertFirst(&L, x);
          printf("miss "); displayList(L); printf("\n");
        }
      }
      else {
        deleteAt(&L, indexOf(L, x), &val);
        insertFirst(&L, x);
        printf("hit "); displayList(L); printf("\n");
        hit++;
      }
    }
  }

  float ratio = hit / q;
  printf("hit ratio: %.2f\n", ratio);
  return 0;
}