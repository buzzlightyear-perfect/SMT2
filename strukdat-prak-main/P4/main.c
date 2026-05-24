#include "linkedlist.h"
#include <stdio.h>

void PrintList(List L) {
    address P = First(L);
    printf("Isi List: ");
    while (P != Nil) {
        printf("%d -> ", Info(P));
        P = Next(P);
    }
    printf("NULL\n");
}

int main() {
    List L;
    int pilihan, angka, hapus;

    CreateList(&L);

    printf("=== Program Linked List ===\n");
    printf("Nama   : Bhaskoro Prayoga Utomo\n");
    printf("NIM    : 2550082001\n");
    printf("Kelas  : E-26\n\n");

    do {
        printf("Menu:\n");
        printf("1. Insert First\n");
        printf("2. Delete First\n");
        printf("3. Tampilkan List\n");
        printf("4. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan angka: ");
                scanf("%d", &angka);
                InsFirst(&L, angka);
                PrintList(L);
                break;

            case 2:
                if (!ListEmpty(L)) {
                    DelFirst(&L, &hapus);
                    printf("Data dihapus: %d\n", hapus);
                } else {
                    printf("List kosong, tidak bisa hapus.\n");
                }
                PrintList(L);
                break;

            case 3:
                PrintList(L);
                break;

            case 4:
                printf("Keluar program.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }
        printf("\n");
    } while (pilihan != 4);

    return 0;
}

