#include "point.c"
#include <stdio.h>
#include <stdbool.h>

int main() {
    POINT P1, P2, result;
    float deltaX, deltaY, angle;

    // Create and display points
    CreatePoint(&P1, 3.0, 4.0);
    CreatePoint(&P2, 1.0, 2.0);
    printf("P1: ");
    TulisPOINT(P1);
    printf("P2: ");
    TulisPOINT(P2);

    // Test EQ and NEQ
    printf("P1 == P2: %d\n", EQ(P1, P2));
    printf("P1 != P2: %d\n", NEQ(P1, P2));

    // Test IsOrigin, IsOnSbX, IsOnSbY
    printf("P1 is origin: %d\n", IsOrigin(P1));
    printf("P1 is on X axis: %d\n", IsOnSbX(P1));
    printf("P1 is on Y axis: %d\n", IsOnSbY(P1));

    // Test Kuadran
    printf("P1 is in quadrant: %d\n", Kuadran(P1));

    // Test NextX and NextY
    result = NextX(P1);
    printf("P1 after NextX: ");
    TulisPOINT(result);
    result = NextY(P1);
    printf("P1 after NextY: ");
    TulisPOINT(result);

    // Test PlusDelta
    deltaX = 2.0;
    deltaY = 3.0;
    result = PlusDelta(P1, deltaX, deltaY);
    printf("P1 after PlusDelta: ");
    TulisPOINT(result);

    // Test MirrorOf
    result = MirrorOf(P1, true);
    printf("P1 mirrored over X axis: ");
    TulisPOINT(result);
    result = MirrorOf(P1, false);
    printf("P1 mirrored over Y axis: ");
    TulisPOINT(result);

    // Test Jarak0 and Panjang
    printf("Distance from P1 to origin: %.2f\n", Jarak0(P1));
    printf("Distance between P1 and P2: %.2f\n", Panjang(P1, P2));

    // Test Geser
    Geser(&P1, deltaX, deltaY);
    printf("P1 after Geser: ");
    TulisPOINT(P1);

    // Test GeserKeSbX and GeserKeSbY
    GeserKeSbX(&P1);
    printf("P1 after GeserKeSbX: ");
    TulisPOINT(P1);
    GeserKeSbY(&P1);
    printf("P1 after GeserKeSbY: ");
    TulisPOINT(P1);

    // Test Mirror
    Mirror(&P1, true);
    printf("P1 after Mirror over X axis: ");
    TulisPOINT(P1);
    Mirror(&P1, false);
    printf("P1 after Mirror over Y axis: ");
    TulisPOINT(P1);

    // Test Putar
    angle = 90.0; // Rotate 90 degrees
    Putar(&P1, angle);
    printf("P1 after rotating 90 degrees: ");
    TulisPOINT(P1);

    // Test PersamaanLinearDuaVariabel
    PersamaanLinearDuaVariabel(P1, P2);

    return 0;
}