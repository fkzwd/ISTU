#include <stdio.h>
#include <math.h>

int* result(int* a, int* b) {
	int x;
	int y;
	for (int i = 1; i<4; i++) {
		if (a[0] == a[i]) x = i;
		if (b[0] == b[i]) y = i;
	}
	int res = abs(b[x] - b[0]);
	res *= abs(a[y] - a[0]);
	int* res_ptr = &res;
	return res_ptr;
}

int main() {
	int array_X[] = {0,0,10,10};
	int array_Y[] = {3,8,3,8};
	int* perimetr = result(array_X, array_Y);
	printf("perimetr = %d", *perimetr);
}
