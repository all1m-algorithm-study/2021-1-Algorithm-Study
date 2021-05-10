#include <cstdio>
#include <algorithm>
using namespace std;

int num[1000001];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num+n);
	for (int i = 0; i < n; i++) {
		printf("%d\n", num[i]);
	}
}