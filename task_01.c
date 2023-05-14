#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {

	int  n = 0xCAFE;
	if ((0xCAFE & 0x000F) == 15 || (0xCAFE & 0x000F) == 14 || (0xCAFE & 0x000F) == 13 || (0xCAFE & 0x000F) == 11 || (0xCAFE & 0x000F) == 7) {
		printf("haha ");
	}







	return 0;
}