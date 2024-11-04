#include "stack.c"
#include <stdio.h>


int lenStack(Stack s) {
  int count = 0;
  int temp;

  if (IsEmpty(s)) {
    return 0;
  } 
  while (!IsEmpty(s)) {
    Pop(&s, &temp);
    count++;
  }
  return count;
}

void SortirKeranjang(Stack *S1, Stack *S2) {
  CreateEmpty(S2);
  int lengthS1 = lenStack(*S1);
  int temp[lengthS1];
  int i, val;
  // 23 92 98 31 3 34
  for (i = 0; i < lengthS1; i++) {
    Pop(S1, &val);
    // temp = [23, 92, 98, 31, 3, 34]
    temp[i] = val;
  }

  for (i = 0; i < lengthS1; i++) {
    for (int j = i+1; j < lengthS1; j++) {
      if (temp[i] > temp[j]) {
        int tempVal = temp[i];
        temp[i] = temp[j];
        temp[j] = tempVal;
      }
    }
    // temp = [3, 92, 98, 31, 23, 34]
    // temp = [3, 23, 98, 31, 92, 34]
    // temp = [3, 23, 31, 98, 92, 34]
    // temp = [3, 23, 31, 34, 92, 98]
    // temp = [3, 23, 31, 34, 92, 98]
  }
  

  for (i = 0; i < lengthS1; i++) {
    Push(S2, temp[i]);
  }
  // S2 = [98, 92, 34, 31, 23, 3]

  // for (i = lengthS1 - 1; i >= 0; i--) {
  //   Push(S2, temp[i]);
  // }
  // // S2 = [3, 23, 31, 34, 92, 98]
}

int main() {
  Stack S1, S2;
  CreateEmpty(&S1);
  CreateEmpty(&S2);

  int N;
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    int val;
    scanf("%d", &val);
    Push(&S1, val);
  }

  SortirKeranjang(&S1, &S2);

  while (!IsEmpty(S2)) {
    int val;
    Pop(&S2, &val);
    printf("%d ", val);
  }

  return 0;
}