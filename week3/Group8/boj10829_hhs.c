#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
	int bin[50] = { 0, };
	int binLen = 0;
	long long int decimal;

	scanf("%llu", &decimal);

	//printf("%llu\n", decimal);

	while (decimal > 0) {
		
		if (decimal == 1) {
			bin[binLen] = 1;
			//printf("%d  %llu  %d\n", binLen, decimal, bin[binLen]);
			break;
		}
		
		bin[binLen] = decimal % 2;
		//printf("%d  %llu  %d\n", binLen, decimal, bin[binLen]);
		decimal /= 2;
		binLen++;
	}

	for (int i = binLen; i >= 0; i--) {
		//if (i == binLen && bin[i] == 0)
		//	continue;
		printf("%d", bin[i]);
	}
	


	return 0;
}