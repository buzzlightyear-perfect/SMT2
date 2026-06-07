#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "binarytree.h"


void CreateTree(Tree *T, int x, Tree L, Tree R) {
    *T = Alokasi(x);
    if (*T != nil) {
        left(*T) = L;
        right(*T) = R;
    }
}


address Alokasi(int X) {
    address P = (address) malloc(sizeof(Node));
    if (P != nil) {
        info(P) = X;
        left(P) = nil;
        right(P) = nil;
    }
    return P;
}


void DeAlokasi(address P) {
    free(P);
}


int getRoot(Tree T) {
    if (T != nil) {
        return info(T);
    }
    return -1;
}


Tree getLeft(Tree T) {
    if (T != nil) {
        return left(T);
    }
    return nil;
}


Tree getRight(Tree T) {
    if (T != nil) {
        return right(T);
    }
    return nil;
}


int TinggiPohon(Tree T) {
    if (T == nil) {
        return 0;
    } else {
        return 1 + Maksimum(TinggiPohon(left(T)), TinggiPohon(right(T)));
    }
}


int Maksimum(int Kiri, int Kanan) {
    return (Kiri > Kanan) ? Kiri : Kanan;
}


Tree InsSearch(Tree T, int x) {
    if (T == nil) {
        CreateTree(&T, x, nil, nil);
    } else if (x < info(T)) {
        left(T) = InsSearch(left(T), x);
    } else {
        right(T) = InsSearch(right(T), x);
    }
    return T;
}


void CetakTree(Tree T) {
    if (T != nil) {
        printf("%d\n", info(T));
    }
}


void PreOrder(Tree T) {
    if (T != nil) {
        CetakTree(T);
        PreOrder(left(T));
        PreOrder(right(T));
    }
}


void InOrder(Tree T) {
    if (T != nil) {
        InOrder(left(T));
        CetakTree(T);
        InOrder(right(T));
    }
}


void PostOrder(Tree T) {
    if (T != nil) {
        PostOrder(left(T));
        PostOrder(right(T));
        CetakTree(T);
    }
}
