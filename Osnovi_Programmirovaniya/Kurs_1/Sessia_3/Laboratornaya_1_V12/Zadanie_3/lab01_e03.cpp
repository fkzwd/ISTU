#include <stdio.h>

int main() {
	int m = 0;
	int cache;
	int k = 0;
	int numberInEight[1000];
	int i = 0;
	
	printf("Vvedite chislo: ");
	scanf("%d", &m);
	cache = m;
	if (m<0) m *= -1;
	
	while (m>0) {
		numberInEight[i] = m % 8;
		m = m/8;
		i++;
	}
	
	numberInEight[i] = 0;
	for (int j = i-1; j>=0; j--) if ((numberInEight[j]%2)==0) numberInEight[i]++;
	
	printf("Kol-vo chetnih chisel v 8-richnoy zapisi chisla %d = %d\n", cache, numberInEight[i]);
	printf("Ishodnoe chislo v 8-richnoy zapisi: ");
	
	if (cache<0) printf("-");
	for (int j = i-1; j>=0; j--) printf("%d",numberInEight[j]);
}
