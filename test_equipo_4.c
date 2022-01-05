#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<windows.h>
#include "equipo_4.h"

int main() {
    int cap_actual=0;
    struct agenda per[cap_max];
    for(;;) {
        switch(menu()) {
            case 1:
                 if (cap_actual<cap_max) {
                     add_per(per);
                     cap_actual++;
                     system("cls");
                 }
                 else {
                     printf("Espacio Lleno, borre un contacto.");
                 }

                puts("\n------------Lista de Contactos sin ordenar-------------");
                 for(int i=0; i<cap_max; i++) {
                        if(per[i].flag==1) {
                            printf("-----> Nombre:%25s - Edad:%3d - D.N.I.:%8d\n",per[i].nombre, per[i].edad, per[i].dni);
                        }
                    }
                 break;

            case 2:
                puts("\n------------Lista de Contactos sin ordenar-------------");
                for(int i=0; i<cap_max; i++) {
                    if(per[i].flag==1) {
                        printf("-----> Nombre:%25s - Edad:%3d - D.N.I.:%8d\n",per[i].nombre, per[i].edad, per[i].dni);
                    } 
                }
                if (cap_actual>0) {
                     del_per(per);
                     cap_actual--;
                 }
                 else {
                     printf("\nNo hay contactos Agendados.");
                 }
                 break;

            case 3:
                system("cls");
                if (cap_actual==0) {
                    printf("\nNo hay contactos agendados\n");
                }
                else {
                        lista_ordenada(per);
                        puts("\n\t+------------------Lista de Contactos Ordenada------------------+");

                        for(int i=0; i<cap_max; i++)
                            {
                            if(per[i].flag==1)
                                {
                                printf("\t| Nombre:%25s | Edad:%3d | D.N.I.:%8d |\n",per[i].nombre, per[i].edad, per[i].dni);
                                }
                            }
                        puts("\t+---------------------------------------------------------------+\n");
                    }
                break;

            case 4:
                system("cls");
                imprimir_lista (per);
                 break;

            case 5:
                exit(0);
        }
    }
    return 0; 
}