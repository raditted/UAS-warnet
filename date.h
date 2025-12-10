#ifndef DATE_H
#define DATE_H

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int Tgl;
    int Bln;
    int Thn;
} date;

/* Constructor default: 01/01/1900 */
void CreateDate(date *D);

/* Selector */
int GetTgl(date D);
int GetBln(date D);
int GetThn(date D);

/* Modifier */
void SetTgl(int NewTgl, date *D);
void SetBln(int NewBln, date *D);
void SetThn(int NewThn, date *D);

/* I/O */
void BacaDate(date *D);      /* baca dari stdin */
void PrintObj(date D);       /* cetak dd/mm/yyyy */

/* Validasi & util */
bool isValid(date D);
bool isKabisat(date D);
int TglAkhir(date D);

/* Operasi tanggal */
void DateBefore(date D);     /* tampilkan tanggal sebelumnya */
void NextDate(date D);       /* tampilkan tanggal berikutnya */
int SelisihDate(date D1, date D2); /* kembalikan selisih dalam hari (asumsi 1 thn = 365 hari) */

#endif
