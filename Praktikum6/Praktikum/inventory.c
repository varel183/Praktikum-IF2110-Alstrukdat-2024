// Varel Tiara
// 13523008
// Program Inventory

#include "stack.h"
#include <stdio.h>

int lenStack(Stack S) {
    int count = 0;
    Stack temp;
    CreateEmpty(&temp);
    
    while (!IsEmpty(S)) {
        int val;
        Pop(&S, &val);
        Push(&temp, val);
        count++;
    }
    
    while (!IsEmpty(temp)) {
        int val;
        Pop(&temp, &val);
        Push(&S, val);
    }
    
    return count;
}

int sumStack(Stack S) {
    int sum = 0;
    Stack temp;
    CreateEmpty(&temp);
    
    while (!IsEmpty(S)) {
        int val;
        Pop(&S, &val);
        sum += val;
        Push(&temp, val);
    }
    
    // Restore the original stack state
    while (!IsEmpty(temp)) {
        int val;
        Pop(&temp, &val);
        Push(&S, val);
    }
    
    return sum;
}

int main() {
    int N;
    scanf("%d", &N);
    int i;
    char val;

    Stack S;
    CreateEmpty(&S);

    for (i = 0; i < N; i++) {
        scanf(" %c", &val);
        if (val == '+') {
            int digit1, digit2;
            Pop(&S, &digit1);
            Pop(&S, &digit2);
            int add = digit1 + digit2;
            Push(&S, digit2); // Restore previous elements
            Push(&S, digit1);
            Push(&S, add); // Add new result
        } else if (val == 'X') {
            if (!IsEmpty(S)) {
                int digit;
                Pop(&S, &digit); // Remove top element if stack isn't empty
            }
        } else if (val == 'S') {
            if (!IsEmpty(S)) {
                int sum = sumStack(S);
                while (!IsEmpty(S)) {
                    int discard;
                    Pop(&S, &discard); // Clear stack for new total
                }
                Push(&S, sum); // Push sum as new top element
            } else {
                Push(&S, 0);
            }
        } else if (val == 'A') {
            int len = lenStack(S);
            if (IsEmpty(S)) {
                Push(&S, 0);
            } else {
                int avg = sumStack(S) / len; // Calculate average
                while (!IsEmpty(S)) {
                    int discard;
                    Pop(&S, &discard); // Clear stack for new average
                }
                Push(&S, avg); // Push average as new top element
            }
        } else { // If val is a digit
            int num = val - '0';
            Push(&S, num);
        }
    }

    printf("%d\n", sumStack(S));
    return 0;
}
