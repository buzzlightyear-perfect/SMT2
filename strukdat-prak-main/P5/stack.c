/* Program : stack.h
Author : 2550081109 - Bhaskoro Prayoga U
Kelas : E-25
Deskripsi: Header file dari prototype stack
Tanggal : 20-4-2026
*/

#ifndef _STACK_H
#define _STACK_H

#include "boolean.h"
#include <stdio.h>

#define Nil 0
#define MaxEl 10

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

typedef int infotype; 
typedef int address; 

typedef struct {
    infotype T[MaxEl+1];  
    address TOP;          
} Stack;


void CreateStack(Stack *S) {
    (*S).TOP = Nil; 
}
boolean IsStackEmpty(Stack S){
    return (Top(S) == Nil); 
}
boolean IsStackFull(Stack S){
    return (Top(S) == MaxEl); 
}
void Push(Stack *S, infotype X){
    if (!IsStackFull(*S)) {
        (*S).TOP++; 
        (*S).T[Top(*S)] = X; 
    }
}
void Pop(Stack *S, infotype *X){
    if (!IsStackEmpty(*S)) {
        *X = InfoTop(*S); 
        (*S).TOP--; 
    }
}
void PrintStackInfo(Stack S){
	int i;
    if (IsStackEmpty(S)) {
        printf("Stack kosong.\n");
    } else {
        printf("Isi Stack: ");
        for ( i = Top(S); i > Nil; i--) {
            printf("%d ", S.T[i]);
        }
        printf("\n");
    }
}
boolean isInfoKetemu(Stack S, infotype x){
	int i;
    if (IsStackEmpty(S)) {
        return false;
    } else {
        for ( i = Top(S); i > Nil; i--) {
            if (S.T[i] == x) {
                return true;
            }
        }
        return false;
    }
}
address CariElemenStack(Stack S, infotype x){
	int i;
    if (IsStackEmpty(S)) {
        return Nil;
    } else {
        for ( i = Top(S); i > Nil; i--) {
            if (S.T[i] == x) {
                return i;
            }
        }
        return Nil;
    }
}

#endif
