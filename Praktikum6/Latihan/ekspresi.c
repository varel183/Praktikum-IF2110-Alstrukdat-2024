#include "stack.c"
#include <stdio.h>
#include "mesinkarakter.c"
#include "mesinkata.c"

boolean IsOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main() {
    Stack S;
    CreateEmpty(&S);

    STARTWORD();
    while (!EndWord){
        if (IsOperator(currentWord.TabWord[0])){
            int res;
            int a, b;
            Pop(&S, &a);
            Pop(&S, &b);
            if (currentWord.TabWord[0] == '+'){
                res = a + b;
                Push(&S, res);
            } else if (currentWord.TabWord[0] == '-'){
                res = a - b;
                Push(&S, res);
            } else if (currentWord.TabWord[0] == '*'){
                res = a * b;
                Push(&S, res);
            } else if (currentWord.TabWord[0] == '/'){
                res = a / b;
                Push(&S, res);
            } else if (currentWord.TabWord[0] == '^'){
                int result = 1;
                for (int i = 0; i < b; i++){
                    result *= a;
                }
                res = result;
                Push(&S, res);
            }
            printf("%d\n", res);
        } else {
          int temp = 0;
            for (int i = 0; i < currentWord.Length; i++){
                temp = temp * 10 + (currentWord.TabWord[i] - '0');
            }
            Push(&S, temp);
            printf("%d\n", temp);
        }
        ADVWORD();
    }

    int result;
    Pop(&S, &result);
    printf("%d\n", result);
    return 0;
}

