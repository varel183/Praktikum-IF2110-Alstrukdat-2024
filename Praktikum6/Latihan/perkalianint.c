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

    // Mengisi stack S1 dengan bilangan pertama
    for (int i = 0; i < listWords[0].Length; i++) {
        Push(&S1, listWords[0].TabWord[i] - '0');         
    }

    // Mengisi stack S2 dengan bilangan kedua
    for (int i = 0; i < listWords[1].Length; i++) {
        Push(&S2, listWords[1].TabWord[i] - '0');
    }

    // Menyiapkan array untuk hasil sementara perkalian
    int len1 = listWords[0].Length;
    int len2 = listWords[1].Length;
    int resultArray[len1 + len2];
    for (int i = 0; i < len1 + len2; i++) {
        resultArray[i] = 0;
    }

    // Proses perkalian digit demi digit
    // 25 * 132
    // [5, 2] * [2, 3, 1]

    // 1, 0
    for (int i = len1 - 1; i >= 0; i--) {
        int digit1 = listWords[0].TabWord[i] - '0';
        int carry = 0;
        
        // 2, 1, 0
        for (int j = len2 - 1; j >= 0; j--) {
            int digit2 = listWords[1].TabWord[j] - '0';
            int temp = resultArray[i + j + 1] + digit1 * digit2 + carry;
            carry = temp / 10;
            resultArray[i + j + 1] = temp % 10;
        }

        resultArray[i] += carry;
    }

    // Menampilkan hasil perkalian, menghilangkan nol di depan
    boolean leadingZero = true;
    for (int i = 0; i < len1 + len2; i++) {
        if (resultArray[i] != 0) {
            leadingZero = false;
        }
        if (!leadingZero) {
            printf("%d", resultArray[i]);
        }
    }
    if (leadingZero) {
        printf("0");
    }
    
    printf("\n");

    return 0;
}
