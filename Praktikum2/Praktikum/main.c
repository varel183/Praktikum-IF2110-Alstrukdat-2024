// Varel Tiara
// 13523008
// Program Elemen Kedua Terbanyak

#include <stdio.h>
#include "liststatik.h"

int main() {
    ListStatik l, uniqueList, freqList;
    int i, j, uniqueCount = 0;

    readList(&l);
    CreateListStatik(&uniqueList);
    CreateListStatik(&freqList);

    for (i = 0; i < listLength(l); i++) {
        ElType elemen = ELMT(l, i);
        int found = 0;
        for (j = 0; j < uniqueCount; j++) {
            if (elemen == ELMT(uniqueList, j)) {
                ELMT(freqList, j)++;
                found = 1;
                break;
            }
        }
        if (!found) {
            if (uniqueCount < CAPACITY) {
                ELMT(uniqueList, uniqueCount) = elemen;
                ELMT(freqList, uniqueCount) = 1;
                uniqueCount++;
            }
        }
    }

    int maxFreq = 0, secondMaxFreq = 0;
    for (i = 0; i < uniqueCount; i++) {
        if (ELMT(freqList, i) > maxFreq) {
            secondMaxFreq = maxFreq;
            maxFreq = ELMT(freqList, i);
        } else if (ELMT(freqList, i) > secondMaxFreq && ELMT(freqList, i) < maxFreq) {
            secondMaxFreq = ELMT(freqList, i);
        }
    }

    if (secondMaxFreq == 0) {
        printf("Tidak ada elemen kedua yang paling sering muncul\n");
    } else {
        int result = -1;
        for (i = 0; i < uniqueCount; i++) {
            if (ELMT(freqList, i) == secondMaxFreq) {
                if (result == -1 || ELMT(uniqueList, i) < result) {
                    result = ELMT(uniqueList, i);
                }
            }
        }
        printf("%d\n", result);
    }

    return 0;
}
