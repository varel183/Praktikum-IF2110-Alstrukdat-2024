// Varel Tiara
// 13523008
// Program Circle

#include "circle.h"
#include <stdio.h>
#include <math.h>

#define PI 3.14

boolean IsCIRCLEValid(float X, float Y, float R) {
/* Mengirim TRUE jika X, Y, R dapat membentuk Lingkaran C yang valid */
  return R > 0;
};


/* *** Konstruktor: Membentuk Lingkaran C dari titik pusat dan radius *** */
void CreateCIRCLE(CIRCLE *C, float X, float Y, float R){
/* Membentuk sebuah CIRCLE dari komponen-komponen yang valid */
/* Prekondisi : X, Y, R, valid */
  if (IsCIRCLEValid(X, Y, R)) {
    CreatePoint(&Center(*C), X, Y);
    Radius(*C) = R;
  };
};


/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void ReadCIRCLE(CIRCLE *C) {
/**
 * I.S. : C tidak terdefinisi
 * F.S. : C terdefinisi dan merupakan CIRCLE yang valid
 * Proses : Mengulangi membaca komponen X, Y, R sehingga membentuk C
 *  - Pembacaan dilakukan dengan mengetikkan komponen X, Y, R dalam
 *    1 baris, dipisah spasi, diakhiri enter.
 *  - Jika CIRCLE tidak valid, maka berikan pesan: "CIRCLE tidak valid"
 *    dengan newline, pembacaan diulangi hingga didapat CIRCLE yang valid.
 */
  float X, Y, R;
  scanf("%f %f %f", &X, &Y, &R);
  while (!IsCIRCLEValid(X, Y, R)) {
    printf("CIRCLE tidak valid\n");
    scanf("%f %f %f", &X, &Y, &R);
  };
  CreateCIRCLE(C, X, Y, R);
};

void WriteCIRCLE(CIRCLE C) {/**
 * I.S. : C sembarang
 * F.S. : Nilai C ditulis dengan format "P(X,Y) r=R", ex: P(1,1) r=5
 * Proses : Penulisan tanpa spasi, enter, atau karakter lain di depan, 
 * belakang, atau di antaranya
 */
  printf("P(%.2f,%.2f) r=%.2f", Absis(Center(C)), Ordinat(Center(C)), Radius(C));
};


/* ***************************************************************** */
/* KELOMPOK OPERASI GEOMETRI TERHADAP TYPE                           */
/* ***************************************************************** */
float Circumference(CIRCLE C) {
/* Menghitung keliling lingkaran: K = 2 * π * r, π = 3.14 */
  return 2 * PI * Radius(C);
};


float Area(CIRCLE C) {
/* Menghitung luas lingkaran: A = π * r^2, π = 3.14 */
  return PI * Radius(C) * Radius(C);
};

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P) {
/* Mengirim true jika titik P berada di dalam lingkaran C */
  return Panjang(Center(C), P) < Radius(C);
};

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P) {
/* Mengirim true jika titik P berada di tepi lingkaran C */
/* HINT: Gunakan toleransi kecil untuk komparasi float */
  float distance = Panjang(Center(C), P);
  return (fabs(distance - Radius(C)) < 1e-6);
};

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2) {
/* Mengirim true jika C1 di dalam C2 atau C2 di dalam C1 */
/* NOTE: Tidak berpotongan/ bersinggungan */
/* d < |R - r| */
  float distance = Panjang(Center(C1), Center(C2));
  return distance < fabs(Radius(C2) - Radius(C1));
};

boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2) {
/* Mengirim true jika C1 bersinggungan di 1 titik dengan C2 */
/**
 * HINT : Terdapat 2 Kemungkinan:
 *  1. Bersinggungan dalam
 *  2. Bersinggungan luar
 */
/*
 * d = R + r
 * d = |R - r|
 */
  float distance = Panjang(Center(C1), Center(C2));
  return fabs(distance - (Radius(C1) + Radius(C2))) < 1e-6 || fabs(distance - fabs(Radius(C1) - Radius(C2))) < 1e-6;
};


boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2) {
/* Mengirim true jika C1 berpotongan di 2 titik dengan C2 */
/* |R - r| < PQ < R + r */
  float distance = Panjang(Center(C1), Center(C2));
  return fabs(Radius(C1) - Radius(C2)) < distance && distance < (Radius(C1) + Radius(C2));
};


/* ***************************************************************** */