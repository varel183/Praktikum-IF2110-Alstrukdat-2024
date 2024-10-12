#include "complex.h"
#include <stdio.h>
#include <math.h> 

boolean IsCOMPLEXValid(float Re, float Im) {
    return true;
}

void CreateComplex(COMPLEX *C, float Re, float Im) {
    *C = (COMPLEX){Re, Im};
}

void BacaCOMPLEX(COMPLEX *C) {
    float Re, Im;
    scanf("%f %f", &Re, &Im);
    CreateComplex(C, Re, Im);
}

void TulisCOMPLEX(COMPLEX C) {
    if (Imag(C) >= 0) {
        printf("%.2f+%.2fi\n", Real(C), Imag(C));
    } else {
        printf("%.2f-%.2fi\n", Real(C), -Imag(C));
    }
}

COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2) {
    return (COMPLEX){Real(C1) + Real(C2), Imag(C1) + Imag(C2)};
}

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2) {
    return (COMPLEX){Real(C1) - Real(C2), Imag(C1) - Imag(C2)};
}

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2) {
    return (COMPLEX){Real(C1) * Real(C2) - Imag(C1) * Imag(C2), Real(C1) * Imag(C2) + Imag(C1) * Real(C2)};
}

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2) {
    float denominator = Real(C2) * Real(C2) + Imag(C2) * Imag(C2);
    if (denominator == 0) {
        return (COMPLEX){0, 0};
    }
    COMPLEX result = MultiplyCOMPLEX(C1, ConjugateCOMPLEX(C2));
    return (COMPLEX){Real(result) / denominator, Imag(result) / denominator};
}

float AbsCOMPLEX(COMPLEX C) {
    return sqrt(Real(C) * Real(C) + Imag(C) * Imag(C));
}

COMPLEX ConjugateCOMPLEX(COMPLEX C) {
    return (COMPLEX){Real(C), -Imag(C)};
}

boolean CEQ(COMPLEX C1, COMPLEX C2) {
    return Real(C1) == Real(C2) && Imag(C1) == Imag(C2);
}

boolean CNEQ(COMPLEX C1, COMPLEX C2) {
    return Real(C1) != Real(C2) || Imag(C1) != Imag(C2);
}