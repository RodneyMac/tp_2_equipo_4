#include "equipo_4.h"

int menu() {
    int opc;
    for(;;) {
        system("COLOR 3");
        puts("\t+----------------+");
        printf("\t|Menu de Opciones|\n");
        puts("\t+----------------+");
        printf("\n1 - Agregar Contacto");
        printf("\n2 - Borrar Contacto");
        printf("\n3 - Imprimir lista ordenada por nombre");
        printf("\n4 - Imprimir grafico de edades");
        printf("\n5 - Salir    ");
        printf("\nDigite una opcion y presione Enter: ");
        scanf("%d", &opc); ;
        fflush(stdin);
        if(opc==1||opc==2||opc==3||opc==4||opc==5) {
            return opc;
            break;
        } else {
            printf("- Opcion Incorrecta  -\n");
        }
    }
}

void add_per (struct agenda * per) {
    system("COLOR 2");
    for(int i=0; i<cap_max; i++) {
        if(per[i].flag!=1) {
            do {
            fflush(stdin);
            printf("\nNombre: ");
            gets(per[i].nombre);
            fflush(stdin);
            printf("D.N.I: ");
            scanf("%d", &per[i].dni);
            printf("Edad: ");
            scanf("%d", &per[i].edad);
            printf("Presione 1 para guardar y 2 para repetir carga: ");
            scanf("%d", &per[i].flag);
            } while(per[i].flag!=1);
            break;
        }
    }
}

void del_per (struct agenda * per) {
    system("COLOR 9");
    char nombre[25];
    int i=0;

    for(i=0; ;i++) {
        if (i==0) {
            fflush(stdin);
            printf("Ingrese el Nombre: ");
            scanf("%s", &nombre);
        }
        if((per[i].flag==1)&&((strcmp(per[i].nombre,nombre))==0)) {
            printf("- Nombre:%*s - Edad:%d - D.N.I.:%d -",15, per[i].nombre,per[i].edad, per[i].dni);
            fflush(stdin);
            printf("\nPresione 'Y' para Eliminar, 'N' para nueva busqueda: ");
            scanf("%c", &nombre[1]);
            if (nombre[1]=='Y' || nombre[1]=='y') {
                per[i].flag=0;
                system("cls");
                printf("\nContacto Borrado \n", per[i].flag);
                break;
            }
            else {
                i=0;
            }
        }
        if(i<cap_max) {
            printf("Contacto no existe\n");
            i=-1;
        }
    }
}

void lista_ordenada (struct agenda * per) {
    char auxnombre[25];
    long int auxdni;
    short int auxedad;
    int i, p;

    for(int i=0; i<cap_max-1; i++) {
        for(int p=i+1; p<cap_max-i; p++) {
            if((per[i].flag==1 && per[p].flag==1) && ((strcmp(per[i].nombre, per[p].nombre))>0)) {
                strcpy(auxnombre, per[i].nombre);
                strcpy(per[i].nombre, per[p].nombre);
                strcpy(per[p].nombre, auxnombre);

                auxdni= per[i].dni;
                per[i].dni= per[p].dni;
                per[p].dni= auxdni;

                auxedad= per[i].edad;
                per[i].edad= per[p].edad;
                per[p].edad= auxedad;
            }
        }
    }
}

void imprimir_lista (struct agenda * per) {
   int ran1=0, ran2=0, ran3=0, i,mayor;

    for(i=0; i<cap_max; i++) {
        if(((per[i].edad)>33) && (per[i].flag==1)) {
            ran3++;
        } else {
            if(((per[i].edad)>17) && (per[i].flag==1)) {
                ran2++;
            }
            else if(((per[i].edad)<18) && (per[i].flag==1)) {
                ran1++;
            }
        }
    }

    if(ran1>=ran2 && ran1>=ran3) {
        mayor=ran1;
    } else {
        if(ran2>=ran3 && ran2>=ran1) {
            mayor=ran2;
        } else {
            if(ran3>=ran2 && ran3>=ran1) {
                mayor=ran3;
            }
        }
    }

    for(i=mayor; i>0; i--) {
        if(i==ran1) {
            printf("   *");
            ran1--;
        } else {
            printf("   ");
        }

        if(i==ran2) {
            printf("\t  *");
            ran2--;
        } else {
             printf("\t ");
         }

        if(i==ran3) {
            printf("\t  *\n");
            ran3--;
        }
         else {
             printf("\n");
         }
    }
    puts("+-----+-------+-----+");
    puts("| <19 | 19-35 | >35 |");
    puts("+-----+-------+-----+");
}