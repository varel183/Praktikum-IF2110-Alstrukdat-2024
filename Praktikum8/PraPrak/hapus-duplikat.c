// Varel Tiara
// 13523008
// Program Hapus Duplikat

#include "listlinier.h"
#include <stdio.h>

List hapusDuplikat(List l) {
    List result;
    CreateList(&result);
    
    int isFound[1000] = {0}; // Asumsikan angka dalam list tidak lebih dari 999
    
    Address P = FIRST(l);
    while (P != NULL) {
        if (isFound[INFO(P)] == 0) {
            isFound[INFO(P)] = 1;
        } else {
            Address temp = FIRST(result);
            Address prev = NULL;
            
            while (temp != NULL) {
                if (INFO(temp) == INFO(P)) {
                    if (prev == NULL) {
                        FIRST(result) = NEXT(temp);
                    } else {
                        NEXT(prev) = NEXT(temp);
                    }
                    break;
                }
                prev = temp;
                temp = NEXT(temp);
            }
            
            P = NEXT(P);
            continue;
        }
        
        insertLast(&result, INFO(P));
        P = NEXT(P);
    }
    
    // Urutkan list secara membesar
    Address current, next;
    int temp;
    for (current = FIRST(result); current != NULL; current = NEXT(current)) {
        for (next = NEXT(current); next != NULL; next = NEXT(next)) {
            if (INFO(current) > INFO(next)) {
                temp = INFO(current);
                INFO(current) = INFO(next);
                INFO(next) = temp;
            }
        }
    }
    
    return result;
}
/**
 * Menerima masukan sebuah list l yang terurut mengecil
 * Mengembalikan list yang merupakan hasil penghapusan elemen yang mempunyai duplikat pada list l, terurut membesar
 * Contoh: hapusDuplikat(3->3->2->1) = 1->2 (-> adalah panah next pada list linear)
 */