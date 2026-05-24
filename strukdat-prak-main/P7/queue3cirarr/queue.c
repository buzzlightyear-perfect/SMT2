#include "boolean.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void CreateQueue(Queue *Q){
    Q->HEAD = Nil;
    Q->TAIL = Nil;
}

int NBElmt(Queue Q){
    if (IsQueuekEmpty(Q)){
        return 0;
    } else {
        if (Q.TAIL >= Q.HEAD){
            return (Q.TAIL - Q.HEAD + 1);
        } else {
            return (MaxEl - Q.HEAD + 1 + Q.TAIL);
        }
    }
}

boolean IsQueuekEmpty (Queue Q){
    return (Q.TAIL == Nil && Q.HEAD == Nil);
}

boolean IsQueuekFull(Queue Q){
    return (NBElmt(Q) == MaxEl);
}

void AddQueue (Queue *Q, infotype X){
    if (IsQueuekFull(*Q)){
        printf("antrian penuh bos");
    } else {
        if (IsQueuekEmpty(*Q)){
            Q->HEAD = 1;
            Q->TAIL = 1;
        } else {
            Q->TAIL = (Q->TAIL % MaxEl) + 1;
        }
        Q->T[Q->TAIL] = X;
    }
}

void DelQueue (Queue *Q, infotype *X){
    if (IsQueuekEmpty(*Q)){
        printf("antrian kosong bos");
    } else {
        *X = Q->T[Q->HEAD];
        if (Q->HEAD == Q->TAIL){
            Q->HEAD = Nil;
            Q->TAIL = Nil;
        } else {
            Q->HEAD = (Q->HEAD % MaxEl ) + 1;
        }
    }
}

void PrintQueueInfo (Queue Q){
    if (IsQueuekEmpty(Q)){
        printf("antrian kosong bos");
    } else {
        int e;
        printf("isi antrian: ");
        e = Q.HEAD;
        while (1) {
            printf("%d ", Q.T[e]);
            if (e == Q.TAIL)
                break;
            e = (e % MaxEl) + 1;
        }
    }
}

boolean isInfoKetemu(Queue S, infotype X){
    if (IsQueuekEmpty(S)){
        return false;
    }
    int u;
    u = S.HEAD;
    while (1) {
        if (S.T[u] == X) {
            return true;
        }
        if (u == S.TAIL){
            break;
        }
        u = (u % MaxEl) + 1;
    }
    return false;
}

address CariElemenQueue(Queue Q, int X){
    if (IsQueuekEmpty(Q)) {
        return Nil;
    } else {
        int y;
        y = Q.HEAD;
        while (1) {
            if (Q.T[y] == X){
                return y;
            }
            if (y == Q.TAIL)
                break;
            y = (y % MaxEl) + 1;
        }
        return Nil;
    }
}