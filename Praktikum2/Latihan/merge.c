#include <stdio.h>
#include "liststatik.c"

int main() {
  ListStatik l1, l2, l3;
  readList(&l1);
  readList(&l2);

  CreateListStatik(&l3);

  int i;
  for (i=0; i<listLength(l1); i++) {
    insertFirst(&l3, ELMT(l1,i));
  };

  for (i=0; i<listLength(l2); i++) {
    insertFirst(&l3, ELMT(l2,i));
  };

  sortList(&l3, true);
  printList(l3);
  return 0;
}