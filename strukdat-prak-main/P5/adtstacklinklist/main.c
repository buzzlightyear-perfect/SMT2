/* 
Program   : main.c
Author    : 2550081109 - Bhaskoro Prayoga U
Kelas     : E
Deskripsi : Program utama untuk menguji operasi stack (linked list)
Tanggal   : 26/4/2026
*/

#include <stdio.h>
#include "stack.h"

int main() {
    Stack S;
    infotype X;
    int pilihan, nilai;

    CreateStack(&S);

    do {
        printf("\n=== MENU STACK (Linked List) ===\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Cetak isi stack\n");
        printf("4. Cari elemen\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan nilai: ");
                scanf("%d", &nilai);
                Push(&S, nilai);
                break;

            case 2:
                Pop(&S, &X);
                printf("Elemen yang di-pop: %d\n", X);
                break;

            case 3:
                CetakStack(S);
                break;

            case 4:
                printf("Masukkan nilai yang dicari: ");
                scanf("%d", &nilai);
                if (CariElemenStack(S, nilai)) {
                    printf("Elemen %d ditemukan dalam stack.\n", nilai);
                } else {
                    printf("Elemen %d tidak ada dalam stack.\n", nilai);
                }
                break;

            case 5:
                printf("Keluar program.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);

    return 0;
}

