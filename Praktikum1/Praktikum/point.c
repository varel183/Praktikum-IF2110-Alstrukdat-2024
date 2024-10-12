#include "point.h"
#include <stdio.h>
#include <math.h>

void CreatePoint(POINT *P, float X, float Y) {
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void BacaPOINT(POINT *P) {
    float X, Y;
    scanf("%f %f", &X, &Y);
    CreatePoint(P, X, Y);
}

void TulisPOINT(POINT P) {
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ(POINT P1, POINT P2) {
    return Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2);
}

boolean NEQ(POINT P1, POINT P2) {
    return !EQ(P1, P2);
}

boolean IsOrigin(POINT P) {
    return Absis(P) == 0 && Ordinat(P) == 0;
}

boolean IsOnSbX(POINT P) {
    return Ordinat(P) == 0;
}

boolean IsOnSbY(POINT P) {
    return Absis(P) == 0;
}

int Kuadran(POINT P) {
    if (Absis(P) > 0 && Ordinat(P) > 0) {
        return 1;
    } else if (Absis(P) < 0 && Ordinat(P) > 0) {
        return 2;
    } else if (Absis(P) < 0 && Ordinat(P) < 0) {
        return 3;
    } else {
        return 4;
    }
} 

POINT NextX(POINT P) {
    Absis(P) += 1;
    return P;
}

POINT NextY(POINT P) {
    Ordinat(P) += 1;
    return P;
}

POINT PlusDelta(POINT P, float deltaX, float deltaY) {
    Absis(P) += deltaX;
    Ordinat(P) += deltaY;
    return P;
}

POINT MirrorOf(POINT P, boolean SbX) {
    if (SbX) {
        Ordinat(P) *= -1;
    } else {
        Absis(P) *= -1;
    }
    return P;
}

float Jarak0(POINT P) {
    return sqrt(Absis(P) * Absis(P) + Ordinat(P) * Ordinat(P));
}

float Panjang(POINT P1, POINT P2) {
    return sqrt(pow(Absis(P1) - Absis(P2), 2) + pow(Ordinat(P1) - Ordinat(P2), 2));
}

void Geser(POINT *P, float deltaX, float deltaY) {
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX(POINT *P) {
    Ordinat(*P) = 0;
}

void GeserKeSbY(POINT *P) {
    Absis(*P) = 0;
}

void Mirror(POINT *P, boolean SbX) {
    if (SbX) {
        Ordinat(*P) *= -1;
    } else {
        Absis(*P) *= -1;
    }
}

void Putar(POINT *P, float Sudut) {
    float x, y;
    const float PI = 4*atan(1);
    float deg = - Sudut * (PI/180);
    x = cos(deg)*Absis(*P) - sin(deg)*Ordinat(*P);
    y = sin(deg)*Absis(*P) + cos(deg)*Ordinat(*P);
    Absis(*P) = x;
    Ordinat(*P) = y;
}

void PersamaanLinearDuaVariabel(POINT P1, POINT P2) {
    int a = (int)((Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1)));
    int b = (int)(Ordinat(P1) - a * Absis(P1));
    printf("(%d,%d)", a, b);
}