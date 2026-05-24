/* 
Tugas Praktikum Struktur Data
POINT.C
Nama: Bhaskoro Prayoga Utomo
NIM: 2550081109
Kelas: E
*/

#include "point.h"

void MakePoint(Point *P, float x, float y){
    P->x = x;
    P->y = y;
}

void BacaPoint(Point *P){
    printf("Masukkan X: ");
    scanf("%f",&P->x);
    printf("Masukkan Y: ");
    scanf("%f",&P->y);
}

void TulisPoint(Point P){
    printf("(%.2f , %.2f)\n", P.x, P.y);
}

boolean IsOrigin(Point P){
    if(P.x == 0 && P.y == 0){
        return true;
    } else {
        return false;
    }
}

float Jarak(Point P1, Point P2){
    return sqrt(pow(P1.x - P2.x,2) + pow(P1.y - P2.y,2));
}

void Geser(Point *P, float dx, float dy){
    P->x = P->x + dx;
    P->y = P->y + dy;
}
