/* 
Tugas Praktikum Struktur Data
MPOINT.C
Nama: Bhaskoro Prayoga Utomo
NIM: 2550081109
Kelas: E
*/

#include "point.h"

int main(){

    Point P1, P2;
    float jarak;

    printf("Input Point 1\n");
    BacaPoint(&P1);

    printf("Input Point 2\n");
    BacaPoint(&P2);

    printf("Point 1 = ");
    TulisPoint(P1);

    printf("Point 2 = ");
    TulisPoint(P2);

    if(IsOrigin(P1)){
        printf("Point 1 berada di titik origin\n");
    }

    jarak = Jarak(P1,P2);
    printf("Jarak kedua point = %.2f\n", jarak);

    Geser(&P1,2,3);
    printf("Point 1 setelah digeser: ");
    TulisPoint(P1);

    return 0;
}
