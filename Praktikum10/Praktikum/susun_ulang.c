// Varel Tiara
// 13523008
// Program Susun ulang

#include <stdio.h>
#include "listrec.h"

List susunUlang(List l) {
    
    // boolean susun = true;

    // while (l != NULL) {
    //     Address p = l;
    //     if (susun) {
    //         p = reverseList(p);
    //         result = konsb(result, head(p));
    //         l = deleteLast(l);
    //         susun = false;
    //     } else {
                
    //         result = konsb(result, head(p));
    //         l = deleteFirst(l);
    //         susun = true;
    //     }
    // }
    // return result;
    if (isEmpty(l)) {
        return NIL;
    } else {
        List result = NULL;
        
        l = reverseList(l);
        result = konso(susunUlang(tail(l)), head(l));
        l = deleteFirst(l);
   
        return result;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    List l, l1, l2;
    l = NIL;
    l1 = NIL;
    l2 = NIL;

    int i,val;
    for (i=0; i<N; i++) {
        scanf("%d", &val);
        l = konsb(l,val);
    }

    if (isEmpty(l) || isOneElmt(l)) {
        displayList(l);
        return 0;
    }
    else {
        l1 = konso(l1, head(l));
        l2 = tail(l);
        l2 = susunUlang(l2);
        
        l = concat(l1, l2);
        
        displayList(l);
        return 0;
    }
    
    
}