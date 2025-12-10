// Radithya 10 / 12 / 2025
// Program ini dibuat dengan IDE CLion
// laporan.txt tersimpan di folder cmake-build-debug jika menggunakan CLion
// saya menyimpannya di path utama untuk menunjukkan sample txtnya

#include <stdio.h>
#include <string.h>
#include "jam.h"
#include "date.h"

int main() {
    char Nama[50];
    double JamR;
    int JumK;
    double TotB;
    jam durasi;
    date T;

    int pilihan, layanan;
    FILE *f;

    while (1) {
        puts("\n1. Input pelanggan");
        puts("2. Tampilkan laporan");
        puts("3. Keluar");
        printf("Pilihan: ");
        if (scanf("%d", &pilihan) != 1) break;

        if (pilihan == 1) {
            printf("Nama: ");
            scanf("%49s", Nama);

            printf("Tanggal transaksi (tgl bln thn): \n");
            BacaDate(&T);
            printf("- Layanan -\n1: Main PC\n2: Ngeprint\nPilih layanan: ");
            if (scanf("%d", &layanan) != 1) {
                puts("Input layanan salah.");
                continue;
            }

            JamR = 0.0;
            JumK = 0;
            TotB = 0.0;
            durasi.HH = durasi.MM = durasi.SS = 0;

            if (layanan == 1) {
                printf("Durasi (HH MM SS): ");
                if (scanf("%d %d %d", &durasi.HH, &durasi.MM, &durasi.SS) != 3) {
                    puts("Format durasi salah.");
                    continue;
                }
                JamR = JamToDetik(durasi) / 3600.0;
                TotB = 3000.0 * JamR;
            } else if (layanan == 2) {
                printf("Jumlah lembar: ");
                if (scanf("%d", &JumK) != 1) {
                    puts("Input jumlah lembar salah");
                    continue;
                }
                JamR = 0.0;
                TotB = 250.0 * JumK;
            } else {
                puts("Layanan tidak ada");
                continue;
            }

            if (TotB > 10000.0) TotB -= 1000.0;

            f = fopen("laporan.txt", "a");
            if (f) {
                fprintf(f, "%s | %02d/%02d/%04d | %02d:%02d:%02d | Total durasi main: %.2f Jam | Lembar Print: %d | Rp %.2f\n",
                        Nama,
                        T.Tgl, T.Bln, T.Thn,
                        durasi.HH, durasi.MM, durasi.SS,
                        JamR,
                        JumK,
                        TotB);
                fclose(f);
                puts("Data disimpan di laporan.txt");
            } else {
                puts("Gagal buka laporan.txt");
            }

            printf("Ringkasan: %s | %02d/%02d/%04d | %02d:%02d:%02d (%.2f jam) | %d lembar | Rp%.2f\n",
                   Nama,
                   T.Tgl, T.Bln, T.Thn,
                   durasi.HH, durasi.MM, durasi.SS,
                   JamR, JumK, TotB);
        } else if (pilihan == 2) {
            char line[256];
            f = fopen("laporan.txt", "r");
            if (!f) {
                puts("Belum ada laporan.");
                continue;
            }
            puts("\n=== LAPORAN ===");
            while (fgets(line, sizeof(line), f)) fputs(line, stdout);
            fclose(f);
        } else if (pilihan == 3) {
            break;
        } else {
            puts("Pilihan tidak ada.");
        }
    }

    return 0;
}
