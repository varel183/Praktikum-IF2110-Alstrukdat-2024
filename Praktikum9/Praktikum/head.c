// Varel Tiara
// 13523008
// Program Head

#include "list_circular.h"
#include <stdio.h>

int main() {
    List l;
    CreateList(&l);

    int N;
    scanf("%d", &N);
    
    int i;
    for (i=0; i<N;i++) {
        int val;
        scanf("%d", &val);
        insertLast(&l, val);
    }

    Address P = FIRST(l);
    int max = INFO(P);

    for (i=0; i<N;i++)  {
        if (max < INFO(NEXT(P))) {
            max = INFO(NEXT(P));
        }
        P = NEXT(P);
    }

    Address maxaddr = search(l, max);

    FIRST(l) = maxaddr;
    displayList(l);

    return 0; 
}