// Varel Tiara
// 13523008

#include "listdin.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity) {
      BUFFER(*l) = (ElType *) malloc(capacity * sizeof(ElType));
      CAPACITY(*l) = capacity;
      NEFF(*l) = 0;
};
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateList(ListDin *l) {
      if (BUFFER(*l) != NULL) {
            free(BUFFER(*l));
            CAPACITY(*l) = 0;
            NEFF(*l) = 0;
      }
};
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l) {
      return NEFF(l);
};
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l) {
      return IDX_MIN;
};
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListDin l) {
      if (NEFF(l) > 0) {
            return NEFF(l) - 1;
      } else {
            return IDX_UNDEF;
      }

};
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i) {
      return (i >= IDX_MIN && i < CAPACITY(l));
};
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListDin l, IdxType i) {
      return (i >= IDX_MIN && i < NEFF(l));
};
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l) {
      return (NEFF(l) == 0);
};
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDin l) {
      return (NEFF(l) == CAPACITY(l));
};
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l) {
      int n, i;
      scanf("%d", &n);
      while (n < 0 || n > CAPACITY(*l)){
            scanf("%d", &n);
      };
      NEFF(*l) = n;
      if (n != 0){
            for (i=0; i<n; i++){
            scanf("%d", &ELMT(*l, i));
            };
      };
};
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void printList(ListDin l) {
      int i, len;
      len = listLength(l);
      printf("[");
      if (len != 0){
            for (i = 0; i < len-1; i++){
                  printf("%i,", ELMT(l, i));
            }
            printf("%i", ELMT(l, len-1));
      }
      printf("]");
      
};
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
      ListDin result;

      CreateListDin(&result, CAPACITY(l1));

      for (IdxType i = 0; i < NEFF(l1); i++) {
            if (plus) {
                  ELMT(result,i) = ELMT(l1, i) + ELMT(l2, i);
            }
            else {
                  ELMT(result,i) = ELMT(l1, i) - ELMT(l2, i);
            };
      };

      NEFF(result) = NEFF(l1);

      return result;
};
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2) {
      if (NEFF(l1) != NEFF(l2)) {
            return false;
      };
      for (IdxType i = 0; i < NEFF(l1); i++) {
            if (ELMT(l1,i) != ELMT(l2,i)){
                  return false;
            };
      };

      return true;
};
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val) {
      for (IdxType i = 0; i < NEFF(l); i++) {
            if (val == ELMT(l,i)) {
                  return i;
            };
      };
      
      return IDX_UNDEF;
};
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min) {
      if (listLength(l)>0) {
            *max = ELMT(l,0);
            *min = ELMT(l,0);

            for (IdxType i = 1; i<listLength(l); i++) {
                  if (ELMT(l,i) > *max) {
                        *max = ELMT(l,i);
                  };
                  if (ELMT(l,i) < *min) {
                        *min = ELMT(l,i);
                  };
            };
      };
};
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut) {
      dealocateList(lOut);
      CreateListDin(lOut, CAPACITY(lIn));
      NEFF(*lOut) = NEFF(lIn);

      for (IdxType i=0; i<listLength(lIn); i++) {
            ELMT(*lOut,i) = ELMT(lIn,i); 
      };
};
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
ElType sumList(ListDin l) {
      ElType sum = 0;
      for (IdxType i=0; i<listLength(l); i++) {
            sum += ELMT(l,i);
      };

      return sum;
};
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val) {
      int count = 0;
      for (IdxType i=0; i<listLength(l); i++) {
            if (ELMT(l,i) == val) {
                  count++;
            };
      };

      return count;
};
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc) {
      IdxType i, j;
      ElType temp;
      if (asc) {
            for (i=0; i<listLength(*l)-1; i++){
                  for (j=i+1; j<listLength(*l);j++){
                        if (ELMT(*l,i) > ELMT(*l,j)){
                              temp = ELMT(*l,i);
                              ELMT(*l,i) = ELMT(*l,j);
                              ELMT(*l, j) = temp;
                        };
                  };
            };
      }
      else {
            for(i=0; i<listLength(*l)-1; i++){
                  for(j=i+1; j<listLength(*l);j++){
                        if (ELMT(*l,i) < ELMT(*l,j)){
                              temp = ELMT(*l,i);
                              ELMT(*l,i) = ELMT(*l,j);
                              ELMT(*l, j) = temp;
                        };
                  };
            };
      };
};
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val) {
      if (NEFF(*l) < CAPACITY(*l)) {
            ELMT(*l, getLastIdx(*l)+1) = val;
            NEFF(*l)++;
      };
};
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val) {
      if (!isEmpty(*l)) {
            *val = ELMT(*l, getLastIdx(*l));
            NEFF(*l)--;
      };
};
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num) {
      ListDin new;
      int newNEFF;
      IdxType i;

      CreateListDin(&new, CAPACITY(*l));
      copyList(*l,&new);
      newNEFF = NEFF(*l);
      dealocateList(l);
      CreateListDin(l, CAPACITY(new)+num);
      NEFF(*l) = newNEFF;

      for(i=0; i<listLength(new); i++){
            ELMT(*l,i) = ELMT(new,i);
      }
};
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num) {
      ListDin new;
      int newNEFF;
      IdxType i;

      CreateListDin(&new, CAPACITY(*l));
      copyList(*l,&new);
      newNEFF = NEFF(*l);
      CreateListDin(l, CAPACITY(new)-num);
      NEFF(*l) = newNEFF;

      if(CAPACITY(new) - num < NEFF(*l)){
            NEFF(*l) = CAPACITY(new) - num;
      }

      for(i=0; i<listLength(new); i++){
            ELMT(*l,i) = ELMT(new,i);
      }
};
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(ListDin *l) {
      shrinkList(l, CAPACITY(*l) -  NEFF(*l));
};
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */