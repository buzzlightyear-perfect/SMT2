/* Program   : doubleLinkList.h
   Author    : Bhaskoro Prayoga Utomo - 2550081109
   Kelas     : E
   Deskripsi : Header file dari prototype double linked list
*/

#ifndef DOUBLELINKLIST_H
#define DOUBLELINKLIST_H

#include <stdlib.h>
#include "boolean.h"

#define Nil   NULL
#define Info(P)  (P)->info
#define Next(P)  (P)->next
#define Prev(P)  (P)->prev
#define First(L) ((L).First)

typedef int infotype;
typedef struct tElmtList *address;

typedef struct tElmtList {
    infotype info;
    address next;
    address prev;
} ElmtList;

typedef struct {
    address First;
} List;

/* Prototype Operasi List */
boolean ListEmpty(List L);
/* Mengirim TRUE jika list kosong */

void CreateList(List *L);
/* Membentuk sebuah list kosong */

address Alokasi(infotype X);
/* Menghasilkan address alokasi sebuah elemen */

void Dealokasi(address P);
/* Melakukan dealokasi/pengembalian address P */

address Search(List L, infotype X);
/* Menghasilkan address yang mengandung infotype X,
   jika tidak ada menghasilkan Nil */

void AddFirst(List *L, infotype X);
/* Menambahkan elemen X pada elemen pertama List */

void AddLast(List *L, infotype X);
/* Menambahkan elemen X pada elemen terakhir List */

void DelFirst(List *L, infotype *X);
/* Menghapus elemen pertama List */

void DelLast(List *L, infotype *X);
/* Menghapus elemen terakhir List */

#endif
