// Varel Tiara
// 13523008
// Program Matrix

#include <stdio.h>
#include "boolean.h"
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m) {
    /* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
    /* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
    /* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
    int i, j;
    for (i = 0; i < nRows; i++) {
        for (j = 0; j < nCols; j++) {
            ELMT(*m, i, j) = 0;
        }
    }
};


/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j) {
    /* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
    return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
};

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m) {
    /* Mengirimkan Index baris terbesar m */
    return ROW_EFF(m) - 1;
};

IdxType getLastIdxCol(Matrix m) {
    /* Mengirimkan Index kolom terbesar m */
    return COL_EFF(m) - 1;
};

boolean isIdxEff(Matrix m, IdxType i, IdxType j) {
    /* Mengirimkan true jika i, j adalah Index efektif bagi m */
    return (i >= 0 && i < ROW_EFF(m) && j >= 0 && j < COL_EFF(m));
};

ElType getElmtDiagonal(Matrix m, IdxType i) {
    /* Mengirimkan elemen m(i,i) */
    return ELMT(m, i, i);
};
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut) {
    /* Melakukan assignment mOut <- mIn */
    ROW_EFF(*mOut) = ROW_EFF(mIn);
    COL_EFF(*mOut) = COL_EFF(mIn);
    int i, j;
    for (i = 0; i < ROW_EFF(mIn); i++) {
        for (j = 0; j < COL_EFF(mIn); j++) {
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
};

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol) {
    /* I.S. isIdxValid(nRow,nCol) */
    /* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
    /* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
    /* Selanjutnya membaca nilai elemen per baris dan kolom */
    /* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
    1 2 3
    4 5 6
    8 9 10 
    */
    createMatrix(nRow, nCol, m);
    int i, j;
    for (i = 0; i < nRow; i++) {
        for (j = 0; j < nCol; j++) {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
};

void displayMatrix(Matrix m) {
    /* I.S. m terdefinisi */
    /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
    dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
    /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
    /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
    1 2 3
    4 5 6
    8 9 10
    */
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            printf("%d", ELMT(m, i, j));
            if (j != COL_EFF(m) - 1) {
                printf(" ");
            }
        }
        if (i != ROW_EFF(m) - 1) {
            printf("\n");
        }
    }
};

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2) {
    /* Prekondisi : m1 berukuran sama dengan m2 */
    /* Mengirim hasil penjumlahan matriks: m1 + m2 */
    Matrix m;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m);
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            ELMT(m, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return m;
};

Matrix subtractMatrix(Matrix m1, Matrix m2) {
    /* Prekondisi : m1 berukuran sama dengan m2 */
    /* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
    Matrix m;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m);
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            ELMT(m, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return m;
};

Matrix multiplyMatrix(Matrix m1, Matrix m2) {
    /* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
    /* Mengirim hasil perkalian matriks: salinan m1 * m2 */
    Matrix m;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m);
    int i, j, k;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m2); j++) {
            ELMT(m, i, j) = 0;
            for (k = 0; k < COL_EFF(m1); k++) {
                ELMT(m, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
        }
    }
    return m;
};

Matrix multiplyByConst(Matrix m, ElType x) {
    /* Mengirim hasil perkalian setiap elemen m dengan x */
    Matrix mOut;
    createMatrix(ROW_EFF(m), COL_EFF(m), &mOut);
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            ELMT(mOut, i, j) = ELMT(m, i, j) * x;
        }
    }
    return mOut;
};
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyByConst(Matrix *m, ElType k) {
    /* I.S. m terdefinisi, k terdefinisi */
    /* F.S. Mengalikan setiap elemen m dengan k */
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++) {
        for (j = 0; j < COL_EFF(*m); j++) {
            ELMT(*m, i, j) *= k;
        }
    }
};
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2) {
    /* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
    /* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
    /* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
    if (ROW_EFF(m1) != ROW_EFF(m2) || COL_EFF(m1) != COL_EFF(m2)) {
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            if (ELMT(m1, i, j) != ELMT(m2, i, j)) {
                return false;
            }
        }
    }
    return true;
};

boolean isMatrixNotEqual(Matrix m1, Matrix m2) {
    /* Mengirimkan true jika m1 tidak sama dengan m2 */
    return !isMatrixEqual(m1, m2);
};

boolean isMatrixSizeEqual(Matrix m1, Matrix m2) {
    /* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
    /* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
    return ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2);
};


/* ********** Operasi lain ********** */
int countElmt(Matrix m) {
    /* Mengirimkan banyaknya elemen m */
    return ROW_EFF(m) * COL_EFF(m);
};


/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m) {
    /* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
    return ROW_EFF(m) == COL_EFF(m);
};

boolean isSymmetric(Matrix m) {
    /* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
       dan untuk setiap elemen m, m(i,j)=m(j,i) */
    if (!isSquare(m)) {
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            if (ELMT(m, i, j) != ELMT(m, j, i)) {
                return false;
            }
        }
    }
    return true;
};

boolean isIdentity(Matrix m) {
    /* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
       setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    if (!isSquare(m)) {
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            if (i == j) {
                if (ELMT(m, i, j) != 1) {
                    return false;
                }
            } else {
                if (ELMT(m, i, j) != 0) {
                    return false;
                }
            }
        }
    }
    return true;
};

boolean isSparse(Matrix m) {
    /* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
       hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    int i, j, count = 0;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            if (ELMT(m, i, j) != 0) {
                count++;
            }
        }
    }
    return count <= 0.05 * ROW_EFF(m) * COL_EFF(m);
};

Matrix negation(Matrix m) {
    /* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
    Matrix mOut;
    createMatrix(ROW_EFF(m), COL_EFF(m), &mOut);
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            ELMT(mOut, i, j) = -ELMT(m, i, j);
        }
    }
    return mOut;
};

void pNegation(Matrix *m) {
    /* I.S. m terdefinisi */
    /* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++) {
        for (j = 0; j < COL_EFF(*m); j++) {
            ELMT(*m, i, j) = -ELMT(*m, i, j);
        }
    }
};

float determinant(Matrix m) {
    /* Prekondisi: isSquare(m) */
    /* Menghitung nilai determinan m */
    if (!isSquare(m)) {
        return 0.0;
    }
    if (ROW_EFF(m) == 1) {
        return (float)ELMT(m, 0, 0);
    }
    if (ROW_EFF(m) == 2) {
        return (float)(ELMT(m, 0, 0) * ELMT(m, 1, 1) - ELMT(m, 0, 1) * ELMT(m, 1, 0));
    }

    float det = 0.0;
    int i, j;
    for (j = 0; j < COL_EFF(m); j++) {
        Matrix subMatrix;
        createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &subMatrix);
        for (i = 1; i < ROW_EFF(m); i++) {
            int subCol = 0;
            for (int k = 0; k < COL_EFF(m); k++) {
                if (k != j) {
                    ELMT(subMatrix, i - 1, subCol) = ELMT(m, i, k);
                    subCol++;
                }
            }
        }
        det += (j % 2 == 0 ? 1 : -1) * ELMT(m, 0, j) * determinant(subMatrix);
    }
    return det;
};

Matrix transpose(Matrix m) {
    /* I.S. m terdefinisi dan IsSquare(m) */
    /* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    Matrix mOut;
    createMatrix(ROW_EFF(m), COL_EFF(m), &mOut);
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            ELMT(mOut, j, i) = ELMT(m, i, j);
        }
    }
    return mOut;
};

void pTranspose(Matrix *m) {
    /* I.S. m terdefinisi dan IsSquare(m) */
    /* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    Matrix result = transpose(*m);
    copyMatrix(result, m);
};
