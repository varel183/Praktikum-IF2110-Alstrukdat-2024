// Varel Tiara
// 13523008
// Program Maxxing

#include <stdio.h>
#include "prioqueue.h"

int main() {
    int n; 
    scanf("%d", &n);

    PrioQueue chara;
    PrioQueue weap;
    CreatePrioQueue(&chara);
    CreatePrioQueue(&weap); 
    // Tambahkan inisialisasi yang dibutuhkan
    
    for (int i = 0; i < n; i++) {
        int a; 
        scanf("%d", &a);
        enqueue(&chara, a);
        // Tambahkan inisialisasi yang dibutuhkan
    }

    for (int i = 0; i < n; i++) {
        int b; 
        scanf("%d", &b);
        enqueue(&weap, b);
        // Tambahkan inisialisasi yang dibutuhkan
    }

    long long ans = 0;
    // Lanjutkan kode perhitungan disini

    for (int i = 0; i<n; i++) {
        ElType charahead, weaphead;
        dequeue(&chara, &charahead);
        dequeue(&weap, &weaphead);
        ans += (long long)charahead * weaphead;
    }

    printf("%lld\n", ans);
}