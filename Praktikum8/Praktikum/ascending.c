// Varel Tiara
// 13523008
// Program Ascending

#include "listlinier.h"
#include <stdio.h>

void splitl(List l, List* l1, List* l2) {
    int len = length(l);
    if (len % 2 == 1) {
        len += 1;
    }


    int mid = len / 2;
    *l1 = l;
    *l2 = NULL;

    if (len > 1) {
        int i;
        Address P = l;
        for (i = 0; i < mid - 1; i++) {
            P = NEXT(P);
        }
        *l2 = NEXT(P);
        NEXT(P) = NULL;
    }
}

List merge(List l1, List l2) {
    List l = NULL;
    Address P1 = l1, P2 = l2;
    while (P1 != NULL && P2 != NULL) {
        if (INFO(P1) <= INFO(P2)) {
            l = concat(l, newNode(INFO(P1)));
            P1 = NEXT(P1);
        } else {
            l = concat(l, newNode(INFO(P2)));
            P2 = NEXT(P2);
        }
    } while (P1 != NULL) {
        l = concat(l, newNode(INFO(P1)));
        P1 = NEXT(P1);
    } while (P2 != NULL) {
        l = concat(l, newNode(INFO(P2)));
        P2 = NEXT(P2);
    }
    return l;
}

void mergee(List *l) {
    if (isEmpty(*l) || NEXT(*l) == NULL) {
        return;
    }
    else {
        List l1, l2;
        splitl(*l, &l1, &l2);
        mergee(&l1);
        mergee(&l2);
        *l = merge(l1, l2);
    }
}

int main() {
    List l;
    CreateList(&l);
    int x;
    scanf("%d",&x);
    while (x != -9999) {
        insertLast(&l, x);
        scanf("%d",&x);
    }

    if (isEmpty(l)) {
        displayList(l);
        return 0;
    }
    else {
        mergee(&l);
        displayList(l);
        return 0;
    }
}

