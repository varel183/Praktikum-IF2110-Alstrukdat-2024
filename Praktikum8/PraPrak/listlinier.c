// Varel Tiara
// 13523008
// Program ADT List Linier

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType val) {
  Address P = (Address) malloc(sizeof(Node));
  if (P != NULL) {
    INFO(P) = val;
    NEXT(P) = NULL;
  }
  return P;
};

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */


/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
  FIRST(*l) = NULL;
};
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
  return FIRST(l) == NULL;
};
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx) {
  Address P = FIRST(l);
  int i = 0;
  while (i < idx) {
    P = NEXT(P);
    i++;
  }
  return INFO(P);
};
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val) {
  Address P = FIRST(*l);
  int i = 0;
  while (i < idx) {
    P = NEXT(P);
    i++;
  }
  INFO(P) = val;
};
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val) {
  Address P = FIRST(l);
  int i = 0;
  while (P != NULL) {
    if (INFO(P) == val) {
      return i;
    }
    P = NEXT(P);
    i++;
  }
  return IDX_UNDEF;
  
};
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
  Address P = newNode(val);
  if (P != NULL) {
    NEXT(P) = FIRST(*l);
    FIRST(*l) = P;
  }
};
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val) {
  if (isEmpty(*l)) {
    insertFirst(l, val);
  } else {
    Address P = newNode(val);
    if (P != NULL) {
      Address Last = FIRST(*l);
      while (NEXT(Last) != NULL) {
        Last = NEXT(Last);
      }
      NEXT(Last) = P;
    }
  }
};
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx) {
  if (idx == 0) {
    insertFirst(l, val);
  } else {
    Address P = newNode(val);
    if (P != NULL) {
      Address Prec = FIRST(*l);
      int i = 0;
      while (i < idx - 1 ) {
        Prec = NEXT(Prec);
        i++;
      }
      NEXT(P) = NEXT(Prec);
      NEXT(Prec) = P;
    }
  }
};
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
  Address P = FIRST(*l);
  *val = INFO(P);
  FIRST(*l) = NEXT(P);
  free(P); 
};
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val) {
  Address Last = FIRST(*l);
  Address PrecLast = NULL;
  while (NEXT(Last) != NULL) {
    PrecLast = Last;
    Last = NEXT(Last);
  }
  if (PrecLast == NULL) {
    FIRST(*l) = NULL;
  } else {
    NEXT(PrecLast) = NULL;
  }
  *val = INFO(Last);
  free(Last);
};
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val) {
  if (idx == 0) {
    deleteFirst(l, val);
  } else {
    Address Prec = FIRST(*l);
    int i = 0;
    while (i < idx - 1) {
      Prec = NEXT(Prec);
      i++;
    }
    Address P = NEXT(Prec);
    *val = INFO(P);
    NEXT(Prec) = NEXT(P);
    free(P);
  }
};
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
  Address P = FIRST(l);
  printf("[");
  while (P != NULL) {
    printf("%d", INFO(P));
    P = NEXT(P);
    if (P != NULL) {
      printf(",");
    }
  }
  printf("]");
};
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l) {
  Address P = FIRST(l);
  int len = 0;
  while (P != NULL) {
    len++;
    P = NEXT(P);
  }
  return len;
};
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
  List l3;
  CreateList(&l3);
  Address P = FIRST(l1);
  
  while (P != NULL) {
    insertLast(&l3, INFO(P));
    P = NEXT(P);
  }

  P = FIRST(l2);
  while (P != NULL) {
    insertLast(&l3, INFO(P));
    P = NEXT(P);
  }

  return l3;
};
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P) {
    Address now;
    boolean flag = false;
    now = L;
    while(now->next != NULL && !flag) {
        if(now==P){
            flag = true;
        }
        now = now->next;
    }
    return flag;
}

Address searchPrec(List L, ElType X) {
    if(isEmpty(L) || length(L) == 1){
        return NULL;
    }
    Address p = L;
    Address previous;
    while(p != NULL && INFO(p)!= X){
        previous = p;
        p = NEXT(p);
    }
    if(p == NULL){
        return NULL;
    }
    else{
        return previous;
    }
}

ElType maxValue(List l) {
    int maksimum;
    Address p = l;
    maksimum = p->info;
    while(p != NULL){
        if(INFO(p) > maksimum){
            maksimum = INFO(p);
        }
        p = NEXT(p);
    }
    return maksimum;
}

Address adrMax(List l)
{
    int maksimum = maxValue(l);
    Address p = l;
    while (p != NULL && INFO(p) != maksimum){
        p = NEXT(p);
    }
    return p;
}

ElType minValue(List l)
{
    int minimum;
    Address p = l;
    minimum = INFO(p);
    while (p != NULL){
        if (INFO(p) < minimum){
            minimum = INFO(p);
        }
        p = NEXT(p);
    }
    return minimum;
}

Address adrMin(List l)
{
    int minimum = minValue(l);
    Address p = l;
    while(p != NULL && INFO(p) != minimum){
        p = NEXT(p);
    }
    return p;
}

float average(List l)
{
    float sum = 0;
    int n = 0;
    Address p = l;
    while(p != NULL){
        sum += INFO(p);
        n++;
        p = NEXT(p);
    }
    return sum/n;
}

/***************** FUNGSI dan PROSEDUR TAMBAHAN **************/
void deleteAll(List *l)
{
    Address p = *l;
    int value;
    while(p != NULL){
        deleteFirst(l, &value);
        p = NEXT(p);
    }
    *l = NULL;
}

void copyList(List *l1, List *l2)
{
    *l2 = *l1;
}

void inverseList(List *l)
{
    if(!isEmpty(*l)){
        int n = length(*l);
        int i;
        Address p = *l;
        Address prev;
        Address last;
        while(NEXT(p)!= NULL){
            p = NEXT(p);
        }
        last = p;
        while (p != *l){
            prev = *l;
            while(NEXT(prev) != p){
                prev = NEXT(prev);
            }
            NEXT(p) = prev;
            p = prev;
        }
        NEXT(p) = NULL;
        *l = last;
    }
}
