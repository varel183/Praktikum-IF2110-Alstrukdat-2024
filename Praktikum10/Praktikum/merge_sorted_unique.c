// Varel Tiara
// 13523008
// Program Merge Sort Unique

#include <stdio.h>
#include "listrec.h"

void mergeSortedUnique(List l1, List l2, List *res) {
    if (isEmpty(l1) && isEmpty(l2)) {
        *res = NIL;
    } else if (isEmpty(l1)) {
        mergeSortedUnique(l1, tail(l2), res);
        if (isEmpty(*res) || head(l2) != head(*res)) {
            *res = konso(*res, head(l2));
        }
    } else if (isEmpty(l2)) {
        mergeSortedUnique(tail(l1), l2, res);
        if (isEmpty(*res) || head(l1) != head(*res)) {
            *res = konso(*res, head(l1));
        }
    } else {
        if (head(l1) < head(l2)) {
            mergeSortedUnique(tail(l1), l2, res);
            if (isEmpty(*res) || head(l1) != head(*res)) {
                *res = konso(*res, head(l1));
            }
        } else if (head(l1) > head(l2)) {
            mergeSortedUnique(l1, tail(l2), res);
            if (isEmpty(*res) || head(l2) != head(*res)) {
                *res = konso(*res, head(l2));
            }
        } else {
            mergeSortedUnique(tail(l1), tail(l2), res);
            if (isEmpty(*res) || head(l1) != head(*res)) {
                *res = konso(*res, head(l1));
            }
        }
    }
}