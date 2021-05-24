#include <cstdio>
using namespace std;

int n, arr[14], LOTTON[7];

void LOTTO(int d, int lastIndex) {
	if (d > 6) {
		for (int i = 1; i <= 6; i++)
			printf("%d ", LOTTON[i]);
		printf("\n");
		return;
	}
	for (int i = lastIndex + 1; n - i + 1 >= 7 - d; i++) {
		LOTTON[d] = arr[i];
		LOTTO(d + 1, i);
		LOTTON[d] = 0;
	}
}

int main()
{
	while (true) {
		scanf("%d", &n);
		if (!n)
			break;
		for (int i = 1; i <= n; i++)
			scanf("%d",&arr[i]);
		LOTTO(1, 0);
		printf("\n");
	}
}