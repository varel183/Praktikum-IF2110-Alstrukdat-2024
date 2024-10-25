// Varel Tiara
// 13523008
// Program String to Number

#include <stdio.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"

boolean compareWords(Word word1, Word word2)
{
    // KAMUS
    int i;

    // ALGORITMA
    if (word1.Length != word2.Length)
    {
        return false;
    }

    for (i = 0; i < word1.Length; i++)
    {
        if (word1.TabWord[i] != word2.TabWord[i])
        {
            return false;
        }
    }

    return true;
}

Word convertStringToWord(char str[], int length)
{
    // KAMUS
    int i;
    Word result;

    // ALGORITMA
    result.Length = length;
    for (i = 0; i < length; i++)
    {
        result.TabWord[i] = str[i];
    }

    return result;
}

int main()
{
    // KAMUS
    int i, number;
    boolean addSpace, isNumber, printNumber;
    Word wordZero, wordOne, wordTwo, wordThree, wordFour, wordFive, wordSix, wordSeven, wordEight, wordNine;
    Word wordTen, wordEleven, wordTeen, wordTens, wordOneHundred, wordHundreds, wordOneThousand, wordThousands;

    // ALGORITMA
    STARTWORD();

    char stringZero[50] = "nol";
    wordZero = convertStringToWord(stringZero, 3);

    char stringOne[50] = "satu";
    wordOne = convertStringToWord(stringOne, 4);

    char stringTwo[50] = "dua";
    wordTwo = convertStringToWord(stringTwo, 3);

    char stringThree[50] = "tiga";
    wordThree = convertStringToWord(stringThree, 4);

    char stringFour[50] = "empat";
    wordFour = convertStringToWord(stringFour, 5);

    char stringFive[50] = "lima";
    wordFive = convertStringToWord(stringFive, 4);

    char stringSix[50] = "enam";
    wordSix = convertStringToWord(stringSix, 4);

    char stringSeven[50] = "tujuh";
    wordSeven = convertStringToWord(stringSeven, 5);

    char stringEight[50] = "delapan";
    wordEight = convertStringToWord(stringEight, 7);

    char stringNine[50] = "sembilan";
    wordNine = convertStringToWord(stringNine, 8);

    char stringTen[50] = "sepuluh";
    wordTen = convertStringToWord(stringTen, 7);

    char stringEleven[50] = "sebelas";
    wordEleven = convertStringToWord(stringEleven, 7);

    char stringTeen[50] = "belas";
    wordTeen = convertStringToWord(stringTeen, 5);

    char stringTens[50] = "puluh";
    wordTens = convertStringToWord(stringTens, 5);

    char stringOneHundred[50] = "seratus";
    wordOneHundred = convertStringToWord(stringOneHundred, 7);

    char stringHundreds[50] = "ratus";
    wordHundreds = convertStringToWord(stringHundreds, 5);

    number = -1;
    while (!EndWord)
    {
        isNumber = false;
        printNumber = false;

        if (compareWords(wordZero, currentWord))
        {
            if (number == -1)
            {
                number = 0;
            }
            number += 0;
            isNumber = true;
        }
        else if (compareWords(wordOne, currentWord))
        {
            if (number == -1)
            {
                number = 0;
            }
            number += 1;
            isNumber = true;
        }
        else if (compareWords(wordTwo, currentWord))
        {
            if (number == -1)
            {
                number = 0;
            }
            number += 2;
            isNumber = true;
        }
        else if (compareWords(wordThree, currentWord))
        {
            if (number == -1)
            {
                number = 0;
            }
            number += 3;
            isNumber = true;
        }
        else if (compareWords(wordFour, currentWord))
        {
            if (number == -1)
            {
                number = 0;
            }
            number += 4;
            isNumber = true;
        }
        else if (compareWords(wordFive, currentWord))
        {
            if (number == -1)
            {
                number = 0;
            }
            number += 5;
            isNumber = true;
        }
        else if (compareWords(wordSix, currentWord))
        {
            if (number == -1)
            {
                number = 0;
            }
            number += 6;
            isNumber = true;
        }
        else if (compareWords(wordSeven, currentWord))
        {
            if (number == -1)
            {
                number = 0;
            }
            number += 7;
            isNumber = true;
        }
        else if (compareWords(wordEight, currentWord))
        {
            if (number == -1)
            {
                number = 0;
            }
            number += 8;
            isNumber = true;
        }
        else if (compareWords(wordNine, currentWord))
        {
            if (number == -1)
            {
                number = 0;
            }
            number += 9;
            isNumber = true;
        }
        else if (compareWords(wordTen, currentWord))
        {
            if (number == -1)
            {
                number = 0;
            }
            number += 10;
            isNumber = true;
        }
        else if (compareWords(wordEleven, currentWord))
        {
            if (number == -1)
            {
                number = 0;
            }
            number += 11;
            isNumber = true;
        }
        else if (compareWords(wordTeen, currentWord))
        {
            if (number == -1)
            {
                number = 0;
            }
            number += 10;
            isNumber = true;
        }
        else if (compareWords(wordTens, currentWord))
        {
            number += (10 * (number % 10)) - (number % 10);
            isNumber = true;
        }
        else if (compareWords(wordOneHundred, currentWord))
        {
            if (number == -1)
            {
                number = 0;
            }
            number += 100;
            isNumber = true;
        }
        else if (compareWords(wordHundreds, currentWord))
        {
            number += (100 * (number % 100)) - (number % 100);
            isNumber = true;
        }
        else
        {
            printNumber = true;
        }

        if (printNumber && number >= 0)
        {
            if (addSpace)
            {
                printf(" ");
            }
            printf("%d", number);
            addSpace = true;
            number = -1;
        }

        if (!isNumber)
        {
            if (addSpace)
            {
                printf(" ");
            }

            for (i = 0; i < currentWord.Length; i++)
            {
                printf("%c", currentWord.TabWord[i]);
            }

            addSpace = true;
        }

        ADVWORD();
    }

    if (number >= 0)
    {
        if (addSpace)
        {
            printf(" ");
        }
        printf("%d", number);
        addSpace = true;
    }

    printf("\n");

    return 0;
}
