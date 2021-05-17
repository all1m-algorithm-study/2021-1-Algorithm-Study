#include <stdio.h>
#pragma warning(disable:4996)
#include <queue>
using namespace std;

int main(void) {
	int N, K;
	//N = 사람 수, K = K번째마다 사람 제거
	int period = 1;
	queue<int> josephus;

	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		josephus.push(i + 1);
	}

	if (N == 1) {//사람이 한명이면 그냥 출력
		printf("<%d>", josephus.front());
		josephus.pop();
	}
	else {
		printf("<");
		while (!josephus.empty()) {
			if (josephus.size() == 1) {//원에서 사람이 하나 남으면 마지막 하나 남은 원소 출력하고 pop한 후 탈출
				printf("%d", josephus.front());
				josephus.pop();
				continue;
			}

			if (period == K) {//k번째 사람이면 제거
				printf("%d, ", josephus.front());
				josephus.pop();
				period = 1;
			}
			else {//k번째 사람이 아니면 pop하지 않고 뒤로 재배치
				josephus.push(josephus.front());
				josephus.pop();
				period++;
			}
		}
		printf(">");
	}


	

	return 0;
}