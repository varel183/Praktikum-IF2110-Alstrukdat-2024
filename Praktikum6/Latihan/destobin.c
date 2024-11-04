#include <stdio.h>
#include "stack.h"

void decimalToBinary(int decimal) {
    Stack stack;
    CreateEmpty(&stack);
    if (decimal == 0) {
        Push(&stack, 0); // Jika desimal 0, simpan 0 dalam stack
    } else {
        while (decimal > 0) {
            Push(&stack, decimal % 2); // Simpan sisa bagi 2 ke dalam stack
            decimal /= 2; // Bagikan desimal dengan 2
        }
    }

    printf("Biner: ");
    while (!IsEmpty(stack)) {
        infotype bit;
        Pop(&stack, &bit); // Ambil elemen teratas dari stack
        printf("%d", bit); // Cetak bit biner
    }
    printf("\n");
}

int main() {
    int decimal;
    printf("Masukkan angka desimal: ");
    scanf("%d", &decimal);

    decimalToBinary(decimal); // Panggil fungsi konversi

    return 0;
}
