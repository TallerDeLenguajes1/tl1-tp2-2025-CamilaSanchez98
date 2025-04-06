#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main(){

    srand(time(NULL));

    int i;
    double vt[N];
    double *pVector = vt;

    for (i = 0; i < N; i++)
    {
        //CARGA 
        *(pVector + i) = 1 + rand() % 100; //numero entre 1 y 100 
        
        //MUESTRO
        printf("contenido: %f , puntero en %d\n", *(pVector +i), i);
    }
    return 0;
}