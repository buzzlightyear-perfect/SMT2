#include <stdio.h>
#include<stdlib.h>
#include "queue.h"

int main() {
    Queue Q;
    CreateQueue(&Q);
    int pilihan, x;

    do {
        printf("\nQUEUE CIRCULAR ARRAY\n");
        printf("1. Tambah antrian bos\n");
        printf("2. Hapus antrian bos\n");
        printf("3. Cetak antrian\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                system("cls");
                printf("Masukkan nilai: ");
                scanf("%d", &x);
                AddQueue(&Q, x);
                break;
            case 2:
                if (!IsQueuekEmpty(Q)) {
                    DelQueue(&Q, &x);
                    printf("Antrian dihapus bos: %d\n", x);
                } else {
                    DelQueue(&Q, &x);
                }
                break;
            case 3:
                PrintQueueInfo(Q);
                break;
        }
    } while (pilihan != 0);

    return 0;
}
