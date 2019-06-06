#include <math.h>
#include <stdio.h>

double getNext(int i);

int main() {
	int k = 1;
	int i = 1;
	double sum = 0;
	
	printf("Vvedite kolichestvo chlenov posledovatelnosti: ");
	scanf("%d", &k);
	
	if (k<1) k = 1;
	
	while (i<=k) {
		sum+= getNext(i);
		i++;
	}
	
	printf("summa %d chlenov = %lf", k, sum);
}

double getNext(int i) {
	double result;
	double top = sinh(i);
	double bot = 1;
	
	for (int j = 1; j<=i+3; j++) {
		bot *= j;
	}
	
	result = top/bot;
	return result;
}
