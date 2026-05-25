/* Program   : main.c
   Author    : 255081109 - bhaskoro prayoga utomo
   Kelas     : E
   Deskripsi : Program utama untuk menguji AddLast dengan menu switch-case
   Tanggal   :
*/

#include <stdio.h>
#include "doubleLinkList.h"

void PrintList(List L) {
    address P = First(L);
    printf("Isi list: ");
    while (P != Nil) {
        printf("%d ", Info(P));
        P = Next(P);
    }
    printf("\n");
}

int main() {
    List L;
    int pilihan, nilai;
    CreateList(&L);

    do {
        printf("\n=== MENU DOUBLE LINKED LIST ===\n");
        printf("1. Tambah elemen di akhir (AddLast)\n");
        printf("2. Tampilkan isi list\n");
        printf("3. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan nilai: ");
                scanf("%d", &nilai);
                AddLast(&L, nilai);
                printf("Elemen %d berhasil ditambahkan.\n", nilai);
                break;

            case 2:
                PrintList(L);
                break;

            case 3:
                printf("Program selesai.\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 3);

    return 0;
}
