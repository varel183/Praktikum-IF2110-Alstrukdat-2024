// Varel Tiara
// 13523008
// Program ADT Binary Tree + Tambahan Praktikum

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree) {
    BinTree p = (BinTree) malloc(sizeof(BinTree));
    if (p != NULL) {
        ROOT(p) = root;
        LEFT(p) = left_tree;
        RIGHT(p) = right_tree;
    }
    return p;
}; 
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p) {
    *p = NewTree(root, left_tree, right_tree);
};
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */

Address newTreeNode(ElType val) {
    Address p = (Address) malloc(sizeof(TreeNode));
    if (p != NULL) {
        p->info = val;
        p->left = NULL;
        p->right = NULL;
    }
    return p;
};
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */

void deallocTreeNode (Address p) {
    free(p);
};
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */

boolean isTreeEmpty (BinTree p) {
    return p == NULL;
};
/* Mengirimkan true jika p adalah pohon biner yang kosong */

boolean isOneElmt (BinTree p) {
    return !isTreeEmpty(p) && isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p));
};
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

boolean isUnerLeft (BinTree p) {
    return !isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p));
};
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */

boolean isUnerRight (BinTree p) {
    return !isTreeEmpty(p) && isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p));
};
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */

boolean isBinary (BinTree p) {
    return !isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p));
};
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */

/* ****** Display Tree ***** */
void printPreorder(BinTree p) {
    if (isTreeEmpty(p)) {
        printf("()");
    } else {
        printf("(%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
        printf(")");
    }
};
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */

void printInorder(BinTree p) {
    if (isTreeEmpty(p)) {
        printf("()");
    } else {
        printf("(");
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
        printf(")");
    }
};
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */

void printPostorder(BinTree p) {
    if (isTreeEmpty(p)) {
        printf("()");
    } else {
        printf("(");
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d)", ROOT(p));
    }
};
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */

void printTreeLevel(BinTree p, int h, int l) {
    int N;
    if (!isTreeEmpty(p)) {
        N = h * l;
        while (N > 0) {
            printf(" ");
            N--;
        }
        printf("%d\n", ROOT(p));
        printTreeLevel(LEFT(p), h, l + 1);
        printTreeLevel(RIGHT(p), h, l + 1);
    }
}

void printTree(BinTree p, int h) {
    printTreeLevel(p, h, 0);
};
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
*/

boolean isEqual(BinTree p1, BinTree p2) {
    if (isTreeEmpty(p1) && isTreeEmpty(p2)) {
        return true;
    } else if (isTreeEmpty(p1) || isTreeEmpty(p2)) {
        return false;
    } else {
        return (ROOT(p1) == ROOT(p2)) && isEqual(LEFT(p1), LEFT(p2)) && isEqual(RIGHT(p1), RIGHT(p2));
    }
}

/* I.S. p1 dan p2 terdefinisi */
/* F.S. Mengirimkan true jika struktur dan nilai node pada p1 dan p2 identik, false jika tidak */

int getMaximumDepth(BinTree p) {
    if (isTreeEmpty(p)) {
        return 0;
    } else {
        int leftDepth = getMaximumDepth(LEFT(p));
        int rightDepth = getMaximumDepth(RIGHT(p));
        return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
    }
}
// int main() {
//     BinTree root, left_root, right_root, child_left, child_right, child2_right;
//     CreateTree(3, NULL, NULL, &child2_right);
//     CreateTree(4, NULL, child2_right, &child_left);
//     CreateTree(5, NULL, NULL, &child_right);
//     CreateTree(2, child_left, child_right, &left_root);
//     CreateTree(3, NULL, NULL, &right_root);
//     CreateTree(1, left_root, right_root, &root);
//     int count = getMaximumDepth(root);
//     printf("%d", count);
//     return 0;
// }

/* I.S. p terdefinisi */
/* F.S. Mengembalikan kedalaman maksimum pohon biner p */
/* Kedalaman maksimum adalah panjang lintasan dari akar ke simpul daun terjauh */
/* Jika pohon kosong, maka kedalaman = 0 */


BinTree createBinSearchTreeFromSortedArray(ElType* arr, ElType start, ElType end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    BinTree left = createBinSearchTreeFromSortedArray(arr, start, mid - 1);
    BinTree right = createBinSearchTreeFromSortedArray(arr, mid + 1, end);
    BinTree root;
    CreateTree(arr[mid], left, right, &root);
    return root;
}
/* Mengembalikan pohon biner yang seimbang (balanced) dibangun dari array yang terurut */
/* arr terdefinisi dan tidak kosong, start dan end adalah indeks awal dan akhir array */
/* arr merupakan array berisi ElType yang terurut menaik (ascending) */
/* dipastikan semua elemen pada array unik */
/* Pilih elemen tengah dari array (indeks mid = (start + end) / 2) sebagai akar pohon. */
/* Pohon yang dihasilkan adalah Binary Search Tree(BST), di mana setiap node kiri lebih kecil dari parent node,
   dan setiap node kanan lebih besar dari parent node. */
/* Misalnya, jika array [1, 2, 3, 4, 5], pohon yang dihasilkan adalah:
    3
   / \
  1   4
   \   \
    2    5
*/

int countNodes(BinTree p) {
    if (isTreeEmpty(p)) {
        return 0;
    } else {
        return 1 + countNodes(LEFT(p)) + countNodes(RIGHT(p));
    }
}
// int main() {
//     BinTree root, left_root, right_root, child_left, child_right;
//     // CreateTree(3, NULL, NULL, &child2_right);
//     CreateTree(4, NULL, NULL, &child_left);
//     CreateTree(5, NULL, NULL, &child_right);
//     CreateTree(2, child_left, child_right, &left_root);
//     CreateTree(3, NULL, NULL, &right_root);
//     CreateTree(1, left_root, right_root, &root);
//     int count = countNodes(root);
//     printf("%d", count);
//     return 0;
// }

/* p terdefinisi, p adalah pohon biner yang mungkin kosong */
/* Mengembalikan jumlah seluruh node dalam pohon biner p */
/* Contoh:
   Misalkan pohon biner p adalah sebagai berikut:
       1
      / \
     2   3
    / \
   4   5

   Panggilan fungsi: countNodes(p)

   Output: 5
   Penjelasan: Pohon ini memiliki 5 simpul (1, 2, 3, 4, 5)
*/

void printPathToElement(BinTree p, ElType target) {
    int path[100];
    int idx = 0;
    int found = 0; 

    void printPath(BinTree p, ElType target) {
        if (isTreeEmpty(p) || found) {
            return;
        }

        path[idx++] = ROOT(p);

        if (ROOT(p) == target) {
            found = 1; 
            for (int i = 0; i < idx; i++) {
                if (i > 0) {
                    printf(" -> ");
                }
                printf("%d", path[i]);
            }
            printf("\n");
            idx--;
            return;
        }

        if (!isTreeEmpty(LEFT(p))) {
            printPath(LEFT(p), target);
        }

        if (!isTreeEmpty(RIGHT(p)) && !found) {
            printPath(RIGHT(p), target);
        }

        if (!found) {
            idx--; 
        }
    }

    printPath(p, target);

    if (!found) {
        printf("-1\n");
    }
};

/* I.S. p terdefinisi, target adalah elemen yang dicari dalam pohon biner p. Dipastikan node pada pohon biner p unik */
/* F.S. Menampilkan jalur menuju elemen target dalam pohon p dalam format "x -> y -> z" 
   jika elemen ditemukan, atau "-1" jika elemen tidak ditemukan */
/* Untuk memudahkan implementasi, dipastikan path tidak lebih panjang dari 100 elemen */
/* Contoh:
   Jika pohon p adalah:
       1
      / \
     2   3
    / \
   4   5

   Panggilan: printPathToElement(p, 5)
   Output: 1 -> 2 -> 5
*/