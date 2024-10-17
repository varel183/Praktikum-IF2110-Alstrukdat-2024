// Varel Tiara
// 13523008
// Proram Pivot

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

int main() {
  ListDin l, maxLeft, minRight;
  CreateListDin(&l, 100000);
  readList(&l);

  CreateListDin(&maxLeft, 100000);
  CreateListDin(&minRight, 100000);

  ELMT(maxLeft, 0) = ELMT(l, 0);
  for (IdxType i = 1; i < listLength(l); i++) {
    ELMT(maxLeft, i) = (ELMT(l, i) > ELMT(maxLeft, i-1)) ? ELMT(l, i) : ELMT(maxLeft, i-1);
  }


  ELMT(minRight, listLength(l)-1) = ELMT(l, listLength(l)-1);
  for (IdxType i = listLength(l)-2; i >= 0; i--) {
    ELMT(minRight, i) = (ELMT(l, i) < ELMT(minRight, i+1)) ? ELMT(l, i) : ELMT(minRight, i+1);
  }


  int count = 0;
  for (IdxType i = 0; i < listLength(l); i++) {
    if (i==0) {
      if (ELMT(minRight, i+1) >= ELMT(l, i)) {
        count++;
      }
    }
    if (i==listLength(l)-1) {
      if (ELMT(maxLeft, i-1) <= ELMT(l, i)) {
        count++;
      }
    }
    if (i != 0 && i != listLength(l)-1) {
      if (ELMT(maxLeft, i-1) <= ELMT(l, i) && ELMT(l, i) <= ELMT(minRight, i+1)) {
        count++;
      }
    }
  }

  printf("%d\n", count);

  return 0;
}