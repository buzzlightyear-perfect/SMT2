/*
Program : list.c
Author : 2550081109 - Bhaskoro Prayoga Utomo
Kelas : E
*/

#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

typedef struct tElmtList *address;
typedef int infotype;

typedef struct tElmtList {
    infotype info;
    address next;
} ElmtList;

typedef struct {
    address First;
} List;

void CreateList(List *L);
address Alokasi(infotype X);
void DeAlokasi(address P);
boolean ListEmpty(List L);
void InsFirst(List *L, infotype X);
void InsLast(List *L, infotype X);
void InsAfter(List *L, infotype X, infotype Y);
void DelFirst(List *L, infotype *X);
void DelLast(List *L, infotype *X);
void DelAfter(List *L, infotype *X, infotype Y);
int NbElmt(List L);
address Search(List L, infotype X);
void InversList(List *L);
