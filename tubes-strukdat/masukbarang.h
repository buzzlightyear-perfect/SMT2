#ifndef MASUK_BARANG_H
#define MASUK_BARANG_H

#include "pendataan.h"

// ================= QUEUE BARANG MASUK =================

typedef struct QueueNode {
    int id;
    int jumlah;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

void initQueue(Queue *q);
boolean isQueueEmpty(Queue *q);
void enqueue(Queue *q, int id, int jumlah);
void prosesBarangMasuk(Queue *q, Barang *head, Log **logHead);
void tampilQueue(Queue *q);

#endif