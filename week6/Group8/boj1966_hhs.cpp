#include <stdio.h>
#pragma warning(disable:4996)
#include <queue>
#include <utility>//pair 쓰기 위함
using namespace std;

int main(void) {
	int tCase;
	int N, M;
	int tmp;
	int num=1;
	//idx = M번째 문서가 num 번째 출력되는지 알고 싶음, num = 최종적으로 몇 번째 출력되는지
	queue<pair<int,int>> printQ;//idx, priority
	priority_queue<int> maxQ;

	scanf("%d", &tCase);

	for (int i = 0; i < tCase; i++) {
		num = 1;
		scanf("%d %d", &N, &M);
		
		while (!maxQ.empty()) {
			maxQ.pop();
		}
		while (!printQ.empty()) {
			printQ.pop();
		}

		for (int j = 0; j < N; j++) {//큐에 push
			scanf("%d", &tmp);
			printQ.push(make_pair(j, tmp));
			maxQ.push(tmp);
		}

		
		if (N == 1) {//문서의 개수 1개면 무조건 1번째로 출력
			printQ.pop();
			printf("1\n");
		}
		else{

			while (1) {
				if (printQ.front().second == maxQ.top()) {
					//printQ에서 dequeue되는 원소 우선순위와 가장 우선순위 높은 값이 같다면
					if (printQ.front().first == M) {//M번째 문서이면 출력하고 반복문 탈출
						printf("%d\n", num);//num번째 출력
						break;
					}
					else {
						//printf("\npop!\n");
						//printf("printQ %d %d\n", printQ.front().first, printQ.front().second);
						//printf("maxQ %d\n", maxQ.top());
						maxQ.pop();
						printQ.pop();
						num++;//num번째로 front 출력되고 앞으로는 num+1번째 출력 시작
					}
				}
				else {//printQ에서 dequeue되는 원소가 가장 우선순위 높은 값보다 작다면 인쇄하지 않고 뒤로 재배치
					printQ.push(make_pair(printQ.front().first, printQ.front().second));
					printQ.pop();
				}
				//printf("loop complete\n");
			}
				
		}
	}

	return 0;
}