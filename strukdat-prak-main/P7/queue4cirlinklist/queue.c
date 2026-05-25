/* Program : queue.c
   Author  : Bhaskoro Prayoga Utomo
   Kelas   : E - 255081109
*/

#include "queue.h"
#include <stdlib.h>

void CreateQueue(Queue *Q) {
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    Q->counter = 0;
}

boolean IsQueuekEmpty(Queue Q) {
    return (Head(Q) == Nil);
}

boolean IsQueuekFull(Queue Q) {
    return false;
}

int NBElmt(Queue Q) {
    return Q.counter;
}

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

void DelQueue(Queue *Q, infotype *X) {
    if (!IsQueuekEmpty(*Q)) {
        address P = Head(*Q);
        *X = P->Info;

        if (Head(*Q) == Tail(*Q)) {
            Head(*Q) = Nil;
            Tail(*Q) = Nil;
        } else {
            Head(*Q) = Head(*Q)->next;
            Tail(*Q)->next = Head(*Q);
        }
        free(P);
        Q->counter--;
    }
}

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
