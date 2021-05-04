#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
	int tCase = 0;

	scanf("%d", &tCase);

	for (int i = 0; i < tCase; i++) {
		int coin = 0;
		int q = 0, d = 0, n = 0, p = 0;

		scanf("%d", &coin);

		q = coin / 25;
		coin -= (q * 25);
		d = coin / 10;
		coin -= (d * 10);
		n = coin / 5;
		coin -= (n * 5);
		p = coin;

		printf("%d %d %d %d\n", q, d, n, p);

	}

	return 0;
}