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
    int pilihan, angka, hapus, target;

    CreateList(&L);

    do {
        printf("\n=== MENU LINKED LIST ===\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Insert After\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete After\n");
        printf("7. Hitung Jumlah Elemen\n");
        printf("8. Search Elemen\n");
        printf("9. Invers List\n");
        printf("10. Tampilkan List\n");
        printf("0. Keluar\n");
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
                printf("Masukkan angka: ");
                scanf("%d", &angka);
                InsLast(&L, angka);
                PrintList(L);
                break;

            case 3:
                printf("Masukkan angka baru: ");
                scanf("%d", &angka);
                printf("Masukkan angka target (setelah elemen ini): ");
                scanf("%d", &target);
                InsAfter(&L, angka, target);
                PrintList(L);
                break;

            case 4:
                if (!ListEmpty(L)) {
                    DelFirst(&L, &hapus);
                    printf("Data dihapus: %d\n", hapus);
                } else {
                    printf("List kosong.\n");
                }
                PrintList(L);
                break;

            case 5:
                if (!ListEmpty(L)) {
                    DelLast(&L, &hapus);
                    printf("Data dihapus: %d\n", hapus);
                } else {
                    printf("List kosong.\n");
                }
                PrintList(L);
                break;

            case 6:
                printf("Masukkan angka target (hapus setelah elemen ini): ");
                scanf("%d", &target);
                DelAfter(&L, &hapus, target);
                printf("Data dihapus: %d\n", hapus);
                PrintList(L);
                break;

            case 7:
                printf("Jumlah elemen: %d\n", NbElmt(L));
                break;

            case 8:
                printf("Masukkan angka yang dicari: ");
                scanf("%d", &target);
                if (Search(L, target) != Nil) {
                    printf("Data %d ditemukan.\n", target);
                } else {
                    printf("Data %d tidak ada.\n", target);
                }
                break;

            case 9:
                InversList(&L);
                printf("List dibalik.\n");
                PrintList(L);
                break;

            case 10:
                PrintList(L);
                break;

            case 0:
                printf("Keluar program.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);

    return 0;
}

