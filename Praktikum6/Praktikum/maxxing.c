// Varel Tiara
// 13523008
// Program Maxxing

#include "stack.h"
#include <stdio.h>

int el[MaxEl]; // Array untuk menyimpan elemen
int prev[MaxEl]; // Array untuk menyimpan indeks elemen lebih kecil sebelumnya
int next[MaxEl]; // Array untuk menyimpan indeks elemen lebih kecil selanjutnya
int max[MaxEl]; // Array untuk menyimpan kekuatan maksimal setiap ukuran kelompok

// Fungsi untuk menemukan kekuatan maksimal dari setiap ukuran kelompok
void maxxing(int n) {
    Stack S;
    CreateEmpty(&S);

    // Menghitung elemen lebih kecil sebelumnya untuk setiap elemen dalam el
    for (int i = 0; i < n; i++) {
        while (!IsEmpty(S) && el[InfoTop(S)] >= el[i]) {
            int temp;
            Pop(&S, &temp);
        }
        prev[i] = IsEmpty(S) ? -1 : InfoTop(S);
        Push(&S, i);
    }

    // Reset Stack untuk menghitung elemen lebih kecil selanjutnya
    CreateEmpty(&S);

    // Menghitung elemen lebih kecil selanjutnya untuk setiap elemen dalam el
    for (int i = n - 1; i >= 0; i--) {
        while (!IsEmpty(S) && el[InfoTop(S)] >= el[i]) {
            int temp;
            Pop(&S, &temp);
        }
        next[i] = IsEmpty(S) ? n : InfoTop(S);
        Push(&S, i);
    }

    // Inisialisasi max dengan nol
    for (int i = 0; i < n; i++) {
        max[i] = 0;
    }

    // Menemukan elemen maksimal untuk setiap ukuran kelompok
    for (int i = 0; i < n; i++) {
        int windowSize = next[i] - prev[i] - 1;
        if (max[windowSize - 1] < el[i]) {
            max[windowSize - 1] = el[i];
        }
    }

    // Menjamin nilai maksimum untuk setiap ukuran setidaknya sebesar ukuran di atasnya
    for (int i = n - 2; i >= 0; i--) {
        if (max[i] < max[i + 1]) {
            max[i] = max[i + 1];
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &el[i]);
    }

    maxxing(N);

    for (int i = 0; i < N; i++) {
        printf("%d", max[i]);
        if (i < N - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
