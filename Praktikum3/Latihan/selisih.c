#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdin.h"
#include <math.h>

int main() {
  ListDin l;
  CreateListDin(&l, 100);
  readList(&l);

  ElType max, min, selisih;
  extremeValues(l, &max, &min);

  max++;

  selisih = max-min;
  printf("%d", selisih);


  return 0;
}