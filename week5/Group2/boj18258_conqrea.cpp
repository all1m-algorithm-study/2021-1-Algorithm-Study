#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;

int main()
{
	int n;
	char checkMethod[6][6] = { "push","pop","size","empty","front","back" };
	queue<int> q;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		char str[7];
		scanf("%s", &str);
		if (!strcmp(str, checkMethod[0])) {
			scanf("%d", &num);
			q.push(num);
		}
		else if (!strcmp(str, checkMethod[1])) {
			if (!q.empty()) {
				printf("%d\n", q.front());
				q.pop();
			}
			else
				printf("-1\n");
		}
		else if (!strcmp(str, checkMethod[2])) {
			printf("%d\n", q.size());
		}
		else if (!strcmp(str, checkMethod[3])) {
			printf("%d\n", q.empty() == true ? 1 : 0);
		}
		else if (!strcmp(str, checkMethod[4])) {
			if (!q.empty())
				printf("%d\n", q.front());
			else
				printf("-1\n");
		}
		else if (!strcmp(str, checkMethod[5])) {
			if (!q.empty())
				printf("%d\n", q.back());
			else
				printf("-1\n");
		}
	}

}