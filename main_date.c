#include <stdio.h>
#include "date.h"

int main() {
    date D1, D2;
    CreateDate(&D1);
    printf("Hasil CreateDate: ");
    PrintObj(D1);

    SetTgl(27, &D2);
    SetBln(12, &D2);
    SetThn(1972, &D2);
    printf("Set D2 menjadi: ");
    PrintObj(D2);

    printf("\nMasukkan tanggal untuk D3:\n");
    date D3;
    BacaDate(&D3);
    printf("D3: ");
    PrintObj(D3);

    if (GetBln(D3) == 2) {
        if (isKabisat(D3)) printf("Tahun %d adalah kabisat\n", GetThn(D3));
        else printf("Tahun %d bukan kabisat\n", GetThn(D3));
    }

    DateBefore(D3);
    NextDate(D3);

    printf("\nMasukkan tanggal untuk D4:\n");
    date D4;
    BacaDate(&D4);
    printf("D4: ");
    PrintObj(D4);

    int selisih = SelisihDate(D3, D4);
    printf("Selisih D3 ke D4: %d hari\n", selisih);

    return 0;
}
