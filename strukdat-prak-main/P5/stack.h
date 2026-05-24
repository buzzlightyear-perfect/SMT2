/* 
Program   : stack.h
Author    : 2550081109 - Bhaskoro Prayoga U
Kelas     : E-25
Deskripsi : Header file prototype stack
Tanggal   : 20-4-2026
*/

#ifndef _STACK_H
#define _STACK_H

#include "boolean.h"
#include <stdio.h>
#include <conio.h>

#define Nil   0
#define MaxEl 10

#define Top(S)      (S).TOP
#define InfoTop(S)  (S).T[(S).TOP]

typedef int infotype; 
typedef int address; 

typedef struct {
    infotype T[MaxEl + 1]; 
    address TOP; 
} Stack;


void CreateStack(Stack *S);
boolean IsStackEmpty(Stack S);
boolean IsStackFull(Stack S);
void Push(Stack *S, infotype X);
void Pop(Stack *S, infotype *X);
void PrintStackInfo(Stack S);
boolean isInfoKetemu(Stack S, infotype x);
address CariElemenStack(Stack S, infotype x);

#endif

