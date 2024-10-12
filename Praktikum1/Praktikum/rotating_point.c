// Varel Tiara
// 13523008
// Program Rotating Point

#include "rotating_point.h"
#include <stdio.h>

/* Catatan: Hasil perkalian float dan int adalah float*/

/* Fungsi untuk menghitung perpangkatan bilangan kompleks */
/* Formula: Bilangan kompleks dikalikan dirinya sendiri sebanyak P kali */
COMPLEX PowerCOMPLEX(COMPLEX C, int p){
  COMPLEX result;
  if (p == 0) {
    CreateComplex(&result, 1.0, 0.0);
    return result;
  } 

  CreateComplex(&result, Real(C), Imag(C));
  for(int i = 2; i <= p; ++i){
    result = MultiplyCOMPLEX(result, C);
  }
  return result;

}

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n) {
  if (n == 0){
    printf("Titik keluar dari lingkaran pada iterasi ke 0");
    return;
  };

  for (int i = 1; i<=n;i++) {
    COMPLEX pC = PowerCOMPLEX(C,i);    
    float x = Absis(*P);
    float y = Ordinat(*P);
        
    Absis(*P) = x *  Real(pC) - y * Imag(pC);
    Ordinat(*P) = x *  Imag(pC) + y * Real(pC);
    if(Absis(*P)* Absis(*P) + Ordinat(*P)*Ordinat(*P) > 1){
      printf("Titik keluar dari lingkaran pada iterasi ke %d", i);
      break;
    };
  };

  if (Absis(*P)* Absis(*P) + Ordinat(*P)*Ordinat(*P) <= 1){
    printf("Titik tetap berada di dalam lingkaran setelah %d iterasi", n);
  };
};