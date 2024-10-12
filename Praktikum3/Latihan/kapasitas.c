#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdin.h"
#include <math.h>

int main() {
  ListDin l;
  CreateListDin(&l, 0);

  int i,q;
  scanf("%d", &q);
  for (i=0;i<q;i++) {
    int tipe;
    scanf("%d", &tipe);
    if (tipe == 1) {
      int x;
      scanf("%d", &x);
      if (CAPACITY(l) == 0) {
        CAPACITY(l) += 1;
        insertLast(&l, x);
      }
      else if (CAPACITY(l) == listLength(l)) {
        CAPACITY(l) *= 2;
        insertLast(&l,x);
      }
      else {
        insertLast(&l,x);
      };

    }
    else if (tipe == 2) {
      deleteLast(&l, &ELMT(l, getLastIdx(l)));
      if (NEFF(l) <= CAPACITY(l)/2) {
        CAPACITY(l) /= 2;
      };

    }
    else {
      printf("%d", CAPACITY(l));
      printList(l);
      printf("\n");
    }
  }
  return 0;
}