// Varel Tiara
// 13523008
// Proram Barisan

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

int main() {
    ListDin l;
    CreateListDin(&l, 100);
    readList(&l);

    IdxType i,j;
    int count = 0;
    for (i=0;i<listLength(l);i++) {
        for (j=0;j<i;j++) {
          if (ELMT(l,i) < ELMT(l,j)) {
            count++;
          }
        }
    }

    printf("%d\n", count);
    return 0;
}