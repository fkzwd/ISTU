#include <stdio.h>
#include <cstdlib>

void execute(int *array, int size);
void printArray(int *array, int size);

int main() {
	int size = 0;
	printf("Vvedite razmer massiva: ");
	scanf("%d", &size);
	if (size<3) size = 3;
	int array[size];
	
	for (int i = 0; i<size; i++) {
		//ruchnoi vvoid
		//if (i==0) printf("vvedite elementi massiva: \n");
		//printf("array[%d]=",i);
		//scanf("%d", array[i]);
		
		array[i] = rand() % 100;
	}
	
	printArray(array, size);
	
	execute(array, size);
	
	printArray(array, size);
}

void execute(int *array, int size) {
	size = size-1;
	int *max[2];
	int cache;
	
	for (int j = 0; j<2; j++) {
		max[j] = array+j;
		for (int i = j; i<=size; i++) {
			if (*(array+i) > *max[j]) max[j] = array+i;
		}
		cache = *(array+size*j);
		*(array+size*j) = *max[j];
		*max[j] = cache;
	}
}

void printArray(int *array, int size) {
	printf("\n MASSIV: \n");
	for (int i = 0; i<size; i++) {
		printf("a[%d] = %d\n", i, array[i]);
	}
	printf("\n______________________________\n");
}
