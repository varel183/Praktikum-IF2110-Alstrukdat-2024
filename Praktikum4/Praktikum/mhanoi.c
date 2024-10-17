// Varel Tiara
// 13523008
// Proram Hanoi

#include <stdio.h>
#include "boolean.h"
#include "matrix.h"

boolean canPlaceRotated(Matrix papan, int i, int j, Matrix gab) {
    Matrix temp;
    createMatrix(2, 2, &temp);

    ELMT(temp, 0, 0) = ELMT(papan, i, j);
    ELMT(temp, 0, 1) = ELMT(papan, i, j + 1);
    ELMT(temp, 1, 1) = ELMT(papan, i + 1, j + 1);
    ELMT(temp, 1, 0) = ELMT(papan, i + 1, j);

    for (int rotation = 0; rotation < 4; rotation++) {
        boolean canPlace = true;
        for (int r = 0; r < 2; r++) {
            for (int c = 0; c < 2; c++) {
                if (ELMT(temp, r, c) <= ELMT(gab, r, c)) {
                    canPlace = false;
                    break;
                }
            }
            if (!canPlace) break;
        }
        if (canPlace) return true;

        int tmp = ELMT(gab, 0, 0);
        ELMT(gab, 0, 0) = ELMT(gab, 1, 0);
        ELMT(gab, 1, 0) = ELMT(gab, 1, 1);
        ELMT(gab, 1, 1) = ELMT(gab, 0, 1);
        ELMT(gab, 0, 1) = tmp;
    }

    return false;
}

int main() {
    Matrix papan, gab;
    int n;
    
    scanf("%d", &n);
    createMatrix(n, n, &papan);
    readMatrix(&papan, n, n);

    createMatrix(2, 2, &gab);
    readMatrix(&gab, 2, 2);

    int count = 0;
    for (int i = 0; i <= n - 2; i++) {
        for (int j = 0; j <= n - 2; j++) {
            if (canPlaceRotated(papan, i, j, gab)) {
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}