#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int main()
{
	int n;
	double x[36], y[36], maxS = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			for (int k = j + 1; k <= n; k++) {
				double S = abs(((x[i] * y[j] + x[j] * y[k] + x[k] * y[i]) - (x[j] * y[i] + x[k] * y[j] + x[i] * y[k])) / 2);
				if (S > maxS)
					maxS = S;
			}
		}
	}
	printf("%.9lf", maxS);
}