#include <stdio.h>
#include <math.h>

void printResult(double volume, double rBig, double rSmall);

double getVolume(double rBig, double rSmall) {
	double result;
	result = 4.0/3.0 * pow(rBig,3) * M_PI;
	result -= 4.0/3.0 * pow(rSmall,3) * M_PI;
	return result;
}

int main() {
	double rBig = 3;
	double rSmall = 0.2;
	double volume = getVolume(rBig, rSmall);
	printResult(volume, rBig, rSmall);
}

void printResult(double volume, double rBig, double rSmall) {
	printf("Ob'em poloi sferi radiusami R = %.4lf & r = %.4lf = %.2lf", rBig, rSmall, volume);
}
