#ifndef JAM_H
#define JAM_H

#include <stdio.h>
#include <time.h>

typedef struct {
    int HH;
    int MM;
    int SS;
} jam;

void ResetJam(jam *J);

void TulisJam(jam J);

long JamToDetik(jam J);

jam DetikToJam(long d);

jam TimeToJam();

jam Jumlah(jam J1, jam J2);

#endif
