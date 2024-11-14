#include "queue.c"
#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  int arr[N];
  for (int i=0;i<N;i++) {
    scanf("%d", &arr[i]);
  }
  int K;
  scanf("%d", &K);
  Queue q;
  CreateQueue(&q);
  for (int i=0;i<N-K+1;i++) {
    int max = arr[i];
    for (int j=i;j<i+K;j++) {
      if (arr[j] > max) {
        max = arr[j];
      }
    }
    enqueue(&q, max);
  }
  displayQueue(q);
  return 0;
}