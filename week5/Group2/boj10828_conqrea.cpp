#include <cstdio>
#include <string.h>
#include <stack>
using namespace std;

int main()
{
	int n;
	char checkMethod[5][6] = { "push","pop","size","empty","top" };
	stack<int> s;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		char str[7];
		scanf("%s", &str);
		if (!strcmp(str, checkMethod[0])) {
			scanf("%d", &num);
			s.push(num);
		}
		else if (!strcmp(str, checkMethod[1])) {
			if (!s.empty()) {
				printf("%d\n", s.top());
				s.pop();
			}
			else
				printf("-1\n");
		}
		else if (!strcmp(str, checkMethod[2])) {
			printf("%d\n", s.size());
		}
		else if (!strcmp(str, checkMethod[3])) {
			printf("%d\n", s.empty() == true ? 1 : 0);
		}
		else if (!strcmp(str, checkMethod[4])) {
			if (!s.empty())
				printf("%d\n", s.top());
			else
				printf("-1\n");
		}
	}

}