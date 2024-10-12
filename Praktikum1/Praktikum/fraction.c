// Varel Tiara
// 13523008
// Program Fraction

#include "fraction.h"
#include <stdio.h>

int GCD(int a, int b) {
    return (b == 0) ? a : GCD(b, a % b);
}

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsFRACTIONValid(int N, int D) {
/* Mengirim TRUE jika pecahan valid */
  return D != 0;
};

/* *** Konstruktor: Membentuk FRACTION F dari komponen-komponennya *** */
void CreateFRACTION(FRACTION *F, int N, int R) {
/* Membentuk sebuah FRACTION yang valid */
/* Prekondisi : N, R valid */
  Numerator(*F) = N;
  Denominator(*F) = R;
};

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void ReadFRACTION(FRACTION *F) {
/**
 * I.S. : F tidak terdefinisi
 * F.S. : F terdefinisi dan merupakan FRACTION yang valid
 * Proses : Mengulangi membaca komponen N, R sehingga membentuk F
 *  - Pembacaan dilakukan dengan mengetikkan komponen N, R dalam
 *    1 baris, dipisah spasi, diakhiri enter.
 *  - Jika FRACTION tidak valid, maka berikan pesan: "FRACTION tidak valid"
 *    dengan newline, pembacaan diulangi hingga didapat FRACTION yang valid.
 */
  int N, D;
  scanf("%d %d", &N, &D);
  while (!IsFRACTIONValid(N, D)) {
    printf("FRACTION tidak valid\n");
    scanf("%d %d", &N, &D);
  };
  CreateFRACTION(F, N, D);
};


void WriteFRACTION(FRACTION F) {
/**
 * I.S. : F sembarang
 * F.S. : Nilai F ditulis dengan format "N/R"
 * Proses : Penulisan tanpa spasi, enter, atau karakter lain di depan, 
 * belakang, atau di antaranya
 * NOTE : hasil dalam bentuk paling sederhana
 */
  FRACTION simplified = SimplifyFRACTION(F);
  printf("%d/%d", Numerator(simplified), Denominator(simplified));
};


/* ***************************************************************** */
/* KELOMPOK OPERASI DASAR TERHADAP TYPE                              */
/* ***************************************************************** */
/* NOTE: untuk hasil FRACTION = 0, maka kembalikan 0/1 */

FRACTION AddFRACTION(FRACTION F1, FRACTION F2) {
/* Mengirim hasil penjumlahan F1 + F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
  FRACTION result;
  result.N = Numerator(F1) * Denominator(F2) + Numerator(F2) * Denominator(F1);
  result.D = Denominator(F1) * Denominator(F2);
  return SimplifyFRACTION(result);
};


FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2) {
/* Mengirim hasil pengurangan F1 - F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
  FRACTION result;
  result.N = Numerator(F1) * Denominator(F2) - Numerator(F2) * Denominator(F1);
  result.D = Denominator(F1) * Denominator(F2);
  return SimplifyFRACTION(result);
};

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2) {
/* Mengirim hasil perkalian F1 * F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
  FRACTION result;
  result.N = Numerator(F1) * Numerator(F2);
  result.D = Denominator(F1) * Denominator(F2);
  return SimplifyFRACTION(result);
};

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2) {
/* Mengirim hasil pembagian F1 / F2 */ 
/* Prekondisi: F2 tidak nol */
/* NOTE: hasil dalam bentuk paling sederhana */
  FRACTION result;
  result.N = Numerator(F1) * Denominator(F2);
  result.D = Denominator(F1) * Numerator(F2);
  return SimplifyFRACTION(result);
};


FRACTION MultiplyNumberFRACTION(int n, FRACTION F1) {
/* Mengirim hasil perkalian n * F1 */
/* NOTE: hasil dalam bentuk paling sederhana */
  FRACTION result;
  result.N = n * Numerator(F1);
  result.D = Denominator(F1);
  return SimplifyFRACTION(result);
};

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
FRACTION SimplifyFRACTION(FRACTION F) {
/* Mengembalikan FRACTION dalam bentuk sederhana */
/* NOTE: pastikan hanya numerator yang memiliki nilai negatif */
  if (Numerator(F) == 0) {
    CreateFRACTION(&F, 0, 1); 
    return F;
  };

  int gcd = GCD(Numerator(F), Denominator(F));
    FRACTION result;
    result.N = Numerator(F) / gcd;
    result.D = Denominator(F) / gcd;
    if (result.D < 0) {
        result.N = -result.N;
        result.D = -result.D;
    }
    return result;
};

float ToDecimal(FRACTION F) {
  /* Mengonversi FRACTION ke bentuk desimal */
  return 1.0 * Numerator(F) / Denominator(F);
};