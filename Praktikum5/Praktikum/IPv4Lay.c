// Varel Tiara
// 13523008
// Program IPv4Lay

#include <stdio.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"

int wordToInt(Word word) {
    int num = 0;
    for (int i = 0; i < word.Length; i++) {
        if (word.TabWord[i] < '0' || word.TabWord[i] > '9') {
            return -1; 
        }
        num = num * 10 + (word.TabWord[i] - '0');
    }
    return num;
}

boolean isValidIPv4Lay(Word word) {
    int octetCount = 0;
    int startIdx = 0;
    int octetValue;
    
    for (int i = 0; i <= word.Length; i++) {
        if (i == word.Length || word.TabWord[i] == '@') {
            if (startIdx == i) {
                return false;
            }

            Word octet;
            octet.Length = 0;

            for (int j = startIdx; j < i; j++) {
                octet.TabWord[octet.Length++] = word.TabWord[j];
            }

            octetValue = wordToInt(octet);
            if (octetValue < 0 || octetValue > 255 || (octet.Length > 1 && octet.TabWord[0] == '0')) {
                return false;
            }

            octetCount++;
            startIdx = i + 1;
        }
    }

    return octetCount == 4; 
}


int main() {
    boolean addSpace = false;
    IgnoreBlanks();
    STARTWORD();

    while (!EndWord) {
        if (addSpace) {
            printf(" ");
        }

        if (isValidIPv4Lay(currentWord)) {
            printf("4Lay");
        } else {
            printf("ewh");
        }

        addSpace = true;
        ADVWORD();
    }

    printf("\n");
    return 0;
}
