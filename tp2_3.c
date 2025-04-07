#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 7

int main()
{
    srand(time(NULL));
    int i, j;
    int mt[N][M];
    int *pMatriz = &mt[0][0];

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            *( pMatriz + (i*M + j) ) = 1 + rand() % 100;
            printf("contenido: %d ,  puntero en  [%d][%d]", *( pMatriz + ( i*M + j)), i, j);
            printf("\n");
        }
    }
    return 0;
}