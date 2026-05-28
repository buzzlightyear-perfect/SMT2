#ifndef PENDATAAN_H
#define PENDATAAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"

#define MAX 100

// ================= LINKED LIST DATA BARANG =================

typedef struct Barang {
    int id;
    char nama[50];
    int stok;
    struct Barang *next;
} Barang;

Barang *createBarang(int id, char nama[], int stok);
void tambahBarang(Barang **head, int id, char nama[], int stok);
void tampilBarang(Barang *head);
Barang* cariBarang(Barang *head, int id);


// ================= DOUBLE LINKED LIST LOG =================

typedef struct Log {
    char aktivitas[100];
    struct Log *prev;
    struct Log *next;
} Log;

void tambahLog(Log **head, char aktivitas[]);
void tampilLog(Log *head);

#endif