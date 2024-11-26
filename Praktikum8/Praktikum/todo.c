// Varel Tiara
// 13523008
// Program Todo

#include "listlinier.h"
#include <stdio.h>

int main() {
    List l;
    CreateList(&l);
    char x;
    scanf("%c",&x);
    int num;
    while (x != 'X') {
        if (x == 'P') {
            scanf("%d", &num);
            insertFirst(&l, num);
        }
        else if (x == 'I') {
            scanf("%d", &num);
            insertLast(&l, num);
        }
        else if (x == 'C') {
            if (!isEmpty(l)) {
                ElType val;
                deleteFirst(&l, &val);
            }
        }
        else if (x == 'D') {
            scanf("%d", &num);
            int idx = indexOf(l, num);
            if (idx != IDX_UNDEF) {
                ElType val;
                deleteAt(&l, idx, &val);
            }
        }
        scanf("%c",&x);
    }

    displayList(l);
    return 0;
}