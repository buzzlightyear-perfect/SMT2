#ifndef KELUAR_BARANG_H
#define KELUAR_BARANG_H

#include "pendataan.h"

// ================= STACK BARANG KELUAR =================

typedef struct StackNode {
    int id;
    int jumlah;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
} Stack;

void initStack(Stack *s);
boolean isStackEmpty(Stack *s);
void push(Stack *s, int id, int jumlah);
void prosesBarangKeluar(Stack *s, Barang *head, Log **logHead);
void tampilStack(Stack *s);

#endif