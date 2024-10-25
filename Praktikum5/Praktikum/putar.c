// Varel Tiara
// 13523008
// Program Putar

#include <stdio.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"

int main() {
    int j = 1;
    int i;
    boolean addSpace = false;
    IgnoreBlanks();
    STARTWORD();
    while (!EndWord) {
        if (j%2 != 0) {
            if (addSpace) {
                printf(" ");
            }

            for (i = currentWord.Length - 1; i >= 0; i--) {
                printf("%c", currentWord.TabWord[i]);
            }
            
            addSpace = true;
        }
        else {
            if (addSpace) {
                printf(" ");
            }

            for (i = 0; i < currentWord.Length; i++) {
                printf("%c", currentWord.TabWord[i]);
            }
            
            addSpace = true;
        }
        j++;
        ADVWORD();
    }
    printf("\n");

    return 0;
}