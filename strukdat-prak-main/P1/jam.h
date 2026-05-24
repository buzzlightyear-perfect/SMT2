/*
PRAKTIKUM STRUKTUR DATA 
Nama: Bhaskoro Prayoga Utomo
NIM: 2550081109
Kelas: E
*/

#ifndef JAM_H
#define JAM_H
#include "boolean.h"
#define true 1
#define false 0
#define boolean unsigned char

typedef struct {
	int Hour;
	int Minute;
	int Second;
} JAM;


void CreateJam (JAM *J, int HH, int MM, int SS);
int GetHour(JAM J);
int GetMinute(JAM J);
int GetSecond(JAM J);
void SetHour(JAM *J, int newHour);
void SetMinute(JAM *J, int newMinute);
void SetSecond(JAM *J, int newSecond);
void ReadJam (JAM *J);
void PrintJam (JAM J);
boolean IsJValid (int H, int M, int S);
boolean JEQ(JAM J1, JAM J2);
boolean JLT(JAM J1, JAM J2);
boolean JGT(JAM J1, JAM J2);
void Reset (JAM *J);
JAM NextDetik (JAM J);
JAM NextNDetik (JAM J, int N);
long int Durasi ( JAM Jaw , JAM JAkh);
long int JamToDetik (JAM J);
#endif


	
