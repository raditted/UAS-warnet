#ifndef JAM_H
#define JAM_H

#include <stdio.h>
#include <time.h>

typedef struct {
    int HH;
    int MM;
    int SS;
} jam;

/* Reset ke 00:00:00 */
void ResetJam(jam *J);

/* Tulis jam ke stdout */
void TulisJam(jam J);

/* Konversi jam → total detik */
long JamToDetik(jam J);

/* Konversi detik → jam */
jam DetikToJam(long d);

/* Mendapatkan jam sistem sekarang */
jam TimeToJam();

/* Menjumlahkan 2 jam (wrap ke 24 jam) */
jam Jumlah(jam J1, jam J2);

#endif
