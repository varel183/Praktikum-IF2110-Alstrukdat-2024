// Varel Tiara
// 13523008
// Program Message Queue

#include <stdio.h>
#include "queue.h"

int main() {
    int n;
    scanf("%d", &n);
    Queue q;
    CreateQueue(&q);

    // Lakukan inisialisasi Queue disini
    for (int i = 0; i < n; ++i) {
        int op;
        scanf("%d", &op);

        // Kerjakan keempat tipe query disini
        if (op == 1) {
            ElType x;
            scanf("%d", &x);
            if (isFull(q)) {
                printf("Queue Penuh\n");
            } else {
                enqueue(&q, x);
                printf("Enqueue %d Berhasil\n", x);
            }
    
        } else if (op == 2) {
            if (isEmpty(q)) {
                printf("Queue Kosong\n");
            } else {
                ElType val;
                dequeue(&q, &val);
                printf("Dequeue %d Berhasil\n", val);
            }
        } else if (op == 3) {
            if (isEmpty(q)) {
                printf("Queue Kosong\n");
            } else {
                ElType val = HEAD(q);
                printf("Elemen Awal Queue adalah %d\n", val);
            }
            
        } else if (op == 4) {
            int a = length(q);
            printf("Ukuran Queue saat ini adalah %d\n", a);
        }
    }

    // Display Queue disini
    displayQueue(q);
}