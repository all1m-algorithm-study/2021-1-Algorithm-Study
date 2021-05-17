#include <cstdio>
#include <string.h>
#include <deque>
using namespace std;

int main()
{
	int n;
	char checkMethod[8][12] = { "push_front","push_back","pop_front","pop_back","size","empty","front","back" };
	deque<int> d;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		char str[12];
		scanf("%s", &str);
		if (!strcmp(str, checkMethod[0])) {
			scanf("%d", &num);
			d.push_front(num);
		}
		else if (!strcmp(str, checkMethod[1])) {
			scanf("%d", &num);
			d.push_back(num);
		}
		else if (!strcmp(str, checkMethod[2])) {
			if (!d.empty()) {
				printf("%d\n", d.front());
				d.pop_front();
			}
			else
				printf("-1\n");
		}
		else if (!strcmp(str, checkMethod[3])) {
			if (!d.empty()) {
				printf("%d\n", d.back());
				d.pop_back();
			}
			else
				printf("-1\n");
		}
		else if (!strcmp(str, checkMethod[4])) {
			printf("%d\n", d.size());
		}
		else if (!strcmp(str, checkMethod[5])) {
			printf("%d\n", d.empty() == true ? 1 : 0);
		}
		else if (!strcmp(str, checkMethod[6])) {
			if (!d.empty())
				printf("%d\n", d.front());
			else
				printf("-1\n");
		}
		else if (!strcmp(str, checkMethod[7])) {
			if (!d.empty())
				printf("%d\n", d.back());
			else
				printf("-1\n");
		}
	}

}