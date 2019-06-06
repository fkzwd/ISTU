#include <stdio.h>

int main() {
	//zadanie soprotivleniya resistorov
	int r[] = {1, 2, 3, 4, 5};
	double result = 0;
	
	for (int i = 0; i<5; i++) {
		result = result + 1.0 / (double) r[i];
	}
	
	result = 1.0 / result;
	
	printf("Obshee soprotivlenie = %lf", result);
}
