#include <stdio.h>
#include "liststatik.c"

int main() {
  ListStatik l1, l2, result;

  readList(&l1);
  readList(&l2);
  CreateListStatik(&result);

  int max_length, i;
  int carry = 0;
  max_length = listLength(l1) >= listLength(l2) ? listLength(l1) : listLength(l2);

  for (i=1; i<=max_length;i++) {
    int digit1 = 0, digit2 = 0, sum = 0;
    if (isIdxEff(l1, listLength(l1) - i)) {
      digit1 = ELMT(l1, listLength(l1) - i);
    };
    if (isIdxEff(l2, listLength(l2) - i)) {
      digit2 = ELMT(l2, listLength(l2) - i);
    };

    sum = digit1 + digit2 + carry;
    carry = sum / 10;

    insertFirst(&result, sum%10);
  };
  if (carry > 0) {
    insertFirst(&result, carry);
  };
  printList(result);
  printf("\n");
  
  
}