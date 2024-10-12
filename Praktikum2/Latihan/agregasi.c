#include <stdio.h>
#include "liststatik.c"

int main() {
  ListStatik l;

  readList(&l);
  int x;
  scanf("%d", &x);

  sortList(&l, true);
  printList(l);
  printf("\n");
  float average=0, sum = 0;
  int i;
  for (i=0;i<listLength(l);i++){
    sum += ELMT(l,i);
  };

  average = sum/listLength(l);
  printf("%.2f", average);
  printf("\n");

  ElType max,min;
  extremeValues(l,&max,&min);
  if(indexOf(l,x) != IDX_UNDEF){
    printf("%d\n",indexOf(l,x));
    if(x == max)
        {
            printf("X maksimum\n");
        }
        if(x == min)
        {
            printf("X minimum\n");
        }
        // median
        int idxmed = getLastIdx(l)/2;
        if(x == ELMT(l,idxmed))
        {
            printf("X median\n");
        }
    }

    else
    {
        printf("%d tidak ada\n",x);
    }
  return 0;
}