// Varel Tiara
// 13523008
// Program BabyCrypt

#include <stdio.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"

int main() {
    Word temp;
    int i;

    STARTWORD();
    int shift = 0;
    for (i = 0; i < currentWord.Length; i++) {
        shift = shift * 10 + (currentWord.TabWord[i] - '0');
    }
    shift %= 26; 
    ADVWORD();

    while (!EndWord) {
        int len = currentWord.Length;
        temp.Length = len;
        
        for (i = 0; i < len; i++) {
            char ch = currentWord.TabWord[i];
            
 
            if (ch >= 'A' && ch <= 'Z') {
                temp.TabWord[i] = ((ch - 'A' - shift + 26) % 26) + 'A';
            } else if (ch >= 'a' && ch <= 'z') {
                temp.TabWord[i] = ((ch - 'a' - shift + 26) % 26) + 'a';
            } else {
                temp.TabWord[i] = ch; 
            }
            printf("%c", temp.TabWord[i]);
        }

        ADVWORD();
        if (!EndWord) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
