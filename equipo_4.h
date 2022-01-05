#ifndef _EQUIPO_4
#define _EQUIPO_4

#define cap_max 4

struct agenda {
    char nombre[25];
    int edad, flag;
    int dni;
};

int menu();
void add_per(struct agenda * per);
void del_per(struct agenda * per);
void lista_ordenada (struct agenda * per);
void imprimir_lista (struct agenda * per);

#include "equipo_4.c"
#endif