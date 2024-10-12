#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdin.h"
#include <math.h>

int main() {
  int c,q;
  IdxType i;
  ListDin l;
  scanf("%d", &c);
  scanf("%d", &q);
  CreateListDin(&l, c);
  
  for (i=0;i<q;i++) {
    int tipe;
    scanf("%d", &tipe);
    if (tipe == 1) {
      int x;
      IdxType j;
      scanf("%d", &x);
      for (j=listLength(l)-1;j>=0;j--) {
        if (ELMT(l,j) < x) {
          deleteLast(&l, &ELMT(l,j));
        };
      };
      insertLast(&l,x);
    }
    else {
      printf("%d\n", listLength(l));
      printList(l);
      printf("\n");
    }
  }
  return 0;
}