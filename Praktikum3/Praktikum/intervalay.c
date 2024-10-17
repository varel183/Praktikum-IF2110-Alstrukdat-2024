// Varel Tiara
// 13523008
// Program Intervalay

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

int main() {
    ListDin intervalay;
    int newStart, newStop;

    CreateListDin(&intervalay, 10000);
    readList(&intervalay);

    scanf("%d %d", &newStart, &newStop);

    ListDin result;
    CreateListDin(&result, listLength(intervalay) + 2); 

    IdxType i = 0;
    while (i <= getLastIdx(intervalay) && ELMT(intervalay, i + 1) < newStart) {
        insertLast(&result, ELMT(intervalay, i));
        insertLast(&result, ELMT(intervalay, i + 1));
        i += 2;
    }

    while (i <= getLastIdx(intervalay) && ELMT(intervalay, i) <= newStop) {
        if (newStart > ELMT(intervalay, i)) {
            newStart = ELMT(intervalay, i);
        }

        if (newStop < ELMT(intervalay, i + 1)) {
            newStop = ELMT(intervalay, i + 1);
        }
        i += 2;
    }

    insertLast(&result, newStart);
    insertLast(&result, newStop);

    while (i <= getLastIdx(intervalay)) {
        insertLast(&result, ELMT(intervalay, i));
        insertLast(&result, ELMT(intervalay, i + 1));
        i += 2;
    }

    printf("%d", ELMT(result, getFirstIdx(result)));
    for (IdxType k = getFirstIdx(result) + 1; k <= getLastIdx(result); k++) {
        printf(" %d", ELMT(result, k));
    }
    printf("\n");
    dealocateList(&intervalay);
    dealocateList(&result);
    return 0;
}