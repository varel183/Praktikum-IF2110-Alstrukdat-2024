// Varel Tiara
// 13523008
// Program Kurung

#include "stack.h"
#include <stdio.h>

// Fungsi untuk memeriksa apakah pasangan kurung cocok
int isMatching(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

int main() {
    int N;
    scanf("%d", &N);

    Stack S;
    CreateEmpty(&S);

    int isValid = 1; // Gunakan 1 untuk true dan 0 untuk false

    // Membaca karakter kurung satu per satu
    for (int i = 0; i < N; i++) {
        char c;
        scanf(" %c", &c); // Spasi sebelum %c untuk mengabaikan newline sebelumnya

        if (c == '(' || c == '[' || c == '{') {
            // Push semua kurung buka ke stack
            Push(&S, c);
        } else if (c == ')' || c == ']' || c == '}') {
            // Jika menemukan kurung tutup, periksa apakah ada pasangan yang cocok di stack
            if (IsEmpty(S)) {
                isValid = 0;  // Stack kosong tetapi ada kurung tutup
                break;
            } else {
                int top;  // Ubah variabel top menjadi int agar sesuai dengan infotype
                Pop(&S, &top);
                if (!isMatching(top, c)) {
                    isValid = 0;  // Kurung buka dan kurung tutup tidak cocok
                    break;
                }
            }
        }
    }

    // Setelah iterasi, jika stack masih berisi elemen, urutan tidak valid
    if (!IsEmpty(S)) {
        isValid = 0;
    }

    // Output hasil
    if (isValid) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }

    return 0;
}
