#include <stdio.h>

int main() {
	double year = 0;
	bool isTrue = true;
	
	printf("Vvedite god: ");
	do{
		scanf("%lf", &year);
		if ((year - (int) year )!= 0) printf("Net takogo goda.\nVvedite polozhitel'noe celoe chislo: ");
		else if (year<0) printf("Net takogo goda.\nVvedite polozhitel'noe chislo: ");
		else isTrue = false;
	}
	while (isTrue);

	if ((int)year % 4 == 0) {
		printf("%d - visokosniy god", (int) year);
	}
	else {
		printf("%d - ne visokosniy god", (int) year);
	}
}
