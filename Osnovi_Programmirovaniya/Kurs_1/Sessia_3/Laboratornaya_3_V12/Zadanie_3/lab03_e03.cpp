/*
Ќаписать программу, выполн¤ющую расчет произведени¤ двух неквадратных матриц.
ћатрицы должны хранитьс¤ в пам¤ти в виде двумерного динамического массива,
размерности матриц ввод¤тс¤ пользователем с клавиатуры.
ѕредусмотреть генерацию значений матриц как случайных вещественных чисел в диапазоне от -0.5 до 0.5.
*/

#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <ctime>

double** getArray(int x, int y);
void generateArray(double **array, int x, int y);
void printArray(double **array, int x, int y);
void getResult(double** result, double **array1, double **array2, int l, int m, int n);

double random(double max, double min) {
	double result = rand() * (max-min)/(double)RAND_MAX  + min;
	return (int) result;
}

int main() {
	srand(time(0));
	int l,n,m;
	
	printf("VVedite razmeri matric (M1 = L x M; M2 = M x N): \n");
	printf("Vvedite L: ");
	scanf("%d", &l);
	printf("Vvedite M: ");
	scanf("%d", &m);
	printf("Vvedite N: ");
	scanf("%d", &n);
	
	double **array1 = getArray(l,m);
	double **array2 = getArray(m,n);
	double **result = getArray(l,n);
	
	generateArray(array1, l, m);
	generateArray(array2, m, n);
	printf("Array1: ");
	printArray(array1, l, m);
	printf("Array2: ");
	printArray(array2, m, n);
	getResult(result, array1, array2, l, m, n);
	printf("Array3: ");
	printArray(result, l, n);
	
}

double** getArray(int y, int x) {
	double **array;
	array = new double*[y];
	for (int i = 0; i<y; i++) {
		array[i] = new double[x];
	}
	return array;
}

void getResult(double** result, double **array1, double **array2, int l, int m, int n) {
	double cache = 0.0;
	for (int i = 0; i<l; i++) {
		for (int j = 0; j<n; j++) {
			for (int r = 0; r<m; r++) {
				cache += array1[i][r] * array2[r][j];
			}
			result[i][j] = cache;
			cache = 0;
		}
	}
}

void generateArray(double **array, int y, int x) {
	for (int i = 0; i<y; i++){
		for (int j = 0; j<x; j++) {
			array[i][j] = random(3, 1);
		}
	}
}

void printArray(double **array, int y, int x) {
	printf("\nVivod massiva: \n");
	for (int i = 0; i<y; i++) {
		for (int j = 0; j<x; j++) {
			printf("%.2lf\t", array[i][j]);
		}
		printf("\n");
	}
	printf("\n**********************\n");
}

