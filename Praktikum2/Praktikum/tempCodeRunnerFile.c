// Varel Tiara
// 13523008
// Program Elemen Kedua Terbanyak

#include <stdio.h>
#include "liststatik.c"

int main() {
    int N;
    ListStatik l, result, count, uniqueList, freqList;
    int i, j, uniqueCount = 0;

    scanf("%d", &N);

    CreateListStatik(&result);
    CreateListStatik(&count);
    readList(&l);


    for (i = 0; i < N; i++) {
        int found = 0;
        for (j = 0; j < uniqueCount; j++) {
            if (uniqueList[j] == list[i]) {
                freqList[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            uniqueList[uniqueCount] = list[i];
            freqList[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    int maxFreq = 0, secondMaxFreq = 0;
    for (i = 0; i < uniqueCount; i++) {
        if (freqList[i] > maxFreq) {
            secondMaxFreq = maxFreq;
            maxFreq = freqList[i];
        } else if (freqList[i] > secondMaxFreq && freqList[i] < maxFreq) {
            secondMaxFreq = freqList[i];
        }
    }


    if (secondMaxFreq == 0) {
        printf("Tidak ada elemen kedua yang paling sering muncul\n");
    } else {
        int result = -1;
        for (i = 0; i < uniqueCount; i++) {
            if (freqList[i] == secondMaxFreq) {
                if (result == -1 || uniqueList[i] < result) {
                    result = uniqueList[i];
                }
            }
        }
        printf("%d\n", result);
    }

    return 0;
}
