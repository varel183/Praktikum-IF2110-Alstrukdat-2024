// Varel Tiara
// 13523008
// Program Hapus Duplikat dan Tampilkan Jumlah Setiap Elemen Pada List

#include <stdio.h>
#include "liststatik.h"

int main() {
    ListStatik l, result, count;
    CreateListStatik(&result);
    CreateListStatik(&count);
    readList(&l);
    int i,j;

    insertLast(&result, ELMT(l,0));
    insertLast(&count, 1);

    for (i=1;i<listLength(l);i++) {
        boolean found = false;
        for (j=0;j<listLength(result);j++) {
            if (ELMT(l,i) == ELMT(result,j)) {
                found = true;
                ELMT(count,j) += 1;
                break;
            };
        };
        if (!found) {
            insertLast(&result, ELMT(l,i));
            insertLast(&count, 1);
        };
    };

    printList(result);
    printf("\n");

    for (i=0;i<listLength(l);i++) {
      if (ELMT(result, i) != MARK) {
        printf("%d %d\n", ELMT(result, i), ELMT(count, i));
      };
    };
    return 0;
}