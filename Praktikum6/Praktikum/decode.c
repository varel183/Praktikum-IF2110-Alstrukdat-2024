// Varel Tiara
// 13523008
// Program Decode

#include <stdio.h>
#include "stack.h"

// Fungsi untuk mendapatkan nilai angka dari karakter
int getNum(char c) {
    int num = (c) - '0';
    if (num < 0 || num > 9) {
        return -1; // Jika bukan digit
    }
    return num;
}

int main() {
    int N;
    char ch;
    Stack S;
    CreateEmpty(&S);

    // Membaca panjang string
    scanf("%d\n", &N);

    // Membaca input dan memproses string
    for (int i = 0; i < N; i++) {
        scanf("%c", &ch);
        Push(&S, ch);

        // Jika menemukan tanda ']', proses pengkodean
        if (ch == ']') {
            Pop(&S, &ch); // out ]
            Pop(&S, &ch); // take first char
            char revStr[10000];
            int maxIdx = 0;
            for(int i=0; i < 10000; i++) {
                if (ch == '[') {
                    revStr[i] = '\0';
                    maxIdx = i-1;
                    break;
                } else if (IsEmpty(S)) {
                    revStr[i] = '\0';
                    maxIdx = i-1;
                    break;
                } else {
                    revStr[i] = ch;
                    Pop(&S, &ch);
                }
            }
            char str[10000];
            int strIdx = 0;
            for (int i = maxIdx; i >= 0; i--) {
                str[strIdx] = revStr[i];
                strIdx++;
            }
            str[maxIdx+1] = '\0';

            // Kumpulkan semua digit ke array terlebih dahulu
            char digits[10];
            int digitCount = 0;
            while (!IsEmpty(S) && getNum(InfoTop(S)) != -1) {
                Pop(&S, &digits[digitCount]);
                digitCount++;
            }

            // Hitung nilai repetisi
            int rep = 0;
            for (int i = digitCount - 1; i >= 0; i--) {
                rep = rep * 10 + getNum(digits[i]);
            }

            // Push kembali string yang diulang
            for (int r = 0; r < rep; r++) {
                for (int j = 0; str[j] != '\0'; j++) {
                    Push(&S, str[j]);
                }
            }
        }
        
    }



    for(int i=0;i<S.TOP+1;i++){
        printf("%c", S.T[i]);
    }

    printf("\n");
    return 0;
}
