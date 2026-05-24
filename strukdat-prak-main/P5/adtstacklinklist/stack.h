/* 
Program   : stack.h
Author    : 2550081109 - Bhaskoro Prayoga U
Kelas     : E
Deskripsi : Header file prototype stack (linked list)
*/

#ifndef _STACK2_H
#define _STACK2_H
#include "boolean.h"
#include <stdio.h>
#define nil NULL

typedef int infotype;
typedef struct tElmStack *address;

typedef struct tElmStack {
    infotype Info;
    address next;
} ElmStack;

typedef struct {
    address BUTTOM;
    address TOP;
} Stack;


void CreateStack(Stack *S);
address Alokasi(infotype x);
boolean IsStackEmpty(Stack S);
boolean CariElemenStack(Stack S, infotype x);
void DeAlokasi(address P);
void Push(Stack *S, infotype X);
void Pop(Stack *S, infotype *X);
void CetakStack(Stack S);

#endif

