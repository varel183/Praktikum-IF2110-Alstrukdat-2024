// Varel Tiara
// 13523008
// Proram Barisan

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

int main() {
    ListDin l,siswa;
    CreateListDin(&l, 1000);
    CreateListDin(&siswa, 1000);
    readList(&l);

    IdxType i,j;
    int count = 0;
    for (i=0;i<listLength(l);i++) {
        insertLast(&siswa, ELMT(l,i));
        for (j=getFirstIdx(siswa);j<getLastIdx(siswa);j++) {
          if (ELMT(siswa,j) > ELMT(siswa,getLastIdx(siswa))) {
            count++;
          }
        }
    }

    printf("%d\n", count);

    dealocateList(&l);
    dealocateList(&siswa);
    return 0;
}