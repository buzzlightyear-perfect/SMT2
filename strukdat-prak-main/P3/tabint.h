#ifndef _TABINT_H
#define _TABINT_H

#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#define nMax 10
#define IdxUndef -999
#define ElType int

#endif

typedef struct {
    ElType T1[nMax];
    int nEff;
}TabInt;

void CreateTabInt (TabInt *T);
int GetJumElmt(TabInt T);
int GetFirstIdx (TabInt T);
int GetLastIdx (TabInt T);
int GetElmt (TabInt T, int idx);
void SetEl(TabInt *T,int i, int v );
boolean IsEmpty(TabInt T);
boolean IsFull(TabInt T);
void BacaElmt (TabInt *T);
void CetakTabInt(TabInt T);
void AddElmt(TabInt *T, int X);
TabInt KaliTab (TabInt T1, TabInt T2);
TabInt KaliKons (TabInt T, int c);
boolean IsEQTab(TabInt T1, TabInt T2);
void CopyTab(TabInt Tin, TabInt *Tout);
TabInt InverseTab(TabInt T);
boolean isElemenAda(TabInt T, ElType X);
int cariElemen(TabInt T, ElType X);