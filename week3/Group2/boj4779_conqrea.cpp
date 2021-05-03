#include <cstdio>
#include <math.h>
using namespace std;

bool CT[531442];

void CTA(int s, int e) {
	if (s == e)
		return;
	int k = (e - s + 1) / 3;
	for (int i = s + k; i < s + k * 2; i++)
		CT[i] = true;
	CTA(s, s + k - 1);
	CTA(s + k * 2, e);
}

int main()
{
	int T;
	while (scanf("%d",&T) != EOF) {
		int n = pow(3, T);
		for (int i = 1; i <= n; i++)
			CT[i] = false;
		CTA(1, n);
		for (int i = 1; i <= n; i++) {
			if (CT[i])
				printf(" ");
			else
				printf("-");
		}
		printf("\n");
	}
}