// Varel Tiara
// 13523008
// Program Tambah

#include "listlinier.h"
#include <stdio.h>

int main() {
    List l1, l2;
    CreateList(&l1);
    CreateList(&l2);

    int x;

    // Masukkan bilangan pertama ke dalam list l1
    scanf("%d", &x);
    while (x != -1) {
        insertLast(&l1, x);
        scanf("%d", &x);
    }

    // Masukkan bilangan kedua ke dalam list l2
    scanf("%d", &x);
    while (x != -1) {
        insertLast(&l2, x);
        scanf("%d", &x);
    }

    List l3;
    CreateList(&l3);

    int carry = 0; // Menyimpan carry dari penjumlahan digit
    while (!isEmpty(l1) || !isEmpty(l2) || carry != 0) {
        int dig1 = 0, dig2 = 0;

        // Ambil digit terakhir dari l1 jika ada
        if (!isEmpty(l1)) {
            deleteLast(&l1, &dig1);
        }

        // Ambil digit terakhir dari l2 jika ada
        if (!isEmpty(l2)) {
            deleteLast(&l2, &dig2);
        }

        // Jumlahkan kedua digit dan carry
        int sum = dig1 + dig2 + carry;
        insertFirst(&l3, sum % 10); // Sisakan digit terakhir di l3
        carry = sum / 10;          // Simpan carry
    }

    // Cetak hasil penjumlahan dari list l3
    while (!isEmpty(l3)) {
        int temp;
        deleteFirst(&l3, &temp);
        printf("%d", temp);
        if (!isEmpty(l3)) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
