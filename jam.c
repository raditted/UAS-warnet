#include "jam.h"

/* Reset ke 00:00:00 */
void ResetJam(jam *J) {
    J->HH = 0;
    J->MM = 0;
    J->SS = 0;
}

void TulisJam(jam J) {
    printf("%02d:%02d:%02d", J.HH, J.MM, J.SS);
}

long JamToDetik(jam J) {
    return (J.HH * 3600) + (J.MM * 60) + J.SS;
}

jam DetikToJam(long d) {
    jam J;
    d %= 86400; // Jaga tetap 0–86399

    J.HH = d / 3600;
    d %= 3600;

    J.MM = d / 60;
    J.SS = d % 60;

    return J;
}

jam TimeToJam() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    jam J;
    J.HH = t->tm_hour;
    J.MM = t->tm_min;
    J.SS = t->tm_sec;

    return J;
}

jam Jumlah(jam J1, jam J2) {
    long total = JamToDetik(J1) + JamToDetik(J2);
    return DetikToJam(total);
}
