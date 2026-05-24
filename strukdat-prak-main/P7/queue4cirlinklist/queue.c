/* Program : queue.c
   Author  : Bhaskoro Prayoga Utomo
   Kelas   : E
   Deskripsi: Implementasi queue menggunakan circular linked list
*/

#include "queue.h"
#include <stdlib.h>

/* Membuat queue kosong */
void CreateQueue(Queue *Q) {
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    Q->counter = 0;
}

/* Mengecek apakah queue kosong */
boolean IsQueuekEmpty(Queue Q) {
    return (Head(Q) == Nil);
}

/* Mengecek apakah queue penuh (untuk linked list circular tidak terbatas kecuali memori habis) */
boolean IsQueuekFull(Queue Q) {
    return false;
}

/* Menghitung jumlah elemen queue */
int NBElmt(Queue Q) {
    return Q.counter;
}

/* Menambahkan elemen ke queue (enqueue) */
void AddQueue(Queue *Q, infotype X) {
    address P = (address) malloc(sizeof(ElmStack));
    if (P != Nil) {
        P->Info = X;
        if (IsQueuekEmpty(*Q)) {
            Head(*Q) = P;
            Tail(*Q) = P;
            P->next = Head(*Q); // circular
        } else {
            Tail(*Q)->next = P;
            Tail(*Q) = P;
            Tail(*Q)->next = Head(*Q); // circular
        }
        Q->counter++;
    }
}

/* Menghapus elemen dari queue (dequeue) */
void DelQueue(Queue *Q, infotype *X) {
    if (!IsQueuekEmpty(*Q)) {
        address P = Head(*Q);
        *X = P->Info;

        if (Head(*Q) == Tail(*Q)) {
            Head(*Q) = Nil;
            Tail(*Q) = Nil;
        } else {
            Head(*Q) = Head(*Q)->next;
            Tail(*Q)->next = Head(*Q); // tetap circular
        }
        free(P);
        Q->counter--;
    }
}

/* Mencetak isi queue */
void PrintQueueInfo(Queue Q) {
    if (!IsQueuekEmpty(Q)) {
        address P = Head(Q);
        printf("Queue sekarang = [");
        int count = 0;
        while (count < Q.counter) {
            printf(" %d", P->Info);
            P = P->next;
            count++;
        }
        printf(" ]\n");
    } else {
        printf("Queue is empty.\n");
    }
}

/* Mengecek apakah suatu info ada di queue */
boolean isInfoKetemu(Queue Q, infotype X) {
    if (!IsQueuekEmpty(Q)) {
        address P = Head(Q);
        int count = 0;
        while (count < Q.counter) {
            if (P->Info == X) return true;
            P = P->next;
            count++;
        }
    }
    return false;
}

/* Mencari alamat elemen dalam queue */
address CariElemenQueue(Queue Q, int X) {
    if (!IsQueuekEmpty(Q)) {
        address P = Head(Q);
        int count = 0;
        while (count < Q.counter) {
            if (P->Info == X) return P;
            P = P->next;
            count++;
        }
    }
    return Nil;
}
