// Varel Tiara
// 13523008
// Proram Pivot

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

int main() {
  ListDin l;
  CreateListDin(&l, 100000);
  readList(&l);
  
  IdxType i,j;
  int count = 0;
  boolean bisa = true;

  for (i=0;i<listLength(l);i++) {
    for (j=0;j<i;j++) {
      if (ELMT(l,i) > ELMT(l,j)) {
        bisa = true;
      }
      else {
        bisa = false;
        break;
      }
    }
    if (bisa) {
      for (j=i+1;j<listLength(l);j++) {
        if (ELMT(l,i) < ELMT(l,j)) {
          bisa = true;
        }
        else {
          bisa = false;
          break;
        }
      }
    }

    if (bisa) {
      count++;
    }
  }

  printf("%d\n", count);

  return 0;
}