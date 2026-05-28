#include "pendataan.h"

Barang *createBarang(int id, char nama[], int stok) {
    Barang *baru = (Barang*)malloc(sizeof(Barang));

    baru->id = id;
    strcpy(baru->nama, nama);
    baru->stok = stok;
    baru->next = NULL;

    return baru;
}

void tambahBarang(Barang **head, int id, char nama[], int stok) {
    Barang *baru = createBarang(id, nama, stok);

    if (*head == NULL) {
        *head = baru;
    } else {
        Barang *temp = *head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = baru;
    }
}

Barang* cariBarang(Barang *head, int id) {
    Barang *temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

void tampilBarang(Barang *head) {
    Barang *temp = head;

    printf("\n===== DATA BARANG =====\n");

    while (temp != NULL) {
        printf("ID    : %d\n", temp->id);
        printf("Nama  : %s\n", temp->nama);
        printf("Stok  : %d\n", temp->stok);
        printf("----------------------\n");

        temp = temp->next;
    }
}


// ================= DOUBLE LINKED LIST LOG =================

void tambahLog(Log **head, char aktivitas[]) {
    Log *baru = (Log*)malloc(sizeof(Log));

    strcpy(baru->aktivitas, aktivitas);
    baru->next = NULL;
    baru->prev = NULL;

    if (*head == NULL) {
        *head = baru;
    } else {
        Log *temp = *head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = baru;
        baru->prev = temp;
    }
}

void tampilLog(Log *head) {
    Log *temp = head;

    printf("\n===== LOG AKTIVITAS =====\n");

    while (temp != NULL) {
        printf("- %s\n", temp->aktivitas);
        temp = temp->next;
    }
}