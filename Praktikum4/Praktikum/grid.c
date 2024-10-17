// Varel Tiara
// 13523008
// Program Grid

#include <stdio.h>
#include "boolean.h"
#include "matrix.h"

const int MOD = 1e9 + 7;

int main() {
    Matrix l,path;
    int n;
    scanf("%d", &n);
    createMatrix(n,n,&l);
    readMatrix(&l,n,n);

    createMatrix(n,n,&path);
    IdxType i,j;
    
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            if (ELMT(l,i,j) == 0) {
                ELMT(l,i,j) = 1;
            }
            else {
                ELMT(l,i,j) = 0;
            } 
        }
    }

    ELMT(path,0,0) = ELMT(l,0,0);

    if (ELMT(path,0,0) == 1) {
        for (i=0; i<n;i++) {
            for (j=0;j<n;j++) {
                if (ELMT(l,i,j) == 1) {
                    if (i>0) {
                        ELMT(path,i,j) += ELMT(path,i-1,j);
                        ELMT(path,i,j) %= MOD;
                    }

                    if (j>0) {
                        ELMT(path,i,j) += ELMT(path,i,j-1);
                        ELMT(path,i,j) %= MOD;
                    }
                }
                
            }
        }
    }
    else {
        ELMT(path,n-1,n-1) = 0;
    }

    printf("%d\n", ELMT(path,n-1,n-1));
    return 0;
}