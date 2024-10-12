// Varel Tiara
// 13523008
// Program Kekayaan

#include <stdio.h>
#include "liststatik.h"

int main() {
    ListStatik l;
    readList(&l);

    int i, carry = 0;
    ELMT(l, listLength(l)-1) += 1;
    for (i=listLength(l)-1;i>=0;i--) {
        if (carry == 1) {
            ELMT(l,i) += 1;
            carry -= 1;
        };
        if (ELMT(l,i) < 10) {
            break;
        }
        else {
            carry = ELMT(l,i) / 10;
            ELMT(l,i) %= 10;

        };
    };
    
    if (carry == 1) {
        if (!isFull(l)) {
            insertFirst(&l,carry);
        };
    };

    for (i=0; i<listLength(l);i++) {
        if (i==(listLength(l)-1)) {
            printf("%d", ELMT(l,i));
        }
        else {
            printf("%d ", ELMT(l,i));
        };
    };
    printf("\n");
    return 0;
}