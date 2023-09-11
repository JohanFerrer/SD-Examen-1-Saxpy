/*Sistemas Distribuidos 
Examen 1 combinacion 3 
Integrantes: 
De La Cruz Munguia Arely
Ferrer Trejo Johan Ariel 
Pérez González Diego 
*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

void get_walltime(double *wcTime) {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    *wcTime = (tp.tv_sec + tp.tv_usec / 1000000.0);
}

int main(int argc, char *argv[]) {
    int i, j, k, n = 100;
    int **matrizA, **matrizB, **matrizC;
    double S1, E1;
    double S2, E2;

    // Inicializando matrices
    matrizA = (int **)malloc(n * sizeof(int *));
    matrizB = (int **)malloc(n * sizeof(int *));
    matrizC = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrizA[i] = (int *)malloc(n * sizeof(int));
        matrizB[i] = (int *)malloc(n * sizeof(int));
        matrizC[i] = (int *)malloc(n * sizeof(int));
    }
    get_walltime(&S1);
    // Llenando matrices
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            matrizA[i][j] = rand() % 6;
            matrizB[i][j] = rand() % 6;
        }
    }
    get_walltime(&E1);

    get_walltime(&S2);
    //combinación 3 
    for (j = 0; j < n; ++j) {
        for (i = 0; i < n; ++i) {
            matrizC[j][i] = 0; // Inicializa la matriz C en 0
            for (k = 0; k < n; ++k) {
                matrizC[j][i] += matrizA[j][k] * matrizB[k][i];
            }
        }
    }
    get_walltime(&E2);
    printf("Tiempo de llenado de matrices: %f s\n", (E1 - S1));
    printf("Tiempo metodo jik: %f s\n", (E2 - S2));

    // Liberar memoria
    for (i = 0; i < n; i++) {
        free(matrizA[i]);
        free(matrizB[i]);
        free(matrizC[i]);
    }
    free(matrizA);
    free(matrizB);
    free(matrizC);

    return 0;
}