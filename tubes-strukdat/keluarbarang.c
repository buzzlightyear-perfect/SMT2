#include "keluarbarang.h"

void initStack(Stack *s) {
    s->top = NULL;
}

boolean isStackEmpty(Stack *s) {
    return s->top == NULL;
}

void push(Stack *s, int id, int jumlah) {
    StackNode *baru = (StackNode*)malloc(sizeof(StackNode));

    baru->id = id;
    baru->jumlah = jumlah;
    baru->next = s->top;

    s->top = baru;
}

void prosesBarangKeluar(Stack *s, Barang *head, Log **logHead) {
    if (isStackEmpty(s)) {
        printf("Stack kosong!\n");
        return;
    }

    StackNode *hapus = s->top;

    Barang *barang = cariBarang(head, hapus->id);

    if (barang != NULL) {
        if (barang->stok >= hapus->jumlah) {
            barang->stok -= hapus->jumlah;

            char logText[100];
            sprintf(logText, "Barang keluar ID %d sebanyak %d", hapus->id, hapus->jumlah);
            tambahLog(logHead, logText);

            printf("Barang keluar berhasil diproses!\n");
        } else {
            printf("Stok tidak mencukupi!\n");
        }
    } else {
        printf("Barang tidak ditemukan!\n");
    }

    s->top = s->top->next;
    free(hapus);
}

void tampilStack(Stack *s) {
    StackNode *temp = s->top;

    printf("\n===== STACK BARANG KELUAR =====\n");

    while (temp != NULL) {
        printf("ID Barang : %d | Jumlah : %d\n", temp->id, temp->jumlah);
        temp = temp->next;
    }
}