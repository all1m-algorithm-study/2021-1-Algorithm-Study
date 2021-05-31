#include <stdio.h>
#include <stack>
#include <cstring> // strcmp

using namespace std;

/*
    [Silver 4]
    스택
    
*/
int main()
{
	int i, j, n, res;
	char buf[100] = {0};
	scanf("%d", &n);
	stack<int> s;
	for (i = 0; i < n; i++)
	{
		scanf("%s", buf);
		if (strcmp(buf, "top") == 0)
			printf("%d\n", s.empty() ? -1 : s.top());
		else if (strcmp(buf, "size") == 0)
			printf("%d\n", s.size());
		else if (strcmp(buf, "empty") == 0)
			printf("%d\n", s.empty());
		else if (strcmp(buf, "pop") == 0)
		{
			printf("%d\n", s.empty() ? -1 : s.top());
			if (!s.empty())
				s.pop();
		}
		else 
		{
			scanf("%d", &res);
			s.push(res);
		}
	}
	return 0;
}