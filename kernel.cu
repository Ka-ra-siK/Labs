#define _CRT_SECURE_NO_WARNINGS
#include "device_launch_parameters.h"
#include <cuda_runtime.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <time.h>
#include <locale.h>

#define N 1000
cudaError_t err = cudaSuccess;
float A[N * (N + 1)];

void check_err(){
	if (err != cudaSuccess){
		fprintf(stderr, "Failed ", cudaGetErrorString(err));
		exit(EXIT_FAILURE);
	}
}


void getMatrix() {
	/*for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			a[i][j] = (float)(rand() % 10);*/
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++)
			A[i + j * N] = rand() % 10;
		A[i + N * N] = 0;
	}
}

/*__global__ void gaussMethod(float** a) {
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

__global__ void getDeterminant(float** a) {
	float det = 1.0;
	for (int i = 0; i < N; i++)
		det *= a[i][i];
	//printf("Определитель матрицы = %.3lf\n", det);
}*/

__global__ void gauss_stage1(float* a, int n, float x)
{
	int i = blockDim.x * blockIdx.x + threadIdx.x;

	if (i <= N - n + 1){
		a[n + N * (i + n)] /= x;
	}
}

__global__ void gauss_stage2(float* a, int n, int i, float x){
	int j = blockDim.x * blockIdx.x + threadIdx.x;
	if (j <= N - n - 1){
		a[i + N * (j + n + 1)] -= a[n + N * (j + n + 1)] * x;
	}
}

__global__ void gauss_stage3(float* a, int n){
	int i = blockDim.x * blockIdx.x + threadIdx.x;
	if (i < n){
		a[i + N * N] -= a[n + N * N] * a[i + n * N];
	}
}


void findDeterminand() {
	cudaError_t err = cudaSuccess;

	int threadsPerBlock = 128,
		blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock,
		size = sizeof(float) * N * (N + 1);

	getMatrix();
	float* _A = NULL;
	err = cudaMalloc((void**)&_A, size); check_err();
	err = cudaMemcpy(_A, A, size, cudaMemcpyHostToDevice); check_err();

	for (int i = 0; i < N; i++){
		gauss_stage1 << <blocksPerGrid, threadsPerBlock >> > (_A, i, A[i + i * N]);
		for (int j = i + 1; j < N; j++)
			gauss_stage2 << <blocksPerGrid, threadsPerBlock >> > (_A, i, j, A[j + i * N]);
	}

	for (int i = N - 1; i > 0; i--)
		gauss_stage3 << <blocksPerGrid, threadsPerBlock >> > (_A, i);

	//for (int i = 0; i < N; i++) {
	//	free(A[i]);
	//	A[i] = nullptr;
	//}
	//free(A);
	//A = nullptr;
}

int main(void){
	setlocale(0, "");
	srand(time(NULL));
	int size = N;
	FILE* text;
	int before = clock();
	findDeterminand();
	int time = (clock() - before) * 1000;
	printf("Время: %d мс\n\n", time);

	text = fopen("text.txt", "a");
	fprintf(text, "Время: %d мс     Размер матрицы: %d\n", time, size);
	fclose(text);

	system("pause");
	return  0;
}
