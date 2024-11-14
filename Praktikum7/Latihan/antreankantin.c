#include "queue.c"
#include <stdio.h>

int main() {
  Queue antrian;
  CreateQueue(&antrian);
  int kode;
  scanf("%d", &kode);
  int count = 0;
  int waktu, sum = 0;
  while (kode != 0 && kode > 0 && kode <= 2 ) {
    if (kode == 1) {
      scanf("%d", &waktu);
      if (isFull(antrian)) {
        printf("Queue penuh\n");
      }
      else {
        enqueue(&antrian, waktu);
      }
    }
    else if (kode == 2) {
      if (!isEmpty(antrian)) {
        dequeue(&antrian, &waktu);
        sum += waktu;
        count += 1;
      }
      else {
        printf("Queue kosong\n");
      }
    }
    scanf("%d", &kode);
  }
  if (kode == 0) {
    printf("%d\n", count);
    if (count == 0) {
      printf("Tidak bisa dihitung\n");
    }
    else {
      float avg = (float) sum / (float) count;
      displayQueue(antrian);
      printf("%d\n", sum);
      printf("%.2f\n", avg);
    }
    
  }

}