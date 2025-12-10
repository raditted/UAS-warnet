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
void BacaDate(date *D);
void PrintObj(date D);
/* Validasi & util */
bool isValid(date D);
bool isKabisat(date D);
int TglAkhir(date D);

/* Operasi tanggal */
void DateBefore(date D);
void NextDate(date D);
int SelisihDate(date D1, date D2);

#endif
