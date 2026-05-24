#include "queue.h"
#include <stdio.h>

void CreateQueue(Queue *Q){
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

int NBElmt (Queue Q){
    return (Q.HEAD);
}

boolean IsQueueEmpty(Queue Q) {
    return ((Q.HEAD == Nil) && (Q.TAIL == Nil));
}

boolean IsQueueFull (Queue Q) {
    return (Q.TAIL == MaxEl);
}

void AddQueue(Queue *Q, infotype X) {
    if (IsQueueFull(*Q)) {
        printf("Queue penuh bos\n");
    } else {
        if (IsQueueEmpty(*Q)) {
            Q->HEAD = 1;
            Q->TAIL = 1;
        } else {
            Q->TAIL++;
        }
        Q->T[Q->TAIL] = X;
    }
}

void DelQueue (Queue *Q, infotype *X){
    if (IsQueueEmpty(*Q)){
        printf("queue kosong bos\n");
    } else {
        int a;
        *X = InfoHead(*Q);
        for (a = Q->HEAD; a < Q->TAIL; a++){
            Q->T[a] = Q->T[a+1];
        }
        Q->TAIL--;

        if (Q->TAIL < Q->HEAD) {
            Q->HEAD = Nil;
            Q->TAIL = Nil;
        }
    }
}

void PrintQueueInfo(Queue Q){
    if (IsQueueEmpty(Q)){
        printf("queue kosong bos\n");
    } else {
        int s;
        printf("isi queue nya bos: ");
        for (s = Q.HEAD; s <= Q.TAIL; s++){
            printf ("%d ", Q.T[s]);
        }
        printf("\n");
    }
}

boolean isInfoKetemu(Queue Q, infotype X){
    int l;
    if (IsQueueEmpty(Q)) return false;
    
    for(l = Q.HEAD; l <= Q.TAIL; l++){
        if(Q.T[l] == X) return true;
    }
    return false;
}

address CariElemenQueue(Queue Q, int X){
    int o;
    if (IsQueueEmpty(Q)) return Nil;
    
    for (o = Q.HEAD; o <= Q.TAIL; o++){
        if (Q.T[o] == X) return o;
    }
    return Nil;
}