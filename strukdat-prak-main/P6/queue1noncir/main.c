#include <stdio.h>
#include <stdlib.h>  
#include "queue.h"

int main () {
    Queue Q;
    infotype X;
    int pilihan, nilai;

    CreateQueue(&Q);

    do {
        system("cls");   // clear screen sebelum tampilkan menu

        printf("QUEUE\n");
        printf("1. Tambah antrian\n");
        printf("2. Hapus antrian\n");
        printf("3. Cetak antrian\n");
        printf("4. Cari antrian\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                printf("Masukan antrian: ");
                scanf("%d", &nilai);
                AddQueue(&Q, nilai);
                break;
            case 2:
                DelQueue(&Q, &X);
                printf("Antrian dihapus bos\n");
                PrintQueueInfo(Q);
                break;
            case 3:
                PrintQueueInfo(Q);
                break;
            case 4:
                printf("Masukkan nilai yang dicari: ");
                scanf("%d", &nilai);
                if (isInfoKetemu(Q, nilai)) {
                    printf("Elemen %d ada di posisi %d bos\n", nilai, CariElemenQueue(Q, nilai));
                } else {
                    printf("Elemen %d gaada bos\n", nilai);
                }
                break;
            case 5:
                printf("Tengs bos.\n");
                break;
            default:
                printf("Nu bener.\n");
        }

        printf("\nTekan ENTER untuk lanjut...");
        getchar();
        getchar();
    } while (pilihan != 5);

    return 0;
}
