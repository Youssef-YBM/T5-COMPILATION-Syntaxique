#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include <string.h>
#include <stdio.h>

typedef struct pile
{
	char* symbole;
	struct pile* svt;
}Pile;

int empty(Pile*);
void empiler(Pile**, char[8]);
Pile* allocate(char[8]);
void depiler(Pile**);
int print(Pile**);