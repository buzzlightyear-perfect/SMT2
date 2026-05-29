#include "doubleLinkList.h"
#include <stdio.h>

boolean ListEmpty(List L) {
    return (First(L) == Nil);
}

void CreateList(List *L) {
    First(*L) = Nil;
}

address Alokasi(infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
    }
    return P;
}

void Dealokasi(address P) {
    free(P);
}

address Search(List L, infotype X) {
    address P = First(L);
    while (P != Nil && Info(P) != X) {
        P = Next(P);
    }
    return P;
}

void AddFirst(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        if (ListEmpty(*L)) {
            First(*L) = P;
        } else {
            Next(P) = First(*L);
            Prev(First(*L)) = P;
            First(*L) = P;
        }
    }
}

void AddLast(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        if (ListEmpty(*L)) {
            First(*L) = P;
        } else {
            address Q = First(*L);
            while (Next(Q) != Nil) {
                Q = Next(Q);
            }
            Next(Q) = P;
            Prev(P) = Q;
        }
    }
}

void DelFirst(List *L, infotype *X) {
    if (!ListEmpty(*L)) {
        address P = First(*L);
        *X = Info(P);
        First(*L) = Next(P);
        if (First(*L) != Nil) {
            Prev(First(*L)) = Nil;
        }
        Dealokasi(P);
    }
}

void DelLast(List *L, infotype *X) {
    if (!ListEmpty(*L)) {
        address P = First(*L);
        if (Next(P) == Nil) {
            *X = Info(P);
            First(*L) = Nil;
            Dealokasi(P);
        } else {
            while (Next(P) != Nil) {
                P = Next(P);
            }
            *X = Info(P);
            Next(Prev(P)) = Nil;
            Dealokasi(P);
        }
    }
}

void PrintList(List L) {
    address P = First(L);
    printf("Isi List: ");
    while (P != Nil) {
        printf("%d ", Info(P));
        P = Next(P);
    }
    printf("\n");
}
