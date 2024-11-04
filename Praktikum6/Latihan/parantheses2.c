#include "stack.h"
#include "mesinkarakter.c"
#include "mesinkata.c"
#include <stdio.h>

void readWord(Word *input) {
    int a;
    START();
    IgnoreBlanks();
    (*input).Length = 0;
    a = 0;
    while ((currentChar != MARK) && (a < NMax)) {
        (*input).TabWord[a] = currentChar;
        ADV();
        a++;
    }
    (*input).Length = a;
    (*input).TabWord[a] = '\0';
}

int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

int main() {
    Word character;
    readWord(&character);
    Stack S;
    CreateEmpty(&S);

    int i;
    int maxDepth = 0;

    for (i = 0; i < character.Length; i++) {
        char currentChar = character.TabWord[i];

        // Check if current character is an opening bracket
        if (currentChar == '(' || currentChar == '[' || currentChar == '{') {
            Push(&S, currentChar);
            if (Top(S) + 1 > maxDepth) {
                maxDepth = Top(S) + 1;
            }
        }
        // Check if current character is a closing bracket
        else if (currentChar == ')' || currentChar == ']' || currentChar == '}') {
            char topChar;
            if (IsEmpty(S)) {
                printf("-1\n");  // Unmatched closing bracket
                return 0;
            }
            Pop(&S, &topChar);

            // Check if the popped bracket matches the current closing bracket
            if (!isMatchingPair(topChar, currentChar)) {
                printf("-1\n");  // Mismatched bracket
                return 0;
            }
        }
    }

    if (!IsEmpty(S)) {
        printf("-1\n");  // Unmatched opening bracket
        return 0;
    }

    printf("%d\n", maxDepth);
    return 0;
}
