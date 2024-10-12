#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdin.h"
#include <math.h>

int main() {
  ListDin l1,l2, l3;
  CreateListDin(&l1, 100000);
  CreateListDin(&l2, 100000);
  CreateListDin(&l3, 100000);

  readList(&l1);
  readList(&l2);
  readList(&l3);

  int i=0;

  while (!isEmpty(l1) || !isEmpty(l2)) {
    if (ELMT(l1,i) >= ELMT(l2,i)) {
      insertLast(&l3, ELMT(l1,i));
      i++
    }
  }
  return 0;
}