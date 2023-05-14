#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int gcd(int a, int b) {

	if (a < b) {
		swao(a, b);
	}
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}