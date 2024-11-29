// Varel Tiara
// 13523008
// Program Bis Danville

#include "list_circular.h"
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    List l;
    CreateList(&l);

    for (int i = 0; i<n;i++) {
        int val;
        scanf("%d", &val);
        insertLast(&l, val);
    }

    Address P = search(l, n);

    boolean isClockwise, isCounter;

    if (INFO(NEXT(P)) + 1 == INFO(NEXT(NEXT(P)))) {
        isClockwise = true;
        isCounter = false;
    } else if (INFO(NEXT(P)) == INFO(P) - 1) {
        isCounter = true;
        isClockwise = false;
    } else {
        isClockwise = false;
        isCounter = false;
    }

    boolean isBaris = true;
    if (!isCounter && isClockwise) {
        for (int i = 0; i<n;i++) {
            if (INFO(NEXT(P)) == INFO(P)+1) {
                P = NEXT(P);
            } else if (INFO(P) == n) {
                if (INFO(NEXT(P)) == n-(n-1)) {
                    P = NEXT(P);
                }
                else {
                    isBaris = false;
                    break;
                }
            }
            else {
                isBaris = false;
                break;
            }

        }
    }

    if (isCounter && !isClockwise) {
        for (int i = 0; i<n;i++) {
            if (INFO(NEXT(P)) == INFO(P)-1) {
                P = NEXT(P);
            } else if (INFO(P) == 1) {
                if (INFO(NEXT(P)) == n) {
                    P = NEXT(P);
                }
                else {
                    isBaris = false;
                    break;
                }
            }
            else {
                isBaris = false;
                break;
            }

        }
    }

    if (!isCounter && !isClockwise) {
        isBaris = false;
    }
    
    if (n == 1) {
        isBaris = true;
    }

    if (isBaris) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }

    return 0;
}