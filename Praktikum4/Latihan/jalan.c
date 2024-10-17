// #include <stdio.h>

// int countPaths(int matrix[3][3], int N) {
//     int paths[N][N];
    
//     // Inisialisasi paths dengan 0 untuk posisi yang tidak bisa dilewati
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             paths[i][j] = 0;
//         }
//     }
    
//     // Jika posisi awal bisa dilewati, inisialisasi dengan 1
//     if (matrix[0][0] == 1) {
//         paths[0][0] = 1;
//     }
    
//     // Isi matrix paths berdasarkan posisi yang bisa dilewati
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             // Jika posisi ini bisa dilewati
//             if (matrix[i][j] == 1) {
//                 // Tambahkan jumlah jalur dari kiri jika ada
//                 if (j > 0) {
//                     paths[i][j] += paths[i][j - 1];
//                 }
//                 // Tambahkan jumlah jalur dari atas jika ada
//                 if (i > 0) {
//                     paths[i][j] += paths[i - 1][j];
//                 }
//             }
//         }
//     }
    
//     return paths[N - 1][N - 1];
// }

// int main() {
//     int N = 3;
//     int matrix[3][3] = {
//         {1, 0, 1},
//         {1, 1, 0},
//         {0, 1, 1}
//     };

//     int result = countPaths(matrix, N);
//     printf("Jumlah jalur: %d\n", result);
//     return 0;
// }


#include <stdio.h>
#include "matrix.c"

int main() {
    Matrix jalan, path;
    int N, M;
    scanf("%d %d", &N, &M);

    createMatrix(N, M, &jalan);
    readMatrix(&jalan, N, M);

    createMatrix(N, M, &path);
    
    if ((ELMT(jalan, 0, 0)) == 1) {
        ELMT(path, 0, 0) = 1;
    }
    if ((ELMT(path, 0, 0)) == 1) {
        int i,j;
        for (i=0;i<N;i++) {
            for (j=0;j<M;j++) {
                if ((ELMT(jalan, i, j)) == 1) {
                    if (i > 0) {
                        ELMT(path, i, j) += ELMT(path, i-1, j);
                    }
                    if (j > 0) {
                        ELMT(path, i, j) += ELMT(path, i, j-1);
                    }
                }
            }
        }
    }
    printf("%d\n", (ELMT(path, N-1, M-1)));
    return 0;
}