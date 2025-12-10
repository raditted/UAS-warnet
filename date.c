#include "date.h"

/* Constructor default */
void CreateDate(date *D) {
    D->Tgl = 1;
    D->Bln = 1;
    D->Thn = 1900;
}

/* Selector */
int GetTgl(date D) { return D.Tgl; }
int GetBln(date D) { return D.Bln; }
int GetThn(date D) { return D.Thn; }

/* Modifier */
void SetTgl(int NewTgl, date *D) { D->Tgl = NewTgl; }
void SetBln(int NewBln, date *D) { D->Bln = NewBln; }
void SetThn(int NewThn, date *D) { D->Thn = NewThn; }

/* I/O */
void BacaDate(date *D) {
    printf("Tanggal (1-31): ");   if (scanf("%d", &D->Tgl) != 1) { CreateDate(D); return; }
    printf("Bulan (1-12): ");     if (scanf("%d", &D->Bln) != 1) { CreateDate(D); return; }
    printf("Tahun: ");           if (scanf("%d", &D->Thn) != 1) { CreateDate(D); return; }

    if (!isValid(*D)) {
        printf("Data tidak valid — di-reset ke 01/01/1900\n");
        CreateDate(D);
    }
}

void PrintObj(date D) {
    printf("%02d/%02d/%04d\n", GetTgl(D), GetBln(D), GetThn(D));
}

/* Validasi & util */
bool isKabisat(date D) {
    int y = GetThn(D);
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return (y % 4 == 0);
}

int TglAkhir(date D) {
    int b = GetBln(D);
    if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
        return 31;
    else if (b == 4 || b == 6 || b == 9 || b == 11)
        return 30;
    else /* Februari */
        return isKabisat(D) ? 29 : 28;
}

bool isValid(date D) {
    if (GetThn(D) < 1900 || GetThn(D) > 30000) return false;
    if (GetBln(D) < 1 || GetBln(D) > 12) return false;
    if (GetTgl(D) < 1 || GetTgl(D) > TglAkhir(D)) return false;
    return true;
}

/* Operasi tanggal */
void DateBefore(date D) {
    printf("Sebelum tanggal: ");
    PrintObj(D);

    date tmp = D;
    if (GetTgl(tmp) == 1) {
        if (GetBln(tmp) == 1) {
            SetThn(GetThn(tmp) - 1, &tmp);
            SetBln(12, &tmp);
            SetTgl(TglAkhir(tmp), &tmp);
        } else {
            SetBln(GetBln(tmp) - 1, &tmp);
            SetTgl(TglAkhir(tmp), &tmp);
        }
    } else {
        SetTgl(GetTgl(tmp) - 1, &tmp);
    }

    printf(" adalah tanggal: ");
    PrintObj(tmp);
}

void NextDate(date D) {
    printf("Setelah tanggal: ");
    PrintObj(D);

    date tmp = D;
    if (GetTgl(tmp) == TglAkhir(tmp)) {
        if (GetBln(tmp) == 12) {
            SetThn(GetThn(tmp) + 1, &tmp);
            SetBln(1, &tmp);
            SetTgl(1, &tmp);
        } else {
            SetBln(GetBln(tmp) + 1, &tmp);
            SetTgl(1, &tmp);
        }
    } else {
        SetTgl(GetTgl(tmp) + 1, &tmp);
    }

    printf(" adalah tanggal: ");
    PrintObj(tmp);
}

/* SelisihDate: kembalikan selisih D2 - D1 dalam hari
   Implementasi sederhana: hitung hari dengan asumsi 1 thn = 365 hari,
   tetap mempertimbangkan jumlah hari antar bulan di tahun yang sama
*/
int SelisihDate(date D1, date D2) {
    /* Normalisasi: jika D2 lebih kecil dari D1, kita bisa jadi negatif */
    int sign = 1;
    /* Bandingkan tahun, bulan, tanggal */
    if (GetThn(D1) > GetThn(D2) ||
       (GetThn(D1) == GetThn(D2) && GetBln(D1) > GetBln(D2)) ||
       (GetThn(D1) == GetThn(D2) && GetBln(D1) == GetBln(D2) && GetTgl(D1) > GetTgl(D2))) {
        /* swap */
        date tmp = D1; D1 = D2; D2 = tmp;
        sign = -1;
    }

    int days = 0;
    if (GetThn(D1) == GetThn(D2) && GetBln(D1) == GetBln(D2)) {
        days = GetTgl(D2) - GetTgl(D1);
        return sign * days;
    }

    /* Tambah sisa hari pada bulan D1 */
    days += TglAkhir(D1) - GetTgl(D1);
    /* Tambah hari sampai akhir tahun D1 (bulan setelah bulan D1) */
    for (int m = GetBln(D1) + 1; m <= 12; ++m) {
        date tmp = D1;
        SetBln(m, &tmp);
        days += TglAkhir(tmp);
    }

    /* Tambah hari untuk tahun penuh di antara */
    for (int y = GetThn(D1) + 1; y < GetThn(D2); ++y) {
        date tmp;
        SetThn(y, &tmp);
        /* default month doesn't matter for isKabisat if we only check year */
        tmp.Tgl = 1; tmp.Bln = 1;
        days += isKabisat(tmp) ? 366 : 365;
    }

    /* Tambah hari dari awal tahun D2 sampai bulan sebelum D2 */
    for (int m = 1; m < GetBln(D2); ++m) {
        date tmp;
        SetThn(GetThn(D2), &tmp);
        SetBln(m, &tmp);
        tmp.Tgl = 1;
        days += TglAkhir(tmp);
    }

    /* Tambah hari di bulan D2 */
    days += GetTgl(D2);

    return sign * days;
}
