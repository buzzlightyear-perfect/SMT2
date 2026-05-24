/* 
Tugas Praktikum Struktur Data
POINT.H
Nama: Bhaskoro Prayoga Utomo
NIM: 2550081109
Kelas: E
*/

#ifndef POINT_H
#define POINT_H
#include <stdio.h>
#include <math.h>
#include "boolean.h"

typedef struct {
    float x;
    float y;
} Point;

/* Prototype */
void MakePoint(Point *P, float x, float y);
void BacaPoint(Point *P);
void TulisPoint(Point P);
boolean IsOrigin(Point P);
float Jarak(Point P1, Point P2);
void Geser(Point *P, float dx, float dy);

#endif
