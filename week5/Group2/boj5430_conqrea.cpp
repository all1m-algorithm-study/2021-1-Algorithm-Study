#include <cstdio>
#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main()
{
	int K;
	scanf("%d", &K);
	for (int i = 1; i <= K; i++) {
		int n;
		bool isFront = true, isError = false;;
		string s;
		char c;
		int t;
		deque<int> d;
		cin >> s;
		scanf("%d", &n);
		cin >> c;
		for (int j = 1; j < n; j++) {
			scanf("%d,", &t);
			d.push_back(t);
		}
		if (n >= 1) {
			scanf("%d", &t);
			d.push_back(t);
		}
		cin >> c;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'R') {
				isFront = !isFront;
			}
			else {
				if (d.size() == 0) {
					isError = true;
					break;
				}
				if (isFront)
					d.pop_front();
				else
					d.pop_back();
			}
		}
		if (isError)
		{
			printf("error\n");
			continue;
		}
		printf("[");
		if (isFront) {
			while (!d.empty()) {
				if (d.size() == 1)
					printf("%d", d.front());
				else
					printf("%d,", d.front());
				d.pop_front();
			}
		}
		else {
			while (!d.empty()) {
				if (d.size() == 1)
					printf("%d", d.back());
				else
					printf("%d,", d.back());
				d.pop_back();
			}
		}
		printf("]\n");
	}
}