#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CANTIDAD 5
#define TAM_TIPO 10
#define CANTIDAD_TIPO 6

struct Compu {
    int velocidad; //entre 1 y 3 GHz-velocidad de procesamiento
    int anio; // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
};

typedef struct Compu PC;

PC GenerarPc(char tipos[][TAM_TIPO]);
void ListarPCs(PC computadoras[], int cantidad);
void MostrarMasVieja(PC computadoras[], int cantidad);
void MostrarMasVeloz(PC computadoras[], int cantidad);

int main (){

    srand(time(NULL));

    PC computadoras[CANTIDAD];

    char tipos[CANTIDAD_TIPO][TAM_TIPO] = {"Intel", "AMD", "Celeron", "Athlon", "Core","Pentium"};

    for (int i = 0; i < CANTIDAD; i++)
    {
        computadoras[i]= GenerarPc(tipos);
    }

    ListarPCs(computadoras, CANTIDAD);
    MostrarMasVieja(computadoras, CANTIDAD);
    MostrarMasVeloz(computadoras, CANTIDAD);
    
    return 0;
}

PC GenerarPc(char tipos[][TAM_TIPO]){
    PC compuNueva;

    compuNueva.velocidad = 1+ rand()% (3-1 +1);
    compuNueva.anio = 2015 + rand()%(2024-2015+1);
    compuNueva.cantidad_nucleos = 1+ rand()%(8);

    int posicionAleatoria = rand()%(6);
    compuNueva.tipo_cpu = tipos[posicionAleatoria]; //tipos[posicionAleatoria] es una cadena , es decir un char*

    return compuNueva;
}


void ListarPCs(PC computadoras[], int cantidad){

    printf("----- ARREGLO DE COMPUTADORAS ----- \n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("-----> PC %d :  \n", i);
        printf("  - Velocidad: %d \n -Anio de Fabricacion: %d \n -Tipo CPU: %s \n -Nucleos: %d \n", computadoras[i].velocidad, computadoras[i].anio, computadoras[i].tipo_cpu, computadoras[i].cantidad_nucleos);
        printf("----- \n");
    }
    
}

void MostrarMasVieja(PC computadoras[], int cantidad){

    int posicion = 0;
    int anioMenor = computadoras[0].anio;
    for (int i = 0; i < cantidad; i++)
    {
        if(computadoras[i].anio < anioMenor){
            anioMenor = computadoras[i].anio;
            posicion = i;
        }else if(computadoras[i].anio == anioMenor){
            //desarrollar logica para ir almacenando varias x ej en un arreglo, sino solo se mostrara la primera que se haya encontrado de entre multiples del mismo anio
        }
    }

    printf("----- PC MAS VIEJA  ----- \n");
    printf("-----> PC %d : \n ", posicion);
    printf("  - Velocidad: %d \n -Anio de Fabricacion: %d \n -Tipo CPU: %s \n -Nucleos: %d  \n", computadoras[posicion].velocidad, computadoras[posicion].anio, computadoras[posicion].tipo_cpu, computadoras[posicion].cantidad_nucleos);
    printf("----- \n");

}
void MostrarMasVeloz(PC computadoras[], int cantidad){
    int posicion = 0;
    int velocidadMayor = computadoras[0].velocidad;

    for (int i = 0; i < cantidad; i++)
    {
        if(computadoras[i].velocidad > velocidadMayor){
            velocidadMayor = computadoras[i].velocidad;
            posicion = i;
        }else if(computadoras[i].velocidad == velocidadMayor){
            //desarrollar logica para ir almacenando varias x ej en un arreglo, sino solo se mostrara la primera que se haya encontrado de entre multiples de la misma velocidad
        }
    }

    printf("----- PC MAS RAPIDA  ----- \n");
    printf("-----> PC %d : \n ", posicion);
    printf("  - Velocidad: %d \n -Anio de Fabricacion: %d \n -Tipo CPU: %s \n -Nucleos: %d \n", computadoras[posicion].velocidad, computadoras[posicion].anio, computadoras[posicion].tipo_cpu, computadoras[posicion].cantidad_nucleos);
    printf("----- \n");

}