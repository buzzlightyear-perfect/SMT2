#include "masukbarang.h"

void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

boolean isQueueEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, int id, int jumlah) {
    QueueNode *baru = (QueueNode*)malloc(sizeof(QueueNode));

    baru->id = id;
    baru->jumlah = jumlah;
    baru->next = NULL;

    if (isQueueEmpty(q)) {
        q->front = baru;
        q->rear = baru;
    } else {
        q->rear->next = baru;
        q->rear = baru;
    }
}

void prosesBarangMasuk(Queue *q, Barang *head, Log **logHead) {
    if (isQueueEmpty(q)) {
        printf("Queue kosong!\n");
        return;
    }

    QueueNode *hapus = q->front;

    Barang *barang = cariBarang(head, hapus->id);

    if (barang != NULL) {
        barang->stok += hapus->jumlah;

        char logText[100];
        sprintf(logText, "Barang masuk ID %d sebanyak %d", hapus->id, hapus->jumlah);
        tambahLog(logHead, logText);

        printf("Barang masuk berhasil diproses!\n");
    } else {
        printf("Barang tidak ditemukan!\n");
    }

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(hapus);
}

void tampilQueue(Queue *q) {
    QueueNode *temp = q->front;

    printf("\n===== QUEUE BARANG MASUK =====\n");

    while (temp != NULL) {
        printf("ID Barang : %d | Jumlah : %d\n", temp->id, temp->jumlah);
        temp = temp->next;
    }
}