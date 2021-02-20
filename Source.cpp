#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <time.h>
#include <locale.h>

#define N 1000

void outMatrix(float** a) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            printf("%10.3f ", a[i][j]);
        printf("\n");
    }
}

void gaussMethod(float** a) {
    float* temp = (float*)malloc(sizeof(float) * N);
    float buf = 0.0;
    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++) {
            if (a[i][i] == 0 && i != N - 1) {
                for (int m = 0; m < N; m++) {
                    temp[m] = a[i][m];
                    a[i][m] = a[i + 1][m];
                    a[i + 1][m] = temp[m];
                }
                for (int m = 0; m < N; m++) {
                    if (a[i + 1][m] != 0)
                        a[i + 1][m] = -a[i + 1][m];
                }
                continue;
            }
            buf = -a[j][i] / a[i][i];
            for (int k = 0; k <= N; k++)
                a[j][k] = a[i][k] * buf + a[j][k];
        }
    free(temp);
    temp = nullptr;
}

void getMatrix(float** a) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            a[i][j] = (float)(rand() % 10);
}

void getDeterminant(float** a) {
    float det = 1.0;
    for (int i = 0; i < N; i++)
        det *= a[i][i];
    //printf("Определитель матрицы = %.3lf\n", det);
}

void findDeterminand() {
    float** a;
    a = (float**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        a[i] = (float*)malloc((N + 1) * sizeof(int));
    getMatrix(a);
    //printf("Матрица: \n");
    //outMatrix(a);
    gaussMethod(a);
   // printf("Ступенчатый вид матрицы: \n");
    //outMatrix(a);
    getDeterminant(a);
    for (int i = 0; i < N; i++) {
        free(a[i]);
        a[i] = nullptr;
    }
    free(a);
    a = nullptr;
}

int main() {
    setlocale(0, "");
    srand(time(NULL));
    int size = N;
    FILE* text;
    int before = clock();
    findDeterminand();
    int time = (clock() - before) * 1000;
    printf("Время: %d мс\n\n", time);

    text = fopen("text.txt", "a");
    fprintf(text, "Время: %d ìñ     Размер матрицы: %d\n", time, size);
    fclose(text);

    system("pause");
    return  0;
}
