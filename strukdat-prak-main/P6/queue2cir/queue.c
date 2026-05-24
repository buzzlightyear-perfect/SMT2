#include<stdio.h>
#include "queue.h"

void CreateQueue(Queue *Q) {
    Q->HEAD = Nil;
    Q->TAIL = Nil;
};

int NBElmt(Queue Q){
    if (IsQueuekEmpty(Q)) {
        return 0;
    } else if (Q.TAIL >= Q.HEAD){
        return Q.TAIL - Q.HEAD + 1;
    } else {
        return MaxEl - (Q.HEAD - Q.TAIL - 1);
    }
};

boolean IsQueuekEmpty (Queue Q) {
    return ((Q.HEAD == Nil) && (Q.TAIL == Nil));
};

boolean IsQueuekFull (Queue Q) {
    return ((Tail(Q) % MaxEl) + 1 == Head(Q));
};

void AddQueue (Queue *Q, infotype X) {
    if (!IsQueuekFull(*Q)) {
        if (IsQueuekEmpty(*Q)) {
            Q->HEAD = 1;
            Q->TAIL = 1;
        } else {
            Q->TAIL = (Q->TAIL % MaxEl) + 1;
        }
        Q->T[Q->TAIL] = X;
    } else {
        printf("Queue penuh, data tidak dapat ditambahkan.\n");
    }
}

void DelQueue (Queue *Q, infotype *X) {
    if (!IsQueuekEmpty(*Q)) {
        *X = InfoHead(*Q);
        if (Q->HEAD == Q->TAIL) {
            Q->HEAD = Nil;
            Q->TAIL = Nil;
        } else {
            Q->HEAD = (Q->HEAD % MaxEl) + 1;
        }
    } else {
        printf("Queue kosong, tidak ada data untuk dihapus.\n");
    }
}

void PrintQueueInfo (Queue Q){
    if (IsQueuekEmpty(Q)) {
        printf("Antrian kosong bos\n");
    } else {
        int p;
        printf("Isi antrian bos: ");
        p = Head(Q);
        while (1) {
            printf("%d ", Q.T[p]);
            if (p == Q.TAIL) break;
            p = (p % MaxEl) + 1;
        }
        printf("\n");
    }
}

boolean isInfoKetemu(Queue Q, infotype X){
    int f;
    if (IsQueuekEmpty(Q)) return false;
    f = Head(Q);
    while(1) {
        if (Q.T[f] == X) return true;
        if (f == Q.TAIL) break;
        f = (f % MaxEl) + 1;
    }
    return false;
};

address CariElemenQueue(Queue Q, int X) {
    int k;
    if (IsQueuekEmpty(Q)) return Nil;
    k = Head(Q);
    while (1) {
        if (Q.T[k] == X) return k;
        if (k == Q.TAIL) break;
        k = (k % MaxEl) + 1;
    }
    return Nil;
}