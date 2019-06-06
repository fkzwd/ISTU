#include <stdio.h>
#include <cstdlib>
#include <ctime>

double* generateArray(double *array, int size, double n, double m);
void checkNM(double* n, double* m);
void checkSize(int *size);
void sortArray(double *array, int size);
void printArray(double *array, int size);

double random(double min, double max)
{
    return (double)(rand())/RAND_MAX*(max - min) + min;
}

int main() {
	srand(time(0));
	
	double* array;
	double n,m;
	int size;
	int cache;
	
	printf("Vvedite razmer massiva: ");
	scanf("%d", &size);
	checkSize(&size);
	
	printf("Vvedite diapazon generiruemih znacheniy \not: ");
	scanf("%lf", &n);
	printf("do: ");
	scanf("%lf", &m);
	checkNM(&n, &m);
	
	array = generateArray(array, size, n, m);
	printArray(array, size);
	sortArray(array, size);
	printArray(array, size);
	
}

double* generateArray(double *array, int size, double n, double m) {
	array = new double[size];

	for (int i = 0; i<size; i++) {
		array[i] = random(n,m);
	}
	return array;
}

void sortArray(double *array, int size) {
	double cache;
	
	for (int j = 0; j<size; j++) {
		for (int i = 0; i<size-j-1; i++) {
			if (array[i] < array[i+1]) {
				cache = array[i];
				array[i] = array[i+1];
				array[i+1] = cache;
			}
		}
	}
}

void printArray(double *array, int size) {
	printf("\nVivod massiva: \n");
	for (int i = 0; i<size; i++) printf("%.2lf ", array[i]);
}

void checkNM(double *n, double *m) {
	if (*n>*m) {
		int cache = *n;
		*n = *m;
		*m = cache;
	}
}

void checkSize(int *size) {
	if (*size<=0) *size = 1;
}
