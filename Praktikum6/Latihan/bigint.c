#include <stdio.h>
#include "mesinkata.c"
#include "mesinkarakter.c"
#include "stack.c"

Word listWords[100];
int countWord = 0;

int main() {
    START();
    while (currentChar != MARK) {
        ADVWORD();
        listWords[countWord] = currentWord;
        countWord++;
    }
    
    Stack S1, S2, result;
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    CreateEmpty(&result);

    // 25
    // [5, 2]
    for (int i = 0; i < listWords[0].Length; i++) {
        Push(&S1, listWords[0].TabWord[i] - '0');         
    }

    // 132
    // [2, 3, 1]
    for (int i = 0; i < listWords[1].Length; i++) {
        Push(&S2, listWords[0].TabWord[i] - '0');
    }

    int carry = 0;

    while (!IsEmpty(S1) || !IsEmpty(S2)) {
        int digit1 = 0;
        int digit2 = 0;

        if (!IsEmpty(S1)) {
            Pop(&S1, &digit1);
        }

        if (!IsEmpty(S2)) {
            Pop(&S2, &digit2);
        }

        int substraction = digit1 - digit2 - carry;
        if (substraction < 0) {
            substraction += 10;
            carry = 1;
        } else {
            carry = 0;
        }

        Push(&result, substraction);
    }

    boolean isZero = true;

    while (!IsEmpty(result)) {
        int digit;
        Pop(&result, &digit);
        if (digit != 0) {
            isZero = false;
        }

        if (!isZero) {
            printf("%d", digit);
        }

    }

    if (isZero) {
        printf("0");
    }

    printf("\n");

    return 0;
}