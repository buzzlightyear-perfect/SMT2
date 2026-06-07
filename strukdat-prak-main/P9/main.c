#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

int main() {
    Tree T = nil;
    int n, x, i;

    printf("=== PROGRAM BINARY TREE ===\n");
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);

    for ( i = 0; i < n; i++) {
        printf("Masukkan nilai ke-%d: ", i + 1);
        scanf("%d", &x);
        T = InsSearch(T, x);
    }

    printf("\n=== Traversal PreOrder ===\n");
    PreOrder(T);

    printf("\n=== Traversal InOrder ===\n");
    InOrder(T);

    printf("\n=== Traversal PostOrder ===\n");
    PostOrder(T);

    printf("\n=== Tinggi Pohon ===\n");
    printf("Tinggi: %d\n", TinggiPohon(T));

    printf("\n=== Root, Left, Right ===\n");
    printf("Root: %d\n", getRoot(T));
    if (getLeft(T) != nil) {
        printf("Left child: %d\n", getRoot(getLeft(T)));
    }
    if (getRight(T) != nil) {
        printf("Right child: %d\n", getRoot(getRight(T)));
    }

    printf("\nTekan ENTER untuk keluar...");
    getchar(); 
    getchar(); 

    return 0;
}
