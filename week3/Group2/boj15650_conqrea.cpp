#include <cstdio>
using namespace std;

bool visit[9];
int arr[9];
int n, m;

void arrPrint(int d, int last) {
	if (d >= m) {
		for (int i = 0; i < m; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = last + 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[d] = i;
			arrPrint(d + 1, i);
			visit[i] = false;
			arr[d] = 0;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	arrPrint(0, 0);
}