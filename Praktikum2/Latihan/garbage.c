#include <stdio.h>
#include "liststatik.c"

int main() {
  ListStatik l1, l2;
  readList(&l1);
  readList(&l2);

  int i, time;
  insertFirst(&l2, 0);
  for (i=0;i<listLength(l2)-1;i++) {
    ELMT(l2,i+1) += ELMT(l2,i);
  };

  int trux1 = 0, trux2 = 0, trux3 = 0, idx1 = 0, idx2 = 0, idx3 = 0;

  for (i=0;i<listLength(l1);i++) {
    if (ELMT(l1,i) == 0 ){
      continue;
    }
    else if(ELMT(l1,i) == 1) {
      trux1++;
      idx1 = i;
    }
    else if (ELMT(l1,i) == 2) {
      trux2++;
      idx2 = i;
    }
    else if (ELMT(l1,i) == 3) {
      trux3++;
      idx3 = i;
    };
  };

  int time1 = 0, time2 = 0, time3 = 0;
  time1 = trux1 + ELMT(l2,idx1)*2;
  time2 = trux2 + ELMT(l2,idx2)*2;
  time3 = trux3 + ELMT(l2,idx3)*2;

  time = time1 + time2 + time3;

  printf("%d\n", time);

  return 0;  
}