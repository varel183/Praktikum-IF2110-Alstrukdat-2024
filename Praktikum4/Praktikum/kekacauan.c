// Varel Tiara
// 13523008
// Program Kekacauan

#include <stdio.h>
#include "matrix.h"

const int MOD = 1e9 + 7;

int main() {
    Matrix l;
    int n;
    scanf("%d", &n);
    createMatrix(n,n,&l);
    readMatrix(&l,n,n);

    IdxType i,j,k;
    int sum = 0;
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            if (ELMT(l,i,j) != 0) {
                int count = 0;
                for (k=0;k<n;k++) {
                    count += ELMT(l,i,k);
                    count += ELMT(l,k,j);
                }
                count -= 2*ELMT(l,i,j);
                sum += count;
                sum = sum % MOD;
            }
        }
    }
    
    printf("%d\n", sum);
    return 0;
}