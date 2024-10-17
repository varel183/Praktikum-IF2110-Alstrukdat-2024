// #include <stdio.h>
// #define N 4

// int main() {
//     int grid[N][N] = {
//         {1, 0, 1, 0},
//         {1, 1, 0, 1},
//         {0, 1, 1, 0},
//         {1, 1, 1, 1}
//     };

//     int coins[N][N] = {0};  // Matrix untuk menyimpan koin maksimal
//     int paths[N][N] = {0};  // Matrix untuk menyimpan jumlah jalur
    
//     // Inisialisasi posisi awal
//     coins[0][0] = grid[0][0];
//     paths[0][0] = 1;

//     // Isi baris pertama (hanya bisa dari kiri ke kanan)
//     for (int j = 1; j < N; j++) {
//         if (grid[0][j] == 1 && coins[0][j - 1] > 0) {
//             coins[0][j] = coins[0][j - 1] + 1;
//             paths[0][j] = paths[0][j - 1];
//         }
//     }

//     // Isi kolom pertama (hanya bisa dari atas ke bawah)
//     for (int i = 1; i < N; i++) {
//         if (grid[i][0] == 1 && coins[i - 1][0] > 0) {
//             coins[i][0] = coins[i - 1][0] + 1;
//             paths[i][0] = paths[i - 1][0];
//         }
//     }

//     // Isi matrix untuk koin maksimal dan jalur dari (1,1) sampai (N-1,N-1)
//     for (int i = 1; i < N; i++) {
//         for (int j = 1; j < N; j++) {
//             if (grid[i][j] == 1) {
//                 if (coins[i - 1][j] > 0 || coins[i][j - 1] > 0) {
//                     if (coins[i - 1][j] > coins[i][j - 1]) {
//                         coins[i][j] = coins[i - 1][j] + 1;
//                         paths[i][j] = paths[i - 1][j];
//                     } else if (coins[i - 1][j] < coins[i][j - 1]) {
//                         coins[i][j] = coins[i][j - 1] + 1;
//                         paths[i][j] = paths[i][j - 1];
//                     } else {
//                         coins[i][j] = coins[i - 1][j] + 1;
//                         paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
//                     }
//                 }
//             }
//         }
//     }

//     // Output jumlah koin maksimal dan jumlah jalur di posisi akhir
//     printf("Jumlah koin maksimal: %d\n", coins[N - 1][N - 1]);
//     printf("Jumlah jalur untuk mencapai jumlah koin maksimal: %d\n", paths[N - 1][N - 1]);

//     return 0;
// }


#include <stdio.h>
#include "matrix.c"

int main() {
  Matrix l, koin, path;
  int N, M;
  scanf("%d %d", &N, &M);

  createMatrix(N, M, &l);
  readMatrix(&l, N, M);

  createMatrix(N, M, &koin);
  createMatrix(N, M, &path);

  if ((ELMT(l, 0, 0)) == 1) {
    ELMT(koin, 0, 0) = 1;
    ELMT(path, 0, 0) = 1;
  }
  if ((ELMT(path, 0, 0)) == 1) {
    int i,j;
    for (j=0;j<M;j++) {
      if ((ELMT(l, 0, j)) == 1 && ELMT(koin, 0, j-1) > 0) {
        ELMT(koin, 0, j) = ELMT(koin, 0, j-1) + 1;
        ELMT(path, 0, j) = ELMT(path, 0, j-1);
      }
    }
    for (i=1;i<N;i++) {
      if ((ELMT(l, i, 0)) == 1 && ELMT(koin, i-1, 0) > 0) {
        ELMT(koin, i, 0) = ELMT(koin, i-1, 0) + 1;
        ELMT(path, i, 0) = ELMT(path, i-1, 0);
      }
    }

    for (i=1;i<N;i++) {
      for (j=1;j<M;j++) {
        if ((ELMT(l, i, j)) == 1) {
          if (ELMT(koin, i-1, j) > 0 || ELMT(koin, i, j-1) > 0) {
            if (ELMT(koin, i-1, j) > ELMT(koin, i, j-1)) {
              ELMT(koin, i, j) = ELMT(koin, i-1, j) + 1;
              ELMT(path, i, j) = ELMT(path, i-1, j);
            } else if (ELMT(koin, i-1, j) < ELMT(koin, i, j-1)) {
              ELMT(koin, i, j) = ELMT(koin, i, j-1) + 1;
              ELMT(path, i, j) = ELMT(path, i, j-1);
            } else {
              ELMT(koin, i, j) = ELMT(koin, i-1, j) + 1;
              ELMT(path, i, j) = ELMT(path, i-1, j) + ELMT(path, i, j-1);
            }
          }
        }
      }
    }
  }
  printf("%d\n", (ELMT(path, N-1, M-1)));
  printf("%d\n", (ELMT(koin, N-1, M-1)));
  return 0;
}