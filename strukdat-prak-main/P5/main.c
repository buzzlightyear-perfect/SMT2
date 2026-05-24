/* 
Program   : main.c
Author    : 2550081109 - Bhaskoro Prayoga U
Kelas     : E
Deskripsi : Program utama untuk menguji operasi stack (array)
Tanggal   : 26/4/2026
*/

#include <stdio.h>
#include "stack.h"

int main() {
    Stack S;
    infotype x;
    int N, i;
    int jumlahPop = 0;

    CreateStack(&S);

    printf("Masukkan N: ");
    scanf("%d", &N);

   
    if (N <= 0) {
        printf("Input tidak valid.\n");
        return 0;
    }

  
    for (i = 1; i <= N; i++) {
        if (i % 2 != 0) {
            Push(&S, i);
        }
    }
   
    printf("\nHasil Pop:\n");
    while (!IsStackEmpty(S)) {
        Pop(&S, &x);
        printf("%d\n", x);
        jumlahPop++;
    }

    
    printf("Stack kosong.\n");
    printf("Jumlah elemen yang di-pop: %d\n", jumlahPop);

    return 0;
}

