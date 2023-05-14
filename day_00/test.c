#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SQUARED(x) ((x)*(x))
#define MESSAGE "Happy new year!"   


int main(void)
{
	double ans = 18.0 / SQUARED(2 + 1);
	float a = 3.14;
	//printf("%f",ans);
	puts(MESSAGE);
	return 0;
}