/* Program : main.c
   Author  : Bhaskoro Prayoga Utomo
   Kelas   : E - 2550081109
*/

#include "queue.h"
#include <stdio.h>

int main() {
    Queue Q;
    CreateQueue(&Q);

    int pilihan, x;
    infotype val;
    address pos;

    do {
        printf("\n=== MENU QUEUE CIRCULAR LINKED LIST ===\n");
        printf("1. Enqueue (AddQueue)\n");
        printf("2. Dequeue (DelQueue)\n");
        printf("3. Print Queue\n");
        printf("4. Jumlah Elemen (NBElmt)\n");
        printf("5. Cari Elemen (CariElemenQueue)\n");
        printf("6. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan nilai: ");
                scanf("%d", &x);
                AddQueue(&Q, x);
                printf(">> %d berhasil ditambahkan ke queue.\n", x);
                break;

            case 2:
                if (!IsQueuekEmpty(Q)) {
                    DelQueue(&Q, &val);
                    printf(">> %d berhasil dihapus dari queue.\n", val);
                } else {
                    printf("Queue kosong, tidak bisa dequeue.\n");
                }
                break;

            case 3:
                PrintQueueInfo(Q);
                break;

            case 4:
                printf("Jumlah elemen dalam queue = %d\n", NBElmt(Q));
                break;

            case 5:
                printf("Masukkan nilai yang dicari: ");
                scanf("%d", &x);
                pos = CariElemenQueue(Q, x);
                if (pos != Nil) {
                    printf(">> Elemen %d ditemukan di alamat %p\n", x, (void*)pos);
                } else {
                    printf(">> Elemen %d tidak ditemukan.\n", x);
                }
                break;

            case 6:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 6);

    return 0;
}
