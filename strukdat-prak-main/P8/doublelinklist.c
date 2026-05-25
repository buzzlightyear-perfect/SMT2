#include <stdio.h>
#include <stdlib.h>
#include "doublelinklist.h"

boolean ListEmpty(List L){
    return (L.First == NULL);
};

void CreateList(List *L){
    L->First = Nil;
};
/* Membentuk sebuah list kosong */

address Alokasi(infotype X) {
    address P = (address) malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
    }
    return P;
}

void Dealokasi(address P){
    free(P);
};


address Search(List L, infotype X){
    address P = L.First;
    while (P != Nil) {
        if (P->info == X){
            return P;
        }
        P = P->next;
    }
    return Nil;
}
/* Menghasilkan address yang mengandung infotype X,
   jika tidak ada menghasilkan Nil */

void AddFirst(List *L, infotype X){
    address P = Alokasi(X);
    if (P != Nil) {
        if (ListEmpty(*L)){
            L->First = P;
        } else {
            P->next = L->First;
            Prev(L->First) = P;
            L->First = P;
        }
    }
};
/* Menambahkan elemen X pada elemen pertama List */

void AddLast(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        if (ListEmpty(*L)) {
            First(*L) = P;
        } else {
            address Last = First(*L);
            while (Next(Last) != Nil) {
                Last = Next(Last);
            }
            Next(Last) = P;
            Prev(P) = Last;
        }
    }
}

/* Menambahkan elemen X pada elemen terakhir List */
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
/* Menghapus elemen pertama List */

void DelLast(List *L, infotype *X) {
    if (!ListEmpty(*L)) {
        address Last = First(*L);
        if (Next(Last) == Nil) {
            *X = Info(Last);
            First(*L) = Nil;
            Dealokasi(Last);
        } else {
            while (Next(Last) != Nil) {
                Last = Next(Last);
            }
            *X = Info(Last);
            Next(Prev(Last)) = Nil;
            Dealokasi(Last);
        }
    }
}
/* Menghapus elemen terakhir List */

