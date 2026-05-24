#include <stdio.h>
#include "queue.h"


int main () {
Queue Q;
infotype X;
int pilihan, nilai;

CreateQueue(&Q);

do {
    printf("QUEUE\n");
    printf("1. Tambah antrian\n");
    printf("2. hapus antrian\n");
    printf("3. cetak antrian\n");
    printf("4. cari antrian\n");
    printf("5. keluar\n");
    printf("pilihan: ");
    scanf("%d", &pilihan);

    switch(pilihan) {
        case 1:
            printf("masukan antrian:");
            scanf("%d", &nilai);
            AddQueue(&Q, nilai);
            break;
        case 2:
            DelQueue(&Q, &X);
            printf("antrian dihapus bos\n");
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
            printf("tengs bos.\n");
            break;

        default:
            printf("nu bener.\n");
    }
} while (pilihan != 5);

return 0;
}