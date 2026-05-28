#include "pendataan.h"
#include "masukbarang.h"
#include "keluarbarang.h"

int main() {
    Barang *dataBarang = NULL;
    Log *logAktivitas = NULL;

    Queue barangMasuk;
    Stack barangKeluar;

    initQueue(&barangMasuk);
    initStack(&barangKeluar);

    int pilihan;

    do {
        printf("==============================\n");
        printf(" SISTEM PENDATAAN GUDANG\n");
        printf("==============================\n");
        printf("1. Tambah Data Barang\n");
        printf("2. Barang Masuk\n");
        printf("3. Barang Keluar\n");
        printf("4. Tampilkan Data Barang\n");
        printf("5. Tampilkan Log Aktivitas\n");
        printf("0. Keluar\n");

        printf("Pilih Menu : ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1: {
                int id, stok;
                char nama[50];

                printf("===== INPUT DATA BARANG =====\n");
                printf("Masukkan ID Barang    : ");
                scanf("%d", &id);

                printf("Masukkan Nama Barang  : ");
                scanf(" %[^\n]", nama);

                printf("Masukkan Stok Awal    : ");
                scanf("%d", &stok);

                tambahBarang(&dataBarang, id, nama, stok);

                char logText[100];
                sprintf(logText, "Admin menambahkan barang %s", nama);
                tambahLog(&logAktivitas, logText);

                printf("Data barang berhasil ditambahkan!\n");
                break;
            }

            case 2: {
                int id, jumlah;

                printf("===== BARANG MASUK =====\n");
                printf("Masukkan ID Barang : ");
                scanf("%d", &id);

                printf("Masukkan Jumlah   : ");
                scanf("%d", &jumlah);

                enqueue(&barangMasuk, id, jumlah);
                prosesBarangMasuk(&barangMasuk, dataBarang, &logAktivitas);

                break;
            }

            case 3: {
                int id, jumlah;

                printf("===== BARANG KELUAR =====\n");
                printf("Masukkan ID Barang : ");
                scanf("%d", &id);

                printf("Masukkan Jumlah   : ");
                scanf("%d", &jumlah);

                push(&barangKeluar, id, jumlah);
                prosesBarangKeluar(&barangKeluar, dataBarang, &logAktivitas);

                break;
            }

            case 4:
                tampilBarang(dataBarang);
                break;

            case 5:
                tampilLog(logAktivitas);
                break;

            case 0:
                printf("Program selesai.\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }
    } while(pilihan != 0);

    return 0;
}
