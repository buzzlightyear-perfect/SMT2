#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkList.h"

int main() {
    List L;
    infotype X, cari;
    address P;
    int pilih;

    CreateList(&L);

    do {
        system("cls");

        printf("DOUBLE LINKED LIST\n");
        printf("1. Tambah Data di Awal\n");
        printf("2. Tambah Data di Akhir\n");
        printf("3. Hapus Data di Awal\n");
        printf("4. Hapus Data di Akhir\n");
        printf("5. Cari Data\n");
        printf("6. Tampilkan List\n");
        printf("0. Keluar\n");
        printf("Pilih menu : ");
        scanf("%d", &pilih);

        switch (pilih) {

            case 1:
                printf("Masukkan data : ");
                scanf("%d", &X);

                AddFirst(&L, X);

                printf("Data berhasil ditambahkan di awal.\n");
                break;

            case 2:
                printf("Masukkan data : ");
                scanf("%d", &X);

                AddLast(&L, X);

                printf("Data berhasil ditambahkan di akhir.\n");
                break;

            case 3:
                if (ListEmpty(L)) {
                    printf("List kosong.\n");
                } else {
                    DelFirst(&L, &X);
                    printf("Data %d berhasil dihapus dari awal.\n", X);
                }
                break;

            case 4:
                if (ListEmpty(L)) {
                    printf("List kosong.\n");
                } else {
                    DelLast(&L, &X);
                    printf("Data %d berhasil dihapus dari akhir.\n", X);
                }
                break;

            case 5:
                printf("Masukkan data yang dicari : ");
                scanf("%d", &cari);

                P = Search(L, cari);

                if (P != Nil) {
                    printf("Data %d ditemukan.\n", cari);
                } else {
                    printf("Data %d tidak ditemukan.\n", cari);
                }
                break;

            case 6:
                PrintList(L);
                break;

            case 0:
                printf("Program selesai.\n");
                break;

            default:
                printf("Menu tidak tersedia.\n");
        }

        if (pilih != 0) {
            printf("\nenter untuk melanjutkan");
            getchar();
            getchar();
        }

    } while (pilih != 0);

    return 0;
}