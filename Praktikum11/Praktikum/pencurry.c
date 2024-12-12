// Varel Tiara
// 13523008
// Program Pencurry

#include "bintree.h"
#include <stdio.h>

int mencurry(BinTree T) {
    if (isTreeEmpty(T)) {
        return 0;
    }
    int coba1 = ROOT(T);

    if (LEFT(T) != NULL) {
        coba1 += mencurry(LEFT(LEFT(T))) + mencurry(RIGHT(LEFT(T)));
    }
    if (RIGHT(T) != NULL) {
        coba1 += mencurry(LEFT(RIGHT(T))) + mencurry(RIGHT(RIGHT(T)));
    }

    int coba2 = mencurry(LEFT(T)) + mencurry(RIGHT(T));

    if (coba1 >= coba2) {
        return coba1;
    } else {
        return coba2;
    }
}

