#include "sort.h"
#include <stdio.h>

Address findMiddle(List l) {
    if (isEmpty(l) || isOneElmt(l)) {
        return l;
    } else {
        int mid;
        if (length(l) % 2 == 1){
            mid = length(l)/2;
        } else {
            mid = length(l)/2;
            mid--;
        }
        Address p = l;
        while (mid != 0){
            p = NEXT(p);
            mid--;
        }
        return p;
    }
};
/* Fungsi untuk mencari middle dari list l.
   Fungsi akan mengembalikan Address dari middle tersebut.
   Apabila list ganjil, maka middle adalah elemen tengah.
   Apabila list genap, maka middle adalah elemen tengah kiri.
*/

List merge(List l1, List l2) {
    if (isEmpty(l1)) {
        return l2;
    } else if (isEmpty(l2)) {
        return l1;
    } else {
        if (head(l1) < head(l2)) {
            return konso(merge(tail(l1), l2), head(l1));
        } else {
            return konso(merge(l1, tail(l2)), head(l2));
        }
    }
};
/* melakukan merge sort list a dan b secara rekursif.
   Sort dilakukan secara ascending berdasarkan nilai elemen.
*/

List mergeSort(List l) {
    if (isEmpty(l) || isOneElmt(l)) {
        return l;
    } else {
        Address mid = findMiddle(l);
        List left = l;
        List right = tail(mid);
        NEXT(mid) = NIL;
        return merge(mergeSort(left), mergeSort(right));
    }
};
/* Fungsi untuk melakukan inisialisasi merge sort secara rekursif.
   Apabila head atau NEXT(head) kosong, maka mengembalikan list tersebut.
   Fungsi akan membagi list menjadi dua terlebih dahulu, kemudian
   secara rekursif melakukan merge untuk mengurutkan.   
*/

List zigZagSort(List l) {
    if (isEmpty(l) || isOneElmt(l)) {
        return l;
    } else {
        List result = NULL;
        boolean smallest = true;

        while (l != NULL) {
            Address p = l;
            if (smallest) {
                ElType min = head(p);
                int idx = 0;
                int i = 0;
                while(p != NULL){
                    if(head(p) < min){
                        min = head(p);
                        idx = i;
                    }
                    p = tail(p);
                    i++;
                }
                result = konsb(result, min);
                l = deleteAt(l, idx);
                smallest = false;
            } else {
                ElType max = head(p);
                int idx = 0;
                int i = 0;
                while(p != NULL){
                    if(head(p) > max){
                        max = head(p);
                        idx = i;
                    }
                    p = tail(p);
                    i++;
                }
                result = konsb(result, max);
                l = deleteAt(l, idx);
                smallest = true;
            }
        }
        return result;
    }
};
/* Fungsi untuk melakukan zig-zag sort.
   Zig-zag sort adalah suatu teknik pengurutan dengan cara
   mengurutkan elemen-elemen dengan pola:
   terbesar 1 - terkecil 1 - terbesar 2 - terkecil 2 .. dst.
   Contoh:
   2 8 5 3 1
   1 8 2 4 3
*/

int main() {
    List l = konso(konso(konso(konso(konso(NIL, 2), 8), 5), 3), 1);
    displayList(l);
    l = zigZagSort(l);
    displayList(l);
    return 0;
}