// Varel Tiara
// 13523008
// Program ADT Priority Queue

#include "prioqueue.h"
#include <stdio.h>

/* *** Kreator *** */
void CreatePrioQueue(PrioQueue *pq) {
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
};
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */

/* ********* Prototype ********* */
boolean isEmpty(PrioQueue pq) {
    return (IDX_HEAD(pq) == IDX_UNDEF) && (IDX_TAIL(pq) == IDX_UNDEF);
};
/* Mengirim true jika pq kosong: lihat definisi di atas */
boolean isFull(PrioQueue pq) {
    return (IDX_HEAD(pq) == 0 && IDX_TAIL(pq) == CAPACITY - 1) || (IDX_TAIL(pq) == (IDX_HEAD(pq) - 1) % (CAPACITY - 1));
};
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(PrioQueue pq) {
    if (isEmpty(pq)) {
        return 0;
    } else {
        return (IDX_TAIL(pq) - IDX_HEAD(pq) + CAPACITY) % CAPACITY + 1;
    }
};
/* Mengirimkan banyaknya elemen prioqueue. Mengirimkan 0 jika pq kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(PrioQueue *pq, ElType val) {
    int idx;
    int i, j;
    ElType temp;

    if (isEmpty(*pq)) {
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
        TAIL(*pq) = val;
    }
    else {
        IDX_TAIL(*pq) = IDX_TAIL(*pq) == CAPACITY - 1 ? 0 : IDX_TAIL(*pq) + 1;
        TAIL(*pq) = val;
        i = IDX_TAIL(*pq);
        j = i == 0 ? CAPACITY - 1 : i - 1;
        while (i != IDX_HEAD(*pq) && pq->buffer[i] > pq->buffer[j]) {
            temp = pq->buffer[i];
            pq->buffer[i] = pq->buffer[j];
            pq->buffer[j] = temp;
            i = j;
            j = i == 0 ? CAPACITY - 1 : i - 1;
        }
    }
};
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val disisipkan pada posisi yang sesuai, IDX_TAIL "mundur" dalam buffer melingkar.,
        pq terurut mengecil */

void dequeue(PrioQueue *pq, ElType *val) {
    *val = HEAD(*pq);
    if (IDX_HEAD(*pq) == IDX_TAIL(*pq)) {
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    }
    else {
        IDX_HEAD(*pq) = IDX_HEAD(*pq) == CAPACITY - 1 ? 0 : IDX_HEAD(*pq) + 1;
    }
};
/* Proses: Menghapus val pada pq dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        pq mungkin kosong */

/* *** Display Queue *** */
void displayPrioQueue(PrioQueue pq) {
    int i;
    if (isEmpty(pq)) {
        printf("[]\n");
    } else {
        printf("[");
        for (i = IDX_HEAD(pq); i != IDX_TAIL(pq); i = (i + 1) % CAPACITY) {
        printf("%d,", pq.buffer[i]);
        }
        printf("%d]\n", pq.buffer[IDX_TAIL(pq)]);
    }
};
/* Proses : Menuliskan isi PrioQueue dengan traversal, PrioQueue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. pq boleh kosong */
/* F.S. Jika pq tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 30, 20, 1 akan dicetak: [30,20,1] */
/* Jika Queue kosong : menulis [] */

// int main() {
//     PrioQueue pq;
//     CreatePrioQueue(&pq);
//     int n;
//     scanf("%d", &n);
//     for (int i=0;i<n;i++) {
//         int val;
//         scanf("%d", &val);
//         enqueue(&pq, val);
//     }
//     displayPrioQueue(pq);
//     printf("\n");
//     return 0;
// }